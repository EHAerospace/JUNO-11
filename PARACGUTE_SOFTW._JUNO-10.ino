/*
   Connections
   ===========
   Connect SCL to analog 5
   Connect SDA to analog 4
   Connect VDD to 3.3V DC
   Connect GROUND to common ground
*/

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

//variables:
float val = 0;
float alti = 0;
float alti1 = 0;
float alti2 = 0;
float altiA = 0;
float valA = 0;
float valB = 0;
int x = 0;
//OUTPUTS:
const int indic = 10;
const int rele = 2;
Servo servo;

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);


void displaySensorDetails(void)
{
  sensor_t sensor;
  bmp.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" hPa");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" hPa");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" hPa");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void Set_Zero_Alti() {
  sensors_event_t event;
  bmp.getEvent(&event);

  if (event.pressure) {
    delay(100);
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    altiA = bmp.pressureToAltitude(seaLevelPressure,
                                   event.pressure);
    Serial.println(altiA);
    delay(500);
  }
}

void setup(void)
{
  Serial.begin(9600);

  Serial.println("Juno-K10 rocket parachute system");
  Serial.println("   ");
  Serial.print("");
  delay(2000);

  Serial.println("Pressure Sensor Test"); Serial.println("");

  pinMode(indic, OUTPUT);
  pinMode(rele, OUTPUT);

  if (!bmp.begin())
  {

    Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }


  displaySensorDetails();
  Set_Zero_Alti();

}

void loop(void)
{
  sensors_event_t event;
  bmp.getEvent(&event);

  ///////////////////////////////////////////////////////////////////
  if (event.pressure)
  {

    float temperature;
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;

    Serial.println("alti1 =   ");
    Serial.println(alti1);
    Serial.println("");

    delay(1000); //delay!!!


    alti2 = bmp.pressureToAltitude(seaLevelPressure,
                                   event.pressure) - altiA; //lectura 2
    Serial.println("alti2 =   ");
    Serial.println(alti2);
    digitalWrite(indic , HIGH);
    delay(50);
    digitalWrite(indic, LOW);

    valA = alti2 - alti1;
    Serial.println("");
    // Serial.println(valA);
    Serial.println("");


    if (valA <= -1.7) {

      digitalWrite(rele, HIGH);
      delay(5000);
    } else {
      digitalWrite(rele, LOW);

      alti1 = alti2;

    }
    //////////////////////////////////////////////////

  }
}



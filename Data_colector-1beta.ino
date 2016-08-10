#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

/*                        ____________       ____     ____                _____
                          |           |      |   |    |   |              /     \
                          |   ________|      |   |    |   |             /       \
                          |   |              |   |    |   |            /   /  \  \
                          |   |_____         |   |____|   |           /   /____\  \
                          |    _____|        |            |          /             \
                          |   |              |    ____    |         /   __________  \
                          |   |_______       |   |    |   |        /   /          \  \
                          |           | __   |   |    |   | __    /   /            \  \  __
                          |___________||__|  |___|    |___||__|  /___/              \__\|__|

                            Euskal Herria Aerospace       //     www.ehaerospace.space

                               Amateur space program, "The poor boys space program"

                               *Code developed by:
                                                   Mikel Malagón  (mikelma7@gmail.com)

                               *contact: info@ehaerospace.space          2016

*/

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
SoftwareSerial serial(0, 1); // RX, TX

//Variables
float alti;
float zero;

float maxtemp;
float maxalti;


void setup(void)
{
  Serial.begin(9600);
  serial.begin(4800); //setun bauds
  
  Serial.print("This code was developed by Mikel Malagon");
  Serial.println("The code was used in the rocket JUNO-11C");
  delay(500);
  Serial.print("by EHAerospace.");
  delay(700);

  /* Initialise the sensor */
  if (!bmp.begin())
  {
    /* There was a problem detecting the BMP085 ... check your connections */
    Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }
  getzero();
}
void getzero() {
  /* Get a new sensor event */
  sensors_event_t event;
  bmp.getEvent(&event);

  if (event.pressure)
  {


    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;

    //read the altitude
    zero = bmp.pressureToAltitude(seaLevelPressure,
                                  event.pressure);
  }

}
void loop(void)
{
  /* Get a new sensor event */
  sensors_event_t event;
  bmp.getEvent(&event);

  if (event.pressure)
  {

    //read temperature
    float temp;
    bmp.getTemperature(&temp);

    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;

    //read the altitude
    alti = bmp.pressureToAltitude(seaLevelPressure,
                                  event.pressure) - zero;


    delay(500);

   
    if (alti > maxalti) {
      maxalti = alti;
    } else {

    }
    if (temp > maxtemp) {
      maxtemp = temp;
    } else {
    }

    Serial.print("current alti:  ");
    Serial.print(alti);
    Serial.print("max. alti:   ");
    Serial.println(maxalti);
    
    Serial.print("current temperature:  ");
    Serial.print(temp);
    Serial.print("max. temperature:   ");
    Serial.println(maxtemp);
   
    
    serial.write("max. alti:   ");
    serial.write(maxalti);
    
    serial.write("max. temperature:   ");
    serial.write(maxtemp);
    
  }
  else
  {
    Serial.println("Sensor error");
  }

}

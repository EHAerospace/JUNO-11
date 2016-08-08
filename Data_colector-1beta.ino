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

//Variables
float alti;
float alti2;
float temp2;

byte maxtemp;
byte maxalti;

void setup(void)
{
  Serial.begin(9600);
  Wire.begin();

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
                                  event.pressure);

    //this reding is higher than last?
    alti2 = max(alti2, alti);
    temp2 = min(temp2, temp);

    //decode the data to keep in byte class variable
    maxalti = alti2 * 0.3;
    maxtemp = alti2 * 0.3;

    Wire.beginTransmission(8); // transmit data to device #8
    Wire.write(maxalti);
    Wire.write("$$");
    Wire.write(maxtemp);
    Wire.write("$$");
    Wire.endTransmission(); //stop transmitting
  }
  else
  {
    Serial.println("Sensor error");
  }
  delay(500);
}

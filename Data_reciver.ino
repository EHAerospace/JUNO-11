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

#include <SoftwareSerial.h>
SoftwareSerial serial(0, 1); // RX, TX

void setup() {
 Serial.begin(9600);
 serial.begin(4800);
}

void loop() {
  if (serial.available()) {
    Serial.write(serial.read());
  }

}

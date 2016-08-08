#include <Wire.h>

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

void setup() {
  Wire.begin(8);
  Wire.onReceive(ReciverEvent);

  Serial.begin9600();
}

void loop() {
  delay(100);

}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) { 
    char c = Wire.read(); 
    Serial.print(c);         
  }
  int x = Wire.read();   

  Serial.print(x);
  Serial.print("        ");

  int data = x * 0.3;
  Serial.println(data);
    
 }




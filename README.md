# JUNO-11
JUNO-11 is the first rocket of EHAerospace. This is the code of the Arduino based payload of the rocket. The function of this is to deploy the JUNO´s parachute in the right moment to land safely.

#The code
The arduino(1) (PARACGUTE_SOFTW._JUNO-10.ino) reads data from the barometric pressure sensor BMP180 and when it detects a high negative altiude change activates the pin 2to deploy the parachute.
The oder arduino(2)(Data_colector-1beta.ino) aboard JUNO collects data about altitude and temperature and transmittes it via serial. When the rocket lands oder arduino is conected via serial with the data collector arduino(3)(Data_reciver__beta_.ino) and the data is visualized in a laptop.
View schematics (System.png) for more info.
              
#Rocket design
JUNO was designed in Open Rocket. Open Rocket is a free open source program to design rockets. You need this program to open JUNO-11.ork, you can download Open Rocket from: http://openrocket.sourceforge.net/.

The engine nozzle mold and the rocket nosecone are in .STL file to 3d print.

If you have any question: info@ehaerospace.space
Our web page: www.ehaerospace.space



Data_colector-1beta.ino	Arduino based data colector inside JUNO-11C	7 minutes ago
JUNO-11.ork	Add files via upload	3 days ago
PARACGUTE_SOFTW._JUNO-10.ino

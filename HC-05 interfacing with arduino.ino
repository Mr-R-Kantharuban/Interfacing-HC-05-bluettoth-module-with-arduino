#include <SoftwareSerial.h>
#define TX 2
#define RX 3

int Bt_data=0;
int Arduino_data=0;
SoftwareSerial BTscreen(RX, TX);// RX, TX for Bluetooth
void setup() {
BTscreen.begin(9600); // For Bluetooth
Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor
}
void loop()
{
  if(Serial.available()>0)
  {
    String Arduino_data=Serial.readString();
    int a=(Arduino_data.toInt());
    BTscreen.println(a);
  }
  
  if(BTscreen.available()>0)
  {
    String Bt_data=BTscreen.readString();
    int b=(Bt_data.toInt());
    Serial.println(2*(b));
  }
  
}

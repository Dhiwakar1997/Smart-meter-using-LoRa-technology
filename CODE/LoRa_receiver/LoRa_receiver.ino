#include <SPI.h> // arduino spi library
 #include <Wire.h>
#include <LoRa.h> // arduino libraries for ra02 lora
 char Received_Character,Energy[20],Address[20],Watt[20],Received_Full_String[30];
void setup() {

  Serial.begin(9600);
  Wire.begin(8);                // join i2c bus with address #8

  while (!Serial);

  Serial.println("Lora Receiver");

  if (!LoRa.begin(433E6)) {

    Serial.println("Starting LoRa failed ");

   while (1);

  }

 LoRa.setSpreadingFactor(10);

 LoRa.setSignalBandwidth(62.5E3);

 LoRa.crc();

}

void loop() {
 int Energy_Index=0,Watt_Index=0,Address_Index=0,Full_String_Index=0,Flag1=0,Flag2=0;
  int packetSize = LoRa.parsePacket();


  if (packetSize) {

    // read packet

    while (LoRa.available()) {
 Received_Character=(char)LoRa.read();
 Received_Full_String[Full_String_Index++]=Received_Character;
 if(Received_Character=='$')
 {
 Flag1=1;
 continue;
 }
 else if(Received_Character=='=')
 {
  Flag2=1;
  continue;
 }
 //Serial.print(Received_Character);
 if(Flag1==0&&Flag2==0)
Energy[Energy_Index++]=Received_Character;
else if(Flag2==1&&Flag1==1)
Watt[Watt_Index++]=Received_Character;
else
Address[Address_Index++]=Received_Character;

    }

    Wire.beginTransmission(8); // transmit to device #8

   Wire.write(Received_Full_String);
   Wire.write(" ");

  Wire.endTransmission();

 Serial.write(Received_Full_String,30);
 }

}

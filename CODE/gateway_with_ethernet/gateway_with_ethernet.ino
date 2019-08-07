
#define BLYNK_PRINT Serial

#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6ec4b4c46e77464f8e0c2a9908e95993";

#define W5100_CS  10
#define SDCARD_CS 4

       // What digital pin we're connected to

     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301


BlynkTimer timer;
char My_String[20],Power[20],Address[20],Watt_Per_Second[20];
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
 char val[20]="";
 for(int j=0;j<i;j++)
 {
 val[j] =My_String[j];
 }
// Serial.println(i);
Serial.println(val);
  Blynk.virtualWrite(V1, Watt_Per_Second);
   Blynk.virtualWrite(V0, Power);
    Blynk.virtualWrite(V2, Address);
 strcpy(My_String,"");

}

void setup()
{
  // Debug console
  Wire.begin(8);                // join i2c bus with Address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

  Blynk.begin(auth);
  // You can also specify server:
  //Blynk.begin(auth, "blynk-cloud.com", 80);
  //Blynk.begin(auth, IPAddress(192,168,1,100), 8080);



  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
  int Address_Index=0,Power_Index=0,Watt_Index=0,i=0,x,Flag_1=0,Flag_2=0;
  while (1 < Wire.available()) { // loop through all but the last
    char My_String = Wire.read(); // receive byte as a character
     if(My_String=='$')
 {
 Flag_1=1;
 continue;
 }
 else if(My_String=='=')
 {
  Flag_2=1;
  continue;
 }
 //Serial.print(My_String);
 if(Flag_1==0&&Flag_2==0)
Address[Address_Index++]=My_String;
else if(Flag_2==1&&Flag_1==1)
Power[Power_Index++]=My_String;
else
Watt_Per_Second[Watt_Index++]=My_String;
  }
  int x;    // receive byte as an integer
  x = Wire.read();
   Serial.println(Address);
 Serial.println(Watt_Per_Second);
  Serial.println(Power);
  delay(500);
}
void receiveEvent(int howMany) {

}

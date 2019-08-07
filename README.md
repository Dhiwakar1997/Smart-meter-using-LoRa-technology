# Smart-meter-using-LoRa-technology
This is a smart energy meter project which measures the meter readings and visualizes the data live on a mobile application.
The main advantage of this project is that the project doesn't require an internet connection in the houses where the meter is installed.

Data is transferred wirelessly through LoRa wireless technology.

The project is divided into three phases:

1.LoRa based smart meter - It measures energy meter reading and transmits it wirelessly using LoRa.

2. LoRa receiver - It receives the LoRa signals form the meters.

3. Gateway with ethernet/Gateway with WiFi - Received data from LoRa receivers is transferred to a server through these gateways. 
                                             In this project two types of gateways are designed for flexibility,
                                             they are classified asGateway with ethernet & Gateway with WiFi.

Interfaces Used:
1.arduino is connected with LoRa transceivers using the SPI interface.

2. Arduino is connected to another Arduino using I2C interface.

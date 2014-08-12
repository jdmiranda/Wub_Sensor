#include <HTTPClient.h>
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <util.h>
#include <TinkerKit.h>
#include <SPI.h>


int newStatus = 0; 
int oldStatus = 0;
boolean changeStatus = false; 
TKButton button(I0);
TKLed ledGreen(O0); 
TKLed ledYellow(O1);
TKLed ledRed(O2);


// the media access control (ethernet hardware) address for the shield:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

//the IP address for the shield
byte ip[] = {
  10, 0, 0, 177}; 
  
void setup()
{
  Serial.begin(9600);
}

void loop()
{

  //check if the pushbutton is pressed
  if (button.toggle() == HIGH) {
    ledGreen.on();
    newStatus = 0; //bridge down
  }
  else {
    ledGreen.off();
    newStatus = 1;//bridge up
  }
  if (oldStatus != newStatus){
    changeStatus = true;
    oldStatus = newStatus;
    Serial.println("Sending update...");
  }
  else {
    changeStatus = false;
  }

}


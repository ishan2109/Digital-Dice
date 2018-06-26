#include "LedControlMS.h"
#define NBR_MTX 2
#define ctsPin 4 //input PIN for capactitive touch sensor 
LedControl lc=LedControl(12,11,10, NBR_MTX);
int ledPin = 13; // pin for the LED


//////////////////////////////////////////////////////////
  void six(){
    lc.setLed(0,2,2,true);
    lc.setLed(0,2,4,true);
    lc.setLed(0,3,2,true);
    lc.setLed(0,3,4,true);
    lc.setLed(0,4,2,true);
    lc.setLed(0,4,4,true);
    delay(1000);
    lc.setLed(0,2,2,false);
    lc.setLed(0,2,4,false);
    lc.setLed(0,3,2,false);
    lc.setLed(0,3,4,false);
    lc.setLed(0,4,2,false);
    lc.setLed(0,4,4,false);
  }

/////////////////////////////////////////////////////////////
  void five(){
    lc.setLed(0,2,2,true);
    lc.setLed(0,2,4,true);
    lc.setLed(0,3,3,true);
    lc.setLed(0,4,2,true);
    lc.setLed(0,4,4,true);
    delay(1000);
    lc.setLed(0,2,2,false);
    lc.setLed(0,2,4,false);
    lc.setLed(0,3,3,false);
    lc.setLed(0,4,2,false);
    lc.setLed(0,4,4,false);
  }
///////////////////////////////////////////////////////////////

  void four(){
    lc.setLed(0,2,2,true);
    lc.setLed(0,2,4,true);
    lc.setLed(0,4,2,true);
    lc.setLed(0,4,4,true);
    delay(1000);
    lc.setLed(0,2,2,false);
    lc.setLed(0,2,4,false);
    lc.setLed(0,4,2,false);
    lc.setLed(0,4,4,false);
  }

///////////////////////////////////////////////////////////////
  void three(){
    lc.setLed(0,2,2,true);
    lc.setLed(0,3,3,true);
    lc.setLed(0,4,4,true);
    delay(1000);
    lc.setLed(0,2,2,false);
    lc.setLed(0,3,3,false);
    lc.setLed(0,4,4,false);
  
  }

////////////////////////////////////////////////////////////
  void two(){
    lc.setLed(0,3,2,true);
    lc.setLed(0,3,4,true);
    delay(1000);
    lc.setLed(0,3,2,false);
    lc.setLed(0,3,4,false);
  }
  
////////////////////////////////////////////////////////////////

  void one(){
    lc.setLed(0,3,3,true);
    delay(1000);
    lc.setLed(0,3,3,false);
  }
///////////////////////////////////////////////////////////////////









///////////////////////////////////////////////////////////
void setup() {
  Serial.begin (9600);
  pinMode(ledPin, OUTPUT);  
  pinMode(ctsPin, INPUT);
    for (int i=0; i< NBR_MTX; i++)
      {
        lc.shutdown(i,false);
        lc.setIntensity(i,8);
        lc.clearDisplay(i);
      }
  }
/////////////////////////////////////////
  void initial(){
    for(int i=0;i<6;i++)
    {
      lc.setLed(0,0,i,true);
      lc.setLed(0,i,6,true);
      lc.setLed(0,i,0,true);
      lc.setLed(0,6,i,true);
      lc.setLed(0,6,6,true);
     }
  }
///////////////////////////////////////
  void  erase(){
    for(int i=0;i<6;i++){
      lc.setLed(0,0,i,false);
      lc.setLed(0,i,6,false);
      lc.setLed(0,i,0,false);
      lc.setLed(0,6,i,false);
      lc.setLed(0,6,6,false);
      }
  }
////////////////////////////////////////

    
  void loop() {

    int ctsValue = digitalRead(ctsPin);
    
    if(ctsValue == HIGH){
    Serial.println("Touch");
    int random_int = random(1,7);
    Serial.println(random_int);
    delay(2500);


    switch(random_int){
      
      case 1: {
                initial();
                one();
                erase();
                ctsValue == LOW;   
              } 

              
      case 2: {
                initial();
                two();
                erase();
                ctsValue == LOW;   
              } 

              
      case 3: {
                initial();
                three();
                erase();
                ctsValue == LOW;   
              } 
              
              
      case 4: {
                initial();
                four();
                erase();
                ctsValue == LOW;   
              } 
              
              
      case 5: {
                initial();
                five();
                erase();
                ctsValue == LOW;   
              } 

              
      case 6: {
                initial();
                six();
                erase();
                ctsValue == LOW;   
              } 

      default: {
                 ctsValue == LOW;
                 Serial.println(" NO Touch");
               }
    
    }
   
     }
  }

#include <stdio.h>
#include <string.h>

//#define pins
#define SIGNAL_A 15
#define SIGNAL_B 21
#define BUTTON_1 22
#define BUTTON_2 23

//parameters for waveform
#define PARAM_A 1200     //L  micro
#define PARAM_B 900      //I  micro
#define PARAM_C 9       //V
#define PARAM_D 4500     //I  micro
//system_mode = 2        //N  Generate inverted form of complete Sig A waveform (from the largest pulse to the shortest) until switch 2 set back to 0 

int param_c = PARAM_C;
int param_a = PARAM_A;
bool button_1 = false; // creates button variable as boolean, this will help with interupts
bool button_2 = false;
bool debounce_1 = false;
bool debounce_2 = false;

void setup() {
  //set buttons to input
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  
  //set signal pins to output
  pinMode(SIGNAL_A, OUTPUT);
  pinMode(SIGNAL_B, OUTPUT);

  //set buttons to rising edge
  attachInterrupt(BUTTON_1, change_value, RISING);
  attachInterrupt(BUTTON_2, change_value, RISING);
 
}

void change_value(){ // esenntially a flip flip, it's a needed funtion for using attachinterupt
  if(button_1 && debounce_1){
    (button_1 = false);
  }
  else{
    (button_1 = true);
  }
  debounce_1 = false;
  printf("/n button 1 changed");

  if(button_2 && debounce_2){
    (button_2 = false);
  }
  else{
    (button_2 = true);
  }
  debounce_2 = false;
  printf("/n button 2 changed");
}

void loop() {
  int count;
  digitalWrite(SIGNAL_B,HIGH);
  delayMicroseconds(50000);
  digitalWrite(SIGNAL_B,LOW);
  // genertaes signal
  for (int i=0;i<PARAM_C; i++){//creates signal pulse
    if(button_2){
      count = (param_c-1)-i;
    }
    else{
      count = i;
    }
    if(button_1){
     digitalWrite(SIGNAL_A, HIGH);
    }
    delayMicroseconds(param_a + (50*count)); //*1000 for testing with LEDs
    if(button_1){
      digitalWrite(SIGNAL_A, LOW);
    }
  }
  delayMicroseconds(PARAM_D);//*1000 for testing with LEDs
}

#include <stdio.h>
#include <math.h>
#include <string.h>

//#define pins
#define SIGNAL_A 15
#define SIGNAL_B 21
#define BUTTON_1 22
#define BUTTON_2 23

//parameters for waveform
#define PARAM_A 1200     //L  micro
#define PARAM_B 900      //I  micro
#define PARAM_C 13       //V
#define PARAM_D 4500     //I  micro
//system_mode = 2        //N  Generate inverted form of complete Sig A waveform (from the largest pulse to the shortest) until switch 2 set back to 0 


bool button = false; // creates button variable as boolean, this will help with inverting waveform untill button 2 is back to zero
bool button2 = false;

void setup() {
  //set buttons to input
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  
  //set signal pins to output
  pinMode(SIGNAL_A, OUTPUT);
  pinMode(SIGNAL_B, OUTPUT);

  //set buttons to rising edge

  //printf("\n pin set")

}
//void function to invert wave form{
//  if button 1 pressed
//    true
//  else
//    false
//    printf("/n button 1 pressed")
//
//  if button 2 pressed
//    true
//  else
//    false
//    printf("/n button 2 pressed")
//}

void function_name(){
//function 
//for int (i=0;i<param_c; i++)
//  count=+;
//
//if param_a, high
//  width+(50*count);
//
}

void loop() {
  // put your main code here, to run repeatedly:

}

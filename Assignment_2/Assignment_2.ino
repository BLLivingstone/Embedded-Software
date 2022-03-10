#include <Ticker.h>
#include <stdio.h>
#include <string.h>

// define pins
#define SIGNAL_A
#define button_1
#define LED


void setup() {

  pinMode(LED)

}

void loop() {
  // put your main code here, to run repeatedly:

}
void task_1{ // rate 5Hz
  // Output a (digital) watchdog waveform (with same length and period of the 
  //‘Normal’ operation of SigB in Assignment 1). Timings should be within 5%.
}
void task_2{ // rate 1Hz
  //Monitor one digital input (to be connected to a pushbutton/switch or a signal 
  //generator for students using Proteus).
}
void task_3{ //rate 24Hz
  //Measure the frequency of a 3.3v square wave signal. The frequency will be in 
  //the range 500Hz to 1000Hz and the signal will be a standard square wave (50% 
  //duty cycle). Accuracy to 2.5% is acceptable.
}
void task_4{ //rate 24Hz 
  //Read one analogue input. The analogue input must be connected to a maximum 
  //of 3.3V, using a potentiometer.
}
void task_5{ //rate 10Hz
  //Compute filtered analogue value, by averaging the last 4 readings. 
}
void task_6{ //rate 10Hz
  //Execute 1000 times the following instruction:__asm__ __volatile__ ("nop");
  //The statement could be repeated using a single loop, or broken down into 
  //multiple loops (e.g. to be executed in different slots of the cyclic executive). 
  for ( int i
}
void task_7{ //rate 3Hz
  //Perform the following check:
  if (average_analogue_in > half of maximum range for analogue input){
      error_code = 1
    else:
      error_code = 0
  }
} 
void task_8{ //rate 3Hz
  analogWrite(LED,error_code);
}

void task 9{ //rate 0.2Hz
//  Log the following information every five (5) seconds (in comma separated 
//  format, e.g. CSV) to the serial port:
//    State of the digital input (pushbutton / switch);
//    Frequency value (Hz, as an integer);
//    Filtered analogue input.

printf("/n"button_1"," freq_val","analog_in)
}

error_code{

}

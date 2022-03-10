/* PROBLEM
  A “Cyclic Executive” is a way to implement a simple real-time operating system that does not rely
  on the interrupt system for most of its activity. Your task is to design, build and test a simple Cyclic
  Executive for your microcontroller (ESP32 / Arduino UNO simulated using Proteus) using C/C++.

  SPECIFICATION
  A small cyclic executive is required to implement a machine monitor system. 
  The system must execute the following periodic tasks, with specified timings: see each task function*/

#include <Ticker.h>
#include <stdio.h>
#include <string.h>

// define pins
#define WATCH_DOG 19
#define PULSE_IN 18
#define BUTTON_1 12
#define ANALOG_IN 0
#define LED 14

//rate of the tasks
#define RATE_TASK_2 200
#define RATE_TASK_3 1000
#define RATE_TASK_4 42
#define RATE_TASK_5 42
#define RATE_TASK_6 100
#define RATE_TASK_7 333
#define RATE_TASK_8 5000

bool button false;

int error_code;

float average_analog_in;
float analog_in;
float analog[4];
float frequency_in;



void setup() {
  pinMode(LED, OUTPUT)

}

void ticker(){
  tick_num++;

  task_1();
  if((tick%R_T")

}

void task_1{ // rate 5Hz
  // Output a (digital) watchdog waveform (with same length and period of the 
  //‘Normal’ operation of SigB in Assignment 1). Timings should be within 5%.
  digitalWrite(WATCH_DOG, HIGH);
  delayMicroseconds(50);
  digitalWrite(WATCH_DOG,LOW);
}
void task_2{ // rate 1Hz
  //Monitor one digital input (to be connected to a pushbutton/switch or a signal 
  //generator for students using Proteus)
  button = digitalRead(BUTTON_1);
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
  average_analogue_in=0;
}
void task_6{ //rate 10Hz
  //Execute 1000 times the following instruction:__asm__ __volatile__ ("nop");
  //The statement could be repeated using a single loop, or broken down into 
  //multiple loops (e.g. to be executed in different slots of the cyclic executive). 
  for ( int i=0; i<1000; i++{
    _asm_ _volitile()
  }
}
void task_7{ //rate 3Hz
  //Perform the following check:
  if (average_analogue_in > (3.3/2)){
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

printf("/n"button"," freq_val","analog_in)
}

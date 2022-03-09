#define LED



void setup() {
  
  
  task8();

}

void loop() {
  // put your main code here, to run repeatedly:

}
task_1{ // rate 5Hz
  // Output a (digital) watchdog waveform (with same length and period of the 
  //‘Normal’ operation of SigB in Assignment 1). Timings should be within 5%.
}
task_2{ // rate 1Hz
  //Monitor one digital input (to be connected to a pushbutton/switch or a signal 
  //generator for students using Proteus).
}
task_3{ //rate 24Hz
  //Measure the frequency of a 3.3v square wave signal. The frequency will be in 
  //the range 500Hz to 1000Hz and the signal will be a standard square wave (50% 
  //duty cycle). Accuracy to 2.5% is acceptable.
}
task_4{ //rate 24Hz 
  //Read one analogue input. The analogue input must be connected to a maximum 
  //of 3.3V, using a potentiometer.
}
task_5{ //rate 10Hz
  //Compute filtered analogue value, by averaging the last 4 readings. 
}
task_6{ //rate 10Hz
  //Execute 1000 times the following instruction:__asm__ __volatile__ ("nop");
  //The statement could be repeated using a single loop, or broken down into 
  //multiple loops (e.g. to be executed in different slots of the cyclic executive). 
}
task_7{ //rate 3Hz
  //Perform the following check:
  if (average_analogue_in > half of maximum range for analogue input){
      error_code = 1
    else:
      error_code = 0
  }
} 
task_8{ //rate 3Hz
  analogWrite(LED,error_code);
}

task 9{ //rate 0.2Hz
//  Log the following information every five (5) seconds (in comma separated 
//  format, e.g. CSV) to the serial port:
//    State of the digital input (pushbutton / switch);
//    Frequency value (Hz, as an integer);
//    Filtered analogue input.
}

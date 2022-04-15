/* PROBLEM
  A “Cyclic Executive” is a way to implement a simple real-time operating system that does not rely
  on the interrupt system for most of its activity. Your task is to design, build and test a simple Cyclic
  Executive for your microcontroller (ESP32 / Arduino UNO simulated using Proteus) using C/C++.

  SPECIFICATION
  A small cyclic executive is required to implement a machine monitor system. 
  The system must execute the following periodic tasks, with specified timings: see each task function*/
  
// define pins
#define WATCH_DOG 19
#define PULSE_IN 18
#define BUTTON_1 23
#define ANALOG_IN 0
#define LED 14

//rate of the tasks
#define RATE_TASK_1 14
#define RATE_TASK_2 200
#define RATE_TASK_3 1000
#define RATE_TASK_4 42
#define RATE_TASK_5 42
#define RATE_TASK_6 100
#define RATE_TASK_7 333
#define RATE_TASK_8 333
#define RATE_TASK_9 5000

void task_1(void *pvParameters);//prototype of the tasks
void task_2(void *pvParameters);
void task_3(void *pvParameters);
void task_4(void *pvParameters);
void task_5(void *pvParameters);
void task_6(void *pvParameters);
void task_7(void *pvParameters);
void task_8(void *pvParameters);
void task_9(void *pvParameters);

bool button_pressed;

int error_code;

float analog_in;
float analog[4];
float frequency_in;
float wave_form;

static QueueHandle_t a_queue;
static SemaphoreHandle_t data_protc;

struct data_for_tasks{
  bool button = false;
  float frequency_in;
  float average_analogue_in;
};
data_for_tasks data_t;

void setup() {
  Serial.begin(57600);
  //pin definitions
  pinMode(BUTTON_1,INPUT); 
  pinMode(PULSE_IN,INPUT);
  pinMode(ANALOG_IN,INPUT);
  
  pinMode(WATCH_DOG,OUTPUT);
  pinMode(LED, OUTPUT);

  //set analog to 0
  analog[0] =0;
  analog[1] =0;
  analog[2] =0;
  analog[3] =0;

  //set up
  a_queue = xQueueCreate(1, sizeof(float));

  //sets a protection for the data structure
  data_protc = xSemaphoreCreateMutex();

  xTaskCreate(
        task_1,
        "task 1", // name for readability 
        512,      // stack size
        NULL,
        4,        //priority
        NULL);

    xTaskCreate(
        task_2,
        "task 2",
        512,
        NULL,
        3,
        NULL);

    xTaskCreate(
        task_3,
        "task 3",
        1024,
        NULL,
        3,
        NULL);

    xTaskCreate(
        task_4,
        "task 4",
        1024,
        NULL,
        2,
        NULL);

    xTaskCreate(
        task_5,
        "task 5",
        1024,
        NULL,
        1,
        NULL);

    xTaskCreate(
        task_6,
        "task 6",
        512,
        NULL,
        3,
        NULL);

    xTaskCreate(
        task_7,
        "task 7",
        1024,
        NULL,
        4,
        NULL);

    xTaskCreate(
        task_8,
        "task 8",
        512,
        NULL,
        3,
        NULL);

    xTaskCreate(
        task_9,
        "task 9",
        1024,
        NULL,
        4,
        NULL);
}

void task_1(void *pvParameters){ // rate 5Hz
  // Output a (digital) watchdog waveform (with same length and period of the 
  //‘Normal’ operation of SigB in Assignment 1). Timings should be within 5%.
  (void) pvParameters;
  for(;;){
    digitalWrite(WATCH_DOG, HIGH);
    delayMicroseconds(50);
    digitalWrite(WATCH_DOG,LOW);
    vTaskDelay(RATE_TASK_1);
  }
}
void task_2(void *pvParameters){ // rate 1Hz
  //Monitor one digital input (to be connected to a pushbutton/switch or a signal 
  //generator for students using Proteus)
  (void) pvParameters;
  for(;;){
    if(xSemaphoreTake(data_protc, portMAX_DELAY) == pdTRUE){
      data_t.button = digitalRead(BUTTON_1);
      button_pressed = data_t.button;
      xSemaphoreGive(data_protc);
    }
      vTaskDelay(RATE_TASK_2);
  }
}
void task_3(void *pvParameters){ //rate 24Hz
  //Measure the frequency of a 3.3v square wave signal. The frequency will be in 
  //the range 500Hz to 1000Hz and the signal will be a standard square wave (50% 
  //duty cycle). Accuracy to 2.5% is acceptable.
  (void) pvParameters;
  for(;;){
    if(xSemaphoreTake(data_protc, portMAX_DELAY) == pdTRUE){
      wave_form = pulseIn(PULSE_IN, LOW); // returns the length of pulse in micro seconds
      data_t.frequency_in = 1000000.0/(wave_form*2); // conversion for seconds
      xSemaphoreGive(data_protc);
    }
      vTaskDelay(RATE_TASK_3);
  }
}
void task_4(void *pvParameters){ //rate 24Hz 
  //Read one analogue input. The analogue input must be connected to a maximum 
  //of 3.3V, using a potentiometer.
  (void) pvParameters;
  for(;;){
    for (int i=1;i<4;i++){
      analog[i-1] = analog[i];
    }
    analog[2] = analogRead(ANALOG_IN);
    vTaskDelay(RATE_TASK_4);
  }
}
void task_5(void *pvParameters){ //rate 10Hz
  //Compute filtered analogue value, by averaging the last 4 readings. 
  data_t.average_analogue_in=0;
  (void) pvParameters;
  for(;;){
    float c = 0;
    if(xQueueReceive(a_queue, &c, 100)){
        for (int i = 1; i < 4; i++)
        {
            analog[i - 1] = analog[i];
        }

        analog[3] = c * (3.3 / 4095);
    }
        
    if(xSemaphoreTake(data_protc, portMAX_DELAY) == pdTRUE){
      for(int i=1;i<4;i++){
        data_t.average_analogue_in = data_t.average_analogue_in + analog[i];
      }
      
      data_t.average_analogue_in = data_t.average_analogue_in / 4;
      xQueueSend(a_queue, &c, 100);
      xSemaphoreGive(data_protc);
    }
      vTaskDelay(RATE_TASK_5);
  }
}
void task_6(void *pvParameters){ //rate 10Hz
  //Execute 1000 times the following instruction:__asm__ __volatile__ ("nop");
  //The statement could be repeated using a single loop, or broken down into 
  //multiple loops (e.g. to be executed in different slots of the cyclic executive). 
  (void) pvParameters;
  for(;;){
    for ( int i=0; i<1000; i++){
      __asm__ __volatile__("nop");
    }
    vTaskDelay(RATE_TASK_6);
  }
}
void task_7(void *pvParameters){ //rate 3Hz
  //Perform the following check:
  (void) pvParameters;
  for(;;){
    float c = 0;
    if (xQueueReceive(a_queue, &c, 100)){
    
      if(c >(3.3/2)){ //3.3/2 is half maximum range for analogue input
          error_code = 1;
      }
      else{
          error_code = 0;
      }
    }
    vTaskDelay(RATE_TASK_7);
  }
} 
void task_8(void *pvParameters){ //rate 3Hz
  (void) pvParameters;
  for(;;){
    digitalWrite(LED,error_code);
    vTaskDelay(RATE_TASK_8);
  }
}

void task_9(void *pvParameters){ //rate 0.2Hz
//  Log the following information every five (5) seconds (in comma separated 
//  format, e.g. CSV) to the serial port:
//    State of the digital input (pushbutton / switch);
//    Frequency value (Hz, as an integer);
//    Filtered analogue input.
  (void) pvParameters;
    for (;;){
      if(xSemaphoreTake(data_protc, portMAX_DELAY) == pdTRUE){
          if(button_pressed == false) {
              Serial.print(data_t.button);
              Serial.print(", \t");
              Serial.print(data_t.frequency_in);
              Serial.print(", \t");
              Serial.print(data_t.average_analogue_in);
              Serial.print("\n");
          }
          
          xSemaphoreGive(data_protc);
      }

      // delays task for rate
      // before restarting
      vTaskDelay(RATE_TASK_9);
    }
}
void loop(){} // only needed for code to compile

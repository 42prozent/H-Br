#include <PID_v1.h>

#define enable_left_speed_one  11   // value -255 to 255 (is the H-bridge Enable pin) 
  //#define enable_left_speed_two 
  //#define enable_right_speed 10

#define power1  12  //input 1 H-Bridge 
#define power2  13 //input 2 H-Bridge
//rightL
//richtR

      int mainBusA; // speed & diretion Value Left
      int subBusA; // vorzeichenwchsel, debuing pwm

// PID:
double Setpoint, Input, Output;   // Define coneckting Variables
double Kp=2, Ki=5, Kd=1;          //Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

  

void setup() {
// PID
  Input    = subBusA;
  Setpoint = 100;           // adjust parameter (einstellparameter)
  myPID.SetMode(AUTOMATIC); // turn the PID on
  
//pinbelegung
  pinMode (11, OUTPUT); // Motor Speed about the enable pin
  pinMode (12, OUTPUT); // Motor Left
  pinMode (13, OUTPUT); // Moter Reight
    
    Serial.begin(9600);
}



void loop() {
delay (20);


  mainBusA = 220;            // platzhalter serielle Komunikation
  Serial.println (mainBusA);
  mainBusA = map (mainBusA, 0, 100, 0, 50);
   subBusA = abs (mainBusA); // eventuelles negatieves vorzeichen entfernt
  
  
// Trobelschooting Parameter: Cange the motordirecktion here:
if (mainBusA > 0) {
  engineOne (power1,power2); // left vorward 
}
if (mainBusA < 0) {
  engineOne (power2,power1); // left backward
}




//digitalWrite (leftForward,  LOW); digitalWrite (leftBackward, LOW);

}


int engineOne (int wire1 , int wire2 ){   // engine_One_Left_Forward
  Input = subBusA;
  myPID. Compute();
  analogWrite  (enable_left_speed_one, subBusA);
  // spacer vor pid
  digitalWrite (wire1,  HIGH);
  digitalWrite (wire2,   LOW);
  
 Serial.print   (mainBusA, DEC);
 Serial.println ( subBusA, DEC);
  return;
}

/*

int engineOne_LB (){   // engine_One_Left_Backward // first trye
  
analogWrite  (enable_left_speed, SVL);
digitalWrite (leftForward,  LOW);
digitalWrite (leftBackward, HIGH);
Serial.println (SVL, DEC);
return;
}

*/


int serialRead (){
  
}


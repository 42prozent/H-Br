#include <PID_v1.h>

#define enable_left_speed  11   // value -255 to 255 (is the H-bridge Enable pin) 
  //#define enable_left_speed2 
#define enable_right_speed 10

#define power1  12  //input 1 H-Bridge // Trobelschooting Parameter: Cange the motordirecktion here
#define power2  13 //input 2 H-Bridge
//rightL
//richtR

      int mainBusA; // speed & diretion Value Left
      int subBusA; // vorzeichenwchsel, debuing pwm

// PID:
//double Setpoint, Input, Output; // variablen 

      
    
void setup() {

  pinMode (11, OUTPUT); // Motor Speed about the enable pin
  pinMode (12, OUTPUT); // Motor Left
  pinMode (13, OUTPUT); // Moter Reight
    
    Serial.begin(9600);

  


}

void loop() {
delay (20);


  mainBusA = analogRead (0);
  Serial.println (mainBusA);
  mainBusA = map (mainBusA, 0, 100, 0, 50);
  subBusA = abs (mainBusA); // eventuelles negatieves vorzeichen entfernt
  
  

if (mainBusA > 60) {
  engineOne (power1,power2); // left vorward
}
if (mainBusA < 40) {
  engineOne (power2,power1); // left backward
}




//digitalWrite (leftForward,  LOW); digitalWrite (leftBackward, LOW);

}


int engineOne (int wire1 , int wire2 ){   // engine_One_Left_Forward
  
analogWrite  (enable_left_speed, subBusA);
// spacer vor pid
digitalWrite (wire1,  HIGH);
digitalWrite (wire2,  LOW );

Serial.print   (mainBusA, DEC);
Serial.println (subBusA, DEC);
return;
}

/*

int engineOne_LB (){   // engine_One_Left_Backward
  
analogWrite  (enable_left_speed, SVL);
digitalWrite (leftForward,  LOW);
digitalWrite (leftBackward, HIGH);
Serial.println (SVL, DEC);
return;
}

*/


int serialRead (){
  
}


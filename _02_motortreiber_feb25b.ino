
#define leftSpeed  11   // value -255 to 255 (is the H-bridge Enable pin) 
//#define rightSpeed   // value -255 to 255 

#define leftForward   12  //input 1 H-Bridge
#define leftBackward  13 //input 2 H-Bridge
//rightL
//richtR

int SVL = 0; // speed Value Left
int DVL = 0; // direcktion Value left

void setup() {
  pinMode (11, OUTPUT); // Motor Speed about the enable pin
  pinMode (12, OUTPUT); // Motor Left
  pinMode (13, OUTPUT); // Moter Reight
    
    Serial.begin(9600);
}

void loop() {



engineOne_LF ();

digitalWrite (leftForward,  LOW); digitalWrite (leftBackward, LOW);

delay (900);
}


int engineOne_LF (){   // engine_One_Left_Forward
  
analogWrite  (leftSpeed, 80);
digitalWrite (leftForward,  HIGH);
digitalWrite (leftBackward, LOW);
return;


}


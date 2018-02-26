
#define leftSpeed  11   // value -255 to 255 (is the H-bridge Enable pin) 
//#define rightSpeed   // value -255 to 255 

#define leftForward   12  //input 1 H-Bridge
#define leftBackward  13 //input 2 H-Bridge
//rightL
//richtR

    int SVL; // speed Value Left
    int DVL; // direcktion Value left
    
void setup() {

  pinMode (11, OUTPUT); // Motor Speed about the enable pin
  pinMode (12, OUTPUT); // Motor Left
  pinMode (13, OUTPUT); // Moter Reight
    
    Serial.begin(9600);

}

void loop() {
delay (20);

while (Serial.available() > 0){

  SVL = Serial.parseInt() ;
  DVL = Serial.parseInt() ;

  if (Serial.read() == '\n'){
    
    Serial.println (SLV, HEX);
  }

}

 
  
   // inputSpeedL = Serial.read();
   
    
    
  //  if (inputSpeedL > 0){
     //   engineOne_LF ();
        delay (900);
   // }
    
 



digitalWrite (leftForward,  LOW); digitalWrite (leftBackward, LOW);

}


int engineOne_LF (){   // engine_One_Left_Forward
  
analogWrite  (leftSpeed, SVL);
digitalWrite (leftForward,  HIGH);
digitalWrite (leftBackward, LOW);
Serial.println (SVL, DEC);
return;
}





int serialRead (){
  
}


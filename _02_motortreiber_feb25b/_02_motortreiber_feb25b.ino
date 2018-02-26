
#define leftSpeed  11   // value -255 to 255 (is the H-bridge Enable pin) 
//#define leftSpeed2   // value -255 to 255 
#define rightSpeed 10 // 

//#define leftForward   12  //input 1 H-Bridge  // is now pos & neg
//#define leftBackward  13 //input 2 H-Bridge
//rightL
//richtR

      int mainBusA; // speed & diretion Value Left
      int subBusA; // vorzeichenwchsel, debuing pwm
    
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
  mainBusA = map (mainBusA, 0, 1200, 0, 520);
  subBusA = abs (mainBusA); // eventuelles negatieves vorzeichen entfernt
  
  

if (mainBusA > 265) {
  engineOne (12,13); // left vorward
}
if (mainBusA < 255) {
  engineOne (13,12); // left backward
}




//digitalWrite (leftForward,  LOW); digitalWrite (leftBackward, LOW);

}


int engineOne (int wire1 , int wire2 ){   // engine_One_Left_Forward
  
analogWrite  (leftSpeed, subBusA);
// spacer vor pid
digitalWrite (wire1,  HIGH);
digitalWrite (wire2,  LOW );

//Serial.print   (mainBusA, DEC);
Serial.println (subBusA, DEC);
return;
}

/*

int engineOne_LB (){   // engine_One_Left_Backward
  
analogWrite  (leftSpeed, SVL);
digitalWrite (leftForward,  LOW);
digitalWrite (leftBackward, HIGH);
Serial.println (SVL, DEC);
return;
}

*/


int serialRead (){
  
}


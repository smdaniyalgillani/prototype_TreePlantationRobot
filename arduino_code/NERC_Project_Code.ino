// Define the number of sensors
const int numSensors = 6;
// Define sensor pins
const int sensorPins[numSensors] = {A1, A2, A3 ,A4 ,A5 ,A6};
int junctionCount =0;
int sensorValues[numSensors];
int pathway; //path  seclector
int oneone, onetwo, onethree, twoone, twotwo, twothree, threeone, threetwo, threethree,parking1,parking2;
int forwardspeed = 105;
void setup() {
  // put your setup code here, to run once:
  //MotorRight
  pinMode(10,OUTPUT);//A_1
  pinMode(8,OUTPUT); //B_1
  pinMode(5,OUTPUT);//P_1

  //MotorLeft
  pinMode(11,OUTPUT);//A_2
  pinMode(12,OUTPUT);//B_2
  pinMode(7,OUTPUT);//P_2

  motor_initialize();
  delay(100);
  Serial.begin(9600);

  Serial.println("Start");
}

void loop() {
  int sensorValues[numSensors];

  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }
  // Follow the line and count junctions
  followline(sensorValues);

  // Add your desired delay
  delay(10); // Adjust the delay as needed
}
void followline(int sensorValues[]){
   if (sensorValues[0] >= 500 &&  sensorValues[2] < 500) {
    // Turn slightly left
      Turn(1, 0,230, 0, 0,0); //turn left
      delay(50);
      //motor_initialize();
     } 
    else if (sensorValues[0] < 500 && sensorValues[2] >= 500) {
    // Turn slightly right
     Turn(0, 0, 0, 1, 0, 230); //turn right 
     delay(50);
     //motor_initialize();
    }   
    else{
    forward(forwardspeed);
    delay(50);
    //motor_initialize();
  }
  if(sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500) //All on black line
    {
      junctionCount++;
      Serial.println("Junction " + String(junctionCount));
      forward(forwardspeed);
      delay(100);
    }
  if ((junctionCount == 2) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)) {
      turn_delayed(0,1,230,1,0,230);
      Turn(0,1,230,1,0,230);
      delay(110);
      forward(105);
      delay(500);
      motor_initialize();
      delay(300);
      if(analogRead(sensorPins[3])>500 && analogRead(sensorPins[4])<500 && analogRead(sensorPins[5])<500){
        Serial.println("Apple");
        oneone =7; onetwo=8;onethree=12; twoone=15;twotwo=16;twothree=19; threeone=21;threetwo=22; threethree=24;parking1=25 ;parking2=29 ;
        //pathway = 0;
      }
      else if(analogRead(sensorPins[3])<500 && analogRead(sensorPins[4])<500 && analogRead(sensorPins[5])>500){
        Serial.println("Banana");
        //pathway=1;
          oneone =9; onetwo=10;onethree=12; twoone=15;twotwo=16;twothree=19; threeone=23;threetwo=24; threethree=28;parking1=29 ;parking2=33 ;
         
      }
      else if(analogRead(sensorPins[3])>500 && analogRead(sensorPins[4])>500 && analogRead(sensorPins[5])>500){
        Serial.println("grape");
        //pathway = 2;
        oneone =9; onetwo=10;onethree=12; twoone=14;twotwo=15;twothree=17; threeone=19;threetwo=20; threethree=22;parking1=23;parking2=27 ;
      }
      else if(analogRead(sensorPins[3])<500 && analogRead(sensorPins[4])<500 && analogRead(sensorPins[5])<500){
        Serial.println("melon");
        //pathway = 2;
        oneone =8; onetwo=9;onethree=12; twoone=15;twotwo=16;twothree=19; threeone=22;threetwo=23; threethree=26;parking1=27;parking2=31 ;
      }
      else if(analogRead(sensorPins[3])<500 && analogRead(sensorPins[4])>500 && analogRead(sensorPins[5])<500){
        Serial.println("kiwi");
      }
      else {
        oneone =7; onetwo=8;onethree=12; twoone=15;twotwo=16;twothree=19; threeone=21;threetwo=22; threethree=24;parking1=25 ;parking2=29 ;;
        Serial.println("Nothin");
        }
      delay(1500);
      Turn(0,1,125,0,1,125);
      delay(350);
      turn_delayed(1,0,230,0,1,230);
      motor_initialize();
      delay(300);
      //Serial.println("Turn Complete");
      //forward(forwardspeed);
     // delay(300);
    }
    
      if ((junctionCount == 4) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)) {
      // Turn left at the 4th junction
      motor_initialize();
      delay(100);
      forward(forwardspeed);
      delay(100);
      motor_initialize();
      turn_delayed(1, 0, 230, 0, 1, 230); //turn right ---------------------------------------------spped lamo
      Serial.println("Turning");
      } 

       //----------------------------------------------------------------------------------------------------------------1st 
      else if ((junctionCount == oneone) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)) {
      Serial.println("TURN RIGHT");
      // Turn left at the 7th junction
      forward(0);
      delay(50);
      turn_delayed(1, 0, 230, 0, 1, 230);
      //delay(1000);
      Serial.println("Turning");
      //Serial.println("Turn Complete");
      }
    else if((junctionCount == onetwo) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
    motor_initialize();
    delay(2000);
    forward(105);
    delay(100);
    turn_delayed(0, 1, 230, 1, 0, 230);
    motor_initialize();
    delay(100);
    }
    else if((junctionCount == onethree) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
    motor_initialize();
    delay(2000);
    Serial.println("Turn Delayed");
    u_turn(1, 0, 230, 0, 1, 230);  
    Turn(1,0,230,0,1,230); 
    Serial.println("Turn");   
    delay(100);
    }
  //-------------------------------------------------------------------------------------------------------------------------2nd
    else if((junctionCount == twoone) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
      motor_initialize();
      delay(100);
      turn_delayed(0, 1, 230, 1, 0, 230);
    }
    else if((junctionCount == twotwo) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
    motor_initialize();
    delay(2000);
    forward(105);
    delay(50);
    turn_delayed(0, 1, 230, 1, 0, 230); //left
    }
    else if((junctionCount == twothree) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
    motor_initialize();
    delay(2000);
    u_turn(1, 0, 230, 0, 1, 230);
    //Turn(1,0,230,0,1,230);
    //delay(100);
    }
  //--------------------------------------------------------------------------------------------------------------------------3rd
    else if((junctionCount == threeone) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
      motor_initialize();
      delay(100);
      turn_delayed(0, 1, 230, 1, 0, 230);
      forwardspeed=95;
    }
    else if((junctionCount == threetwo) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
    motor_initialize();
    delay(2000);
    forward(150);
    delay(50);
    turn_delayed(0, 1, 230, 1, 0, 230); //left
    Turn(0,1,230,1,0,230);
    delay(100);
    }
    else if((junctionCount == threethree) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
    motor_initialize();
    delay(2000);
    u_turn(1, 0, 230, 0, 1, 230);
    Turn(1,0,230,0,1,230);
    delay(100);
    }
  //-----------------------------------------------------------------------------------------------------------------Onto the parking
    else if((junctionCount == parking1) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
      Serial.println("ParkingTurn");
      forward(150);
      delay(200);
      motor_initialize();
      delay(200);
      turn_delayed(1, 0, 230, 0, 1, 230);
      Turn(1,0,230,0,1,230);
       delay(100);
    }
    else if((junctionCount == parking2) && (sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500)){
    Serial.println("ParkingTurn");
    forward(forwardspeed);
    delay(900);
    motor_initialize();
    delay(300000);
    }
}

void motor_initialize()
{
  // put your main code here, to run repeatedly:
  //motorRight
  digitalWrite(8,LOW);
  digitalWrite(10,LOW);
  //motorLeft
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  analogWrite(5,LOW);
  analogWrite(7,LOW);
}

void Turn(int A_1 , int B_1, int speedR, int A_2 , int B_2, int speedL)
{
  //MotorRight
  digitalWrite(8, A_1); //A_1
  digitalWrite(10, B_1); //B_1
  analogWrite(5, speedR);  //P_1

  //MotorLeft
  digitalWrite(11,A_2);//A_2
  digitalWrite(12,B_2); //B_2
  analogWrite(7,speedL); //P_2
}

void forward(int speed){
  //MotorRight
  digitalWrite(8,HIGH); //A_1
  digitalWrite(10,LOW); //B_1
  analogWrite(5,speed);  //P_1

  //MotorLeft
  digitalWrite(11,HIGH);//A_2
  digitalWrite(12,LOW); //B_2
  analogWrite(7,speed); //P_2
}

void turn_delayed(int Aa_1 , int Bb_1, int speedRr, int Aa_2 , int Bb_2, int speedLl) {
  Turn(Aa_1,Bb_1,speedRr, Aa_2, Bb_2,speedLl);
  // Turn slightly right
  delay(550); //Adjust //changes -------------------------------------------------
  //Serial.println("Delayed turn");
  while(digitalRead(sensorPins[1])==LOW)
  { 
    //Serial.println(analogRead(sensorValues[1]));
    Turn(Aa_1,Bb_1,speedRr, Aa_2, Bb_2,speedLl);
    delay(60);
    motor_initialize();
    delay(60); 
  }
  motor_initialize();
  //Serial.println("Initialize");
}
void u_turn(int Aa_1 , int Bb_1, int speedRr, int Aa_2 , int Bb_2, int speedLl) {
  Turn(Aa_1,Bb_1,speedRr, Aa_2, Bb_2,speedLl);
  // Turn slightly right
  delay(900); //Adjust
  //Serial.println("Delayed turn");
  while(digitalRead(sensorPins[1])==LOW)
  { 
    //Serial.println(analogRead(sensorValues[1]));
    Turn(Aa_1,Bb_1,speedRr, Aa_2, Bb_2,speedLl);
    delay(150);
    motor_initialize();
    delay(40);
  }
  motor_initialize();
  //Serial.println("Initialize");
}

/*void turn_board(int Aa_1 , int Bb_1, int speedRr, int Aa_2 , int Bb_2, int speedLl) {
  Turn(Aa_1,Bb_1,speedRr, Aa_2, Bb_2,speedLl);
  // Turn slightly right
  delay(450); //Adjust
  //Serial.println("Delayed turn");
  while(digitalRead(sensorPins[1])==LOW)
  { 
    //Serial.println(analogRead(sensorValues[1]));
    Turn(Aa_1,Bb_1,speedRr, Aa_2, Bb_2,speedLl);
    delay(60);
    motor_initialize();
    delay(60);
  }
  motor_initialize();
  //Serial.println("Initialize");
}

/*void followline_board(){
  do{

  }while()
}*/



float temp;
float temp1;
float vout;

// sensor
int gasSensor;
int gasSensor1;
int buzzer =7;


////ultrasonic
int trigger_pin=9;
int echo_pin=10;
int time;
int distance;

void setup()
{
pinMode (A0,INPUT);
pinMode (A1,INPUT);
pinMode (A2,INPUT);  
pinMode (buzzer,OUTPUT);  
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  //temp data 
vout=analogRead(A1);
vout=(vout/1023)*5000;
temp=(vout-500)/10;
  
  // gas senosr 1 data
gasSensor=analogRead(A0);
  if (gasSensor>=100){
  digitalWrite(buzzer,HIGH);
  }  
  else
  {
 digitalWrite(buzzer,LOW);
 delay(500);
  } 
  
  //gas sensor 2 data
gasSensor1=analogRead(A2);
  if (gasSensor1>=100){
  digitalWrite(buzzer,HIGH);  
  }  
  else
  {
 digitalWrite(buzzer,LOW);  
 delay(500);
  }  
  //////////// ultrasonic data
  
  digitalWrite (trigger_pin, HIGH);
  delay(1000);
  digitalWrite(trigger_pin,LOW);
  time = pulseIn (echo_pin,HIGH);
  distance = (time * 0.034)/2;
  
  if (distance<=40){
    Serial.println ("Distance=");
      Serial.println (distance);
      digitalWrite(buzzer,HIGH);
  }
  else{
     Serial.println ("Distance=");
      Serial.println (distance);
  digitalWrite(buzzer,LOW);  
    delay(500);
  }
  
    ///serial print data
 Serial.print("DegreeC=");
 Serial.print(" ");
 Serial.print(temp);
 Serial.print("\t");
 Serial.print("gasSensor=");
 Serial.print(" ");
 Serial.print(gasSensor);
 Serial.print("\t"); 
  Serial.print("gasSensor1=");
 Serial.print(" ");
 Serial.print(gasSensor1);
    Serial.println();
    delay(1000);
  
}


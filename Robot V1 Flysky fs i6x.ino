double ch1 = A0;
double ch2 = A1;
double ch3 = A2;
double ch4 = A3;
double ch5 = A4;
double ch6 = A5;

int enA = 2;  
int in1 = 3;  
int in2 = 4;  
int enB = 5;  
int in3 = 6;  
int in4 = 7;  
int enC = 8;     
int inc4 = 9;    
int inc3 = 10;  

int pwm1;
int speed1 = 160;   

int Relay = 11;  
int Relay1 = 12;
int buzzer = 13;

int volume1;
int volume2;
int volume3;
int volume4;
int volume5;
int volume6;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enC, OUTPUT);
  pinMode(inc4, OUTPUT);
  pinMode(inc3, OUTPUT);

  pinMode(Relay, OUTPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
  pinMode(ch3, INPUT);
  pinMode(ch4, INPUT);
  pinMode(ch5, INPUT);
  pinMode(ch6, INPUT);

  Serial.begin(9600);
  Serial.println("Connecting OK");
  digitalWrite(Relay, HIGH);
  digitalWrite(Relay1, HIGH);
}

void loop() {
  volume1 = pulseIn(ch1, HIGH);
  volume2 = pulseIn(ch2, HIGH);
  volume3 = pulseIn(ch3, HIGH);
  volume4 = pulseIn(ch4, HIGH);
  volume5 = pulseIn(ch5, HIGH);
  volume6 = pulseIn(ch6, HIGH);
  Serial.println("OK");
  if (volume5 > 1900) {
    if ((volume2 > 1700)) {      
      Serial.println("foward");  
      foWard1();
    } else if ((volume1 > 1700)) {  
      Serial.println("turnLeft");   
      turnLeft();
    } else if ((volume1 < 1300)) {  
      Serial.println("turnRight");  
      turnRight();
    } else if ((volume2 < 1300)) {  
      Serial.println("back");       
      backWard();
    } else {
      stopBot();
    }
    if (volume3 > 1) {
      pwm1 = map(volume3, 100, 2000, 0, 255);
      Serial.println("motorplus");
      motorrun();
    }
    if (volume6 > 1200) {
      Serial.println("Relay1run");
      Relay1run();
    } else if (volume6 < 1200) {  
      Serial.println("Relay1stop");
      Relay1stop();
    }
    if (volume6 > 1900) {
      Serial.println("Relay2run");
      Relay1stop();
      Relay2run();
    } else if (volume6 < 1900) {
      Serial.println("Relay2stop");
      Relay2stop();
    }

  } else {
    stopBot();
    Relay1stop();
    Relay2stop();
    sound();
  }
}

void foWard1() 
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speed1);  
  analogWrite(enB, speed1);  
}
//***********************************************************************************

void backWard() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speed1);  
  analogWrite(enB, speed1);   
}
//***********************************************************************************

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speed1);  
  analogWrite(enB, speed1); 
}
//***********************************************************************************

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, speed1);  
  analogWrite(enB, speed1);   
}
//***********************************************************************************

void stopBot() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
//***********************************************************************************
void motorrun()  
{
  digitalWrite(inc4, LOW);
  digitalWrite(inc3, HIGH);
  analogWrite(enC, pwm1);  
}
//***********************************************************************************
void Relay1run() {
  digitalWrite(Relay, LOW);
}
//***********************************************************************************
void Relay1stop() {
  digitalWrite(Relay, HIGH);
}
//***********************************************************************************

void Relay2run() {
  digitalWrite(Relay1, LOW);
}
//***********************************************************************************
void Relay2stop() {
  digitalWrite(Relay1, HIGH);
}
//***********************************************************************************
void sound() {
  tone(buzzer, 4000, 500);
  delay(300);
  tone(buzzer, 0, 500);
  delay(300);
  tone(buzzer, 4000, 500);
  delay(300);
  tone(buzzer, 0, 500);
  delay(500);
  tone(buzzer, 3500, 500);
  delay(300);
  tone(buzzer, 0, 500);
  delay(300);
  tone(buzzer, 3000, 500);
  delay(300);
  tone(buzzer, 0, 500);
  delay(300);
  tone(buzzer, 4000, 500);
  delay(800);
  tone(buzzer, 0, 500);
  delay(5000);
}
//***********************************************************************************
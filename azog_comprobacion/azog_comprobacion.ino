
int led1 = 12;
int led2 = 11;
int led3 = 10;
int boton1 = 2;
int boton2 = 9;

int motor_derecho_a = 3;
int motor_derecho_b = 4;
int pwm_derecho = 5;

int motor_izquierdo_a = 7;
int motor_izquierdo_b = 8;
int pwm_izquierdo = 6;
#define Stop 2
#define Adelante 1
#define Atras 0
int i=0;
int j=0;

void setup() {                
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
    pinMode(motor_derecho_a, OUTPUT);     
  pinMode(motor_derecho_b, OUTPUT);
  pinMode(motor_izquierdo_a, OUTPUT);
    pinMode(motor_izquierdo_b, OUTPUT);     

  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
    Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
 

  if (digitalRead(boton1) == HIGH) {     
    // turn LED on:    
    digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level) 
    digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
    i=i+3;
    j=0;
    ponMotores(-i,-i);
  } 
  if (digitalRead(boton2) == HIGH) {     
    // turn LED on:    
    digitalWrite(led1, LOW);   // turn the LED on (HIGH is the voltage level) 
    digitalWrite(led2, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(led3, LOW);   // turn the LED on (HIGH is the voltage level)
    ponMotores(j,j);
    j=j+3;
    i=0;
  } 
  
  if (analogRead(A0) < 255)Serial.print("1");else Serial.print("0");
  if (analogRead(A1) < 255)Serial.print("1");else Serial.print("0");
  if (analogRead(A2) < 255)Serial.print("1");else Serial.print("0");
  if (analogRead(A3) < 255)Serial.print("1");else Serial.print("0");
  if (analogRead(A4) < 255)Serial.print("1");else Serial.print("0");
  if (analogRead(A5) < 255)Serial.print("1");else Serial.print("0");
  if (analogRead(A6) < 255)Serial.print("1");else Serial.print("0");
  if (analogRead(A7) < 255)Serial.println("1");else Serial.println("0");
   

}

//-------------------------VARIABLES DEL CIRCUITO---------------------//
//--------------------------------NO TOCAR ---------------------------//
int led1 = 12;                  //NO TOCAR                            //
int led2 = 11;                  //NO TOCAR                            //
int led3 = 10;                  //NO TOCAR                            //
int boton1 = 2;                 //NO TOCAR                            //
int boton2 = 9;                 //NO TOCAR                            //
int motor_derecho_a = 3;        //NO TOCAR                            //
int motor_derecho_b = 4;        //NO TOCAR                            //
int pwm_derecho = 5;            //NO TOCAR                            //
int motor_izquierdo_a = 7;      //NO TOCAR                            //
int motor_izquierdo_b = 8;      //NO TOCAR                            //
int pwm_izquierdo = 6;          //NO TOCAR                            //
//--------------------------------------------------------------------//
//VARIABLES DE LA FUNCION DE CONTROL                                  //
//--------------------------------------------------------------------//
//--------------------------------NO TOCAR ---------------------------//
int errorAnt=0;                 //NO TOCAR                            //
int resultado;                  //NO TOCAR                           //
//--------------------------------------------------------------------//
//VARIABLES DE LA FUNCION PONMOTORES                                  //
//--------------------------------------------------------------------//
//--------------------------------NO TOCAR ---------------------------//
#define Stop 2                  //NO TOCAR                            //
#define Adelante 1              //NO TOCAR                            //
#define Atras 0                 //NO TOCAR                            //
                                                                      //
//--------------------------------------------------------------------//

//--------------------VARIBLES DE CONTROL DEL PID---------------------//
//------------MODIFICAR PARA MEJORAR FUNCIONAMIENTO-------------------//
int KD=16;
int KP=25;
int bias =100;
//--------------------------------------------------------------------//
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


void loop() {  
  resultado=pid(leer_sensor());
  Serial.print("error = ");
  Serial.print(resultado);
    Serial.print("sensor = ");
  Serial.println(analogRead(A7));
  ponMotores(bias + resultado,bias - resultado);
}



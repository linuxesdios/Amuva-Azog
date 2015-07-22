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
int errorAnt = 0;               //NO TOCAR                            //
int resultado;                  //NO TOCAR                            //
int lectura;                    //NO TOCAR                            //
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
int KD = 16;
int KP = 15;
int bias = 50;
int KP_p = 15;
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


//#define _lecturasimple
#define _lecturadoble

//#define _todonada
//#define _p
#define _pid


void loop() {
  
  //--------------------DISTINTOS MODOS DE LECTURA---------------------//
  
#if defined(_lecturasimple)
  lectura = LecturaSimple();
  Serial.println("lectura simple");
  
#endif
#if defined(_lecturadoble)
  lectura = LecturaDoble();
  Serial.println("lectura doble");
#endif

  //--------------------FIN DISTINTOS MODOS DE LECTURA---------------------//

  //--------------------DISTINTOS MODOS DE ACTUACION---------------------//
  
#if defined(_todonada)
  resultado = TodoNada(lectura);
  Serial.println("TodoNada");
#endif

#if defined(_p)
  resultado = P(lectura);
  Serial.println("p");
#endif

#if defined(_pid)
  resultado = Pid(lectura);
   Serial.println("pid");
#endif

  //-------------------- FIN DISTINTOS MODOS DE ACTUACION---------------------//

  ponMotores(bias - resultado, bias + resultado);
  delay(5);
}



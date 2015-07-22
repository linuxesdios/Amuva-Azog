int LecturaSimple()
{
  if(analogRead(A7) < 512) return -3;
  if(analogRead(A6) < 512) return -2;
  if(analogRead(A5) < 512) return -1;
  if(analogRead(A4) < 512) return 0;
  if(analogRead(A3) < 512) return 0;
  if(analogRead(A2) < 512) return 1;
  if(analogRead(A1) < 512) return 2;
  if(analogRead(A0) < 512) return 3;
  return 4;
}

int LecturaDoble()
{
  return((PrimD()+PrimI()-9)/-2);

}
int PrimD()
{
  if(analogRead(A0) < 512) return 1;
  if(analogRead(A1) < 512) return 2;
  if(analogRead(A2) < 512) return 3;
  if(analogRead(A3) < 512) return 4;
  if(analogRead(A4) < 512) return 5;
  if(analogRead(A5) < 512) return 6;
  if(analogRead(A6) < 512) return 7;
  if(analogRead(A7) < 512) return 8;
  return 0;
}
int PrimI()
{
  if(analogRead(A7) < 512) return 8;
  if(analogRead(A6) < 512) return 7;
  if(analogRead(A5) < 512) return 6;
  if(analogRead(A4) < 512) return 5;
  if(analogRead(A3) < 512) return 4;
  if(analogRead(A2) < 512) return 3;
  if(analogRead(A1) < 512) return 2;
  if(analogRead(A0) < 512) return 1;
  return 0;
}






int Pid(int error)
{
  if (error!=4)
  {
    resultado =  error*KP+(error - errorAnt)*KD; //Anadido parte proporcinal + derivativa
    errorAnt=error;
  }
  return resultado; //Devuelve la actuacion
}
int P(int error)
{
  if (error!=4)
  {
    resultado =  error*KP_p; //Anadido parte proporcinal + derivativa
  }
  return resultado; //Devuelve la actuacion
}
int TodoNada(int error)
{
  if (error!=4){
 if (error==0)resultado=0;
 if (error>0)resultado=100;
 if (error<0)resultado=-100;
 }
  return resultado; //Devuelve la actuacion
}


int leer_sensor()
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
int pid(int error)
{
  if (error!=4)
  {
    resultado =  error*KP+(error - errorAnt)*KD; //Anadido parte proporcinal + derivativa
    errorAnt=error;
  }
  return resultado; //Devuelve la actuacion
}


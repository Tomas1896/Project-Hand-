#include <Servo.h>

int estado = 1;
Servo pulgar; 
Servo indice;
Servo medio; 
Servo anular; 
Servo menique;  

int PosPulgar = 170; 
int PosIndice = 10; 
int PosMedio = 10; 
int PosAnular = 10; 
int PosMenique = 150; 

void servopulgar()
{
  for (PosPulgar = 10; PosPulgar <= 170; PosPulgar++)
  {
    
    pulgar.write(PosPulgar);
    delay(5);
    
  }
}

void servopulgar1()
{

    for(PosPulgar = 170; PosPulgar >= 10; PosPulgar--)
    {

        pulgar.write(PosPulgar); 
        delay(5);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    }
}

void servoindice()
{
  
    for (PosIndice = 10; PosIndice <= 170; PosIndice++)
    {
      
        indice.write(PosIndice);
        delay(5);
    
    }
}

void servoindice1()
{

    for (PosIndice = 170; PosIndice >= 10; PosIndice--)
    {

        indice.write(PosIndice);
        delay(5);
      
    }
}

void servomedio()
{

   for (PosMedio = 10; PosMedio <= 170; PosMedio++)
   {

       medio.write(PosMedio);
       delay(5);
    
   }
}

void servomedio1()
{

    for (PosMedio = 170; PosMedio >=10; PosMedio--)
    {
 
        medio.write(PosMedio);
        delay(5);
      
    }
}

void servoanular()
{

    for (PosAnular = 10; PosAnular <= 170; PosAnular++)
    {

        anular.write(PosAnular);
        delay(5);
      
    } 
}

void servoanular1()
{
     for (PosAnular = 170; PosAnular >=10; PosAnular--)
     {
         anular.write(PosAnular);
         delay(5);
     }
}

void servomenique()
{
    for (PosMenique = 150; PosMenique >=25; PosMenique--)
    {
        menique.write(PosMenique);
        delay(5);
    }
}

void servomenique1()
{
    for (PosMenique = 25; PosMenique <= 150; PosMenique++)
    {
        menique.write(PosMenique);
        delay(5);
    }
}
 
void setup() 
{
  
  Serial.begin(9600);
  
  pulgar.attach(13); //PIN 13 
  indice.attach(12); //PIN 12
  medio.attach(11); //PIN 11
  anular.attach(8); //PIN 8 
  menique.attach(6); //PIN 6 

  /* Posiciones Iniciales */
  pulgar.write(10);
  indice.write(10);
  medio.write(10);
  anular.write(10);
  menique.write(10);
  
}

void loop() 
{
  
  if(Serial.available()>0)
  {
    
    estado = Serial.read();

    if(estado == 'a')
    {
      
      servopulgar();
      
    } 
    
    if(estado == 'b')
    {
      
      servopulgar1();
      
    }

    if(estado == 'c')
    {

      servoindice();
      
    }

    if (estado == 'd')
    {

     servoindice1();
      
    }

    if(estado == 'e')
    {
      servomedio();
    }

    if (estado == 'f')
    {
      servomedio1();
    }

    if(estado == 'k')
    {
      servoanular();
    }

    if (estado == 'l')
    {
      servoanular1();
    }

    if(estado == 'o')
    {
      servomenique();
    }

    if (estado == 'p')
    {
      servomenique1();
    }

    if(estado == 'q') /* All off Arduino Control Voice */
    {
      
      pulgar.write(170);
      indice.write(10);
      medio.write(10);
      anular.write(10);
      menique.write(150);
      
    }

    if(estado == 'r') /* Blink Arduino Control Voice */ 
    {
      pulgar.write(10);
      indice.write(170);
      medio.write(170);
      anular.write(170);
      menique.write(25);
    }

    if(estado == 's')  /* Blink Arduino Control Voice */
    {
      pulgar.write(170);
      indice.write(10);
      medio.write(10);
      anular.write(10);
      menique.write(150);
    }

     if (estado =='t') /* Sequence 1 */ 
     {
      pulgar.write(10);
        delay(5);
        
        indice.write(10);  
        delay(5);
        
        medio.write(10);
        delay(5);

        anular.write(10);
        delay(5);

        menique.write(10);
        delay(5);

     }

     if(estado == 'u') /* Sequence 2 */
     {
      pulgar.write(90);
        delay(200);

        pulgar.write(10);
        indice.write(135);
        delay(200);

        indice.write(10);
        medio.write(170);  
        delay(200);

        medio.write(30);
        anular.write(30);
        delay(200);

        anular.write(130);
        menique.write(40);
        delay(200);


        menique.write(90);
        delay(200);
     }

     if(estado == 'v') /* Sequence 3 */
     {
      pulgar.write(10);
      indice.write(170);
      medio.write(170);
      anular.write(170);
      menique.write(25);
     }
}

}

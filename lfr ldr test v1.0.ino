int s0 = A0;
int s1 = A1;
int s2 = A2;
int s3 = A3;
int s4 = A4;

int lmpin1 = 8;
int lmpin2 = 9;
int rmpin1 = 10;
int rmpin2 = 11;
int en1 = 6;
int en2 = 7;

int threshold = 200;
int Status;
int previousStatus = 0;

void setup()
{
  pinMode(s0, INPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(lmpin1, OUTPUT);
  pinMode(lmpin2, OUTPUT);
  pinMode(rmpin1, OUTPUT);
  pinMode(rmpin2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  analogWrite(en1 , 150 );
  analogWrite(en2 , 150 );
  
}

void loop()
{
  //(analogRead(A0)>threshold) ?s0=1 :s0=0;
  (analogRead(A1)>threshold) ?s1=1 :s1=0;
  (analogRead(A2)>threshold) ?s2=1 :s2=0;
  (analogRead(A3)>threshold) ?s3=1 :s3=0;
  //(analogRead(A4)>threshold) ?s4=1 :s4=0;
 
  
  Status = (s1*4 + s2*2 + s3*1);
  if(Status!=previousStatus)
  {
    switch(Status)
    {
      case 0 : // do as it is
               break;
      
      case 1 : turnLeft();
               break;
               
      case 2 : // do as it is
               break;
              
      case 3 : turnLeft();
               break;
      
      case 4 : turnRight();
               break;
      
      case 5 : goStraight();
               break;   
      
      case 6 : turnRight();
               break;
     
      case 7 : Stop();
               break; 
    }
    previousStatus = Status;
  }
}

void turnRight()
{
  Stop();
  delay(50);
  analogWrite(rmpin1 , 115);
  digitalWrite(rmpin2 , LOW);
  analogWrite(lmpin2 , 65);
  digitalWrite(lmpin1 , LOW);
}

void goStraight()
{
  analogWrite(lmpin1 , 150);
  digitalWrite(lmpin2 , LOW);
  analogWrite(rmpin1 , 150);
  digitalWrite(rmpin2 , LOW);
}

void turnLeft()
{
  Stop();
  delay(50);
  analogWrite(rmpin2 , 65);
  digitalWrite(rmpin1 , LOW);
  analogWrite(lmpin1 ,115);
  digitalWrite(lmpin2 , LOW);
}

void Stop()
{
  digitalWrite(lmpin1 , LOW);
  digitalWrite(lmpin2 , LOW);
  digitalWrite(rmpin2 , LOW);
  digitalWrite(rmpin1 , LOW);
}

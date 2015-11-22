void setup() 
{
  pinMode (2, INPUT_PULLUP);
  
  pinMode (13, OUTPUT);
  digitalWrite(13, LOW);
  
  Serial.begin(9600);
  /* 
  Anton Code
  pinMode ( 2, INPUT);
  pinMode ( 13, LOW);
  */
}

void loop() 
{
  if(digitalRead(2))
    digitalWrite(13, LOW);
    //Serial.write('*');
  else
    {
      digitalWrite(13, HIGH);
      Serial.write('*'); //이럴 경우 *가 버튼이 눌러졌을때 수도없이 써진다 
    }
 /*Anton Code
  Serial.read(2);
    if (Serial.read (1))
    {
      pinMode(13, HIGH);
    }
    else 
    {
      pinMode(13, LOW);
    }
  */

}

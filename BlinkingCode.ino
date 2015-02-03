const int LED1 = 3;
const int LED2 = 4;
const int LED3 = 5;
const int LED4 = 6;
const int LED5 = 7;
int myPins[] = {0, 0, 0, 0, 0};

void SetupPins()
{
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED5, OUTPUT);    
}

void AllOff()
{
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, LOW);
   digitalWrite(LED3, LOW);
   digitalWrite(LED4, LOW);
   digitalWrite(LED5, LOW);
}

void toggleLED(int LED)
{
  if( myPins[LED] == 0)
  {
    digitalWrite(LED + 3,HIGH);
    myPins[LED] = 1;    
  }
  else
  {
    digitalWrite(LED + 3,LOW);
    myPins[LED] = 0;
  }
}

void flickerLED(int LED)
{
  toggleLED(LED);
  delay(random(5,70));
  toggleLED(LED);
}

void setup()
{
  Serial.begin(115200);
  AllOff();
  SetupPins();
  AllOff();
}

void loop()
{    
  delay(random(20,6000));
  int flashes = int(random(5,20)); 
  for(int flash = 0; flash < flashes; flash++)
  {
    flickerLED(int(random(0,5)));  
  }
}

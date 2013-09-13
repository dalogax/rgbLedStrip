
const int RED = 10; 
const int GREEN = 9;
const int BLUE = 11;
const int LED = 12;
const int SENSOR = 0;

int r = 0; 
int g = 0;
int b = 0;

int sensorMin = 0;
int sensorMax = 0; 

long int sensorValue = 0;
long int printValue = 0;

void setup(){
  Serial.begin(115200);
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(LED, OUTPUT);
  
  analogWrite(RED, r); 
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
  
  sensorMin = analogRead(SENSOR);
  sensorMax = sensorMin;
}

void loop(){
   
 
  int value = analogRead(SENSOR);
  
  if (value<sensorMin){
    sensorMin=value;
  }
  if (value>sensorMax){
    sensorMax=value;
  }
  
  if ((value>(20+sensorValue)) || (value <(sensorValue-20))){
    sensorValue = value;
    Serial.println(value);
    printValue = map(value, sensorMin, sensorMax, 0, 255);
  }
  else{
     printValue = 0; 
  }
  
  //Apagado
  if (printValue<50){
    r=0;
    g=0;
    b=0;
  }
  //aluz - violeta
  else if (printValue<100){
    r=printValue/2;
    g=0;
    b=printValue;
  }
  //violeta - rojo
  else if (printValue<150){
    r=printValue;
    g=0;
    b=printValue/2;
  }
  //rojo - amarillo
  else if (printValue<200){
    r=printValue/2;
    g=printValue;
    b=0;
  }
  //amarillo- verde
  else if (printValue<255){
    r=printValue/2;
    g=printValue;
    b=0;
  }
  
  pinta();
  delay(10);
}

void pinta(){
    analogWrite(RED, r); 
    analogWrite(GREEN, g);
    analogWrite(BLUE, b);
}

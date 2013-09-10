
const int RED = 10; 
const int GREEN = 9;
const int BLUE = 11;
const int LED = 12;
const int SENSOR = 0;

int r = 0; 
int g = 0;
int b = 0;

int sensorMin = 500;
int sensorMax = 1000;    

long int sensorValue = 0;

void setup(){
  Serial.begin(115200);
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(LED, OUTPUT);
  
  analogWrite(RED, r); 
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void loop(){
    
  // apply the calibration to the sensor reading
  sensorValue = map(analogRead(SENSOR), sensorMin, sensorMax, 0, 255);
  Serial.println(sensorValue);
  
  r=sensorValue;
  g=0;
  b=map(sensorValue,0,255,255,0);
  
  pinta();
}

void pinta(){
    analogWrite(RED, r); 
    analogWrite(GREEN, g);
    analogWrite(BLUE, b);
}

const int RED = 10; 
const int GREEN = 9;
const int BLUE = 11;

int r = 0; 
int g = 127;
int b = 255;

boolean rsubiendo = true;
boolean gsubiendo = true;
boolean bsubiendo = false;

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop(){
 
    changeColor(&rsubiendo,&r);
    changeColor(&gsubiendo,&g);
    changeColor(&bsubiendo,&b);
    
    pinta();
    delay(10);
   
}
  
void pinta(){
    analogWrite(RED, r); 
    analogWrite(GREEN, g);
    analogWrite(BLUE, b); 
}

void changeColor(boolean *subiendo, int *color){
     if (*subiendo){
      if ((*color)<255){
        (*color)++;
      }
      else{
        (*subiendo)=false;
      }
    }
    else if ((*color)<1){
      (*subiendo)=true;
    }
    else{
      (*color)--;
    }
}

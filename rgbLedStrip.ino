const int FADESPEED = 10;
const int RED = 10; 
const int GREEN = 9;
const int BLUE = 11;

int r = 0; 
int g = 0;
int b = 255;

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  analogWrite(RED, r); 
  analogWrite(GREEN, g);
  analogWrite(BLUE, b); 
}

void loop(){
    // fade from blue to violet
    for (r = 0; r < 256; r++) {
      analogWrite(RED, r);
      delay(FADESPEED);
    }
    // fade from violet to red
    for (b = 255; b > 0; b--) {
      analogWrite(BLUE, b);
      delay(FADESPEED);
    }
    // fade from red to yellow
    for (g = 0; g < 256; g++) {
      analogWrite(GREEN, g);
      delay(FADESPEED);
    }
    // fade from yellow to green
    for (r = 255; r > 0; r--) {
      analogWrite(RED, r);
      delay(FADESPEED);
    }
    // fade from green to teal
    for (b = 0; b < 256; b++) {
      analogWrite(BLUE, b);
      delay(FADESPEED);
    }
    // fade from teal to blue
    for (g = 255; g > 0; g--) {
      analogWrite(GREEN, g);
      delay(FADESPEED);
    }
}

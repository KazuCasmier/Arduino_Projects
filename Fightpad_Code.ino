#include "Keyboard.h"

const int button_parry = 2;
const int button_A = 3;
const int button_S = 4;
const int button_D = 5;
const int button_DI = 6;
const int button_W = 7;
const int button_U= 8;
const int button_J = 9;
const int button_I = 10;
const int button_O = 14;
const int button_L = 15;
const int button_K = 16;

void setup() {
  Serial.begin(9600);
  pinMode(button_parry , INPUT_PULLUP);
  pinMode(button_A, INPUT_PULLUP);
  pinMode(button_S, INPUT_PULLUP);
  pinMode(button_D, INPUT_PULLUP);
  pinMode(button_DI, INPUT_PULLUP);
  pinMode(button_W, INPUT_PULLUP);
  pinMode(button_U, INPUT_PULLUP);
  pinMode(button_J, INPUT_PULLUP);
  pinMode(button_I, INPUT_PULLUP);
  pinMode(button_O, INPUT_PULLUP);
  pinMode(button_L, INPUT_PULLUP);
  pinMode(button_K, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {
  
  if(digitalRead(button_D) == LOW){
    Keyboard.press(100);
  }
  else{
    Keyboard.release(100);
  }

  if(digitalRead(button_A) == LOW){
    Keyboard.press(97);
  }
  else{
    Keyboard.release(97);
  }

  if(digitalRead(button_W) == LOW){
    Keyboard.press(119);
  }
  else{
    Keyboard.release(119);
  }

    
  if(digitalRead(button_S) == LOW){
    Keyboard.press(115);
  }
  else{
    Keyboard.release(115);
  }

  if(digitalRead(button_U) == LOW){
    Keyboard.press(117);
  }
  else{
    Keyboard.release(117);
  }

  if(digitalRead(button_J) == LOW){
    Keyboard.press(106);
  }
  else{
    Keyboard.release(106);
  }

    
  if(digitalRead(button_I) == LOW){
    Keyboard.press(105);
  }
  else{
    Keyboard.release(105);
  }

  if(digitalRead(button_O) == LOW){
    Keyboard.press(108);
  }
  else{
    Keyboard.release(108);
  }

  if(digitalRead(button_L) == LOW){
    Keyboard.press(111);
  }
  else{
    Keyboard.release(111);
  }

    
  if(digitalRead(button_K) == LOW){
    Keyboard.press(107);
  }
  else{
    Keyboard.release(107);
  }

  if(digitalRead(button_parry) == LOW){
    Keyboard.press(104);
  }
  else{
    Keyboard.release(104);
  }

  if(digitalRead(button_DI) == LOW){
    Keyboard.press(121);
  }
  else{
    Keyboard.release(121);
  }
}

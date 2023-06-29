//Librerias
#include <SoftwareSerial.h>
#include <Servo.h>
#include "LedControl.h"    

//Matrix 8x8

LedControl lc=LedControl(11,13,12);
SoftwareSerial BT(8, 9);

//Variables

char valor;
int l = 2;
int l2 = 3;
int l3 = 4;
int l4 = 5;
const int servoPin1 = 6;

//Dibujo/figura Matrix 8x8

byte uno[8]= {     
  B10010000,       
  B01110000,
  B01010000,
  B10010000,
  B00010000,
  B10110000,
  B00010000,
  B10111110
};

Servo servo;

//Inicializacion del programa

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(l, OUTPUT);
  pinMode(l2, OUTPUT);
  servo.attach(servoPin1);
  lc.shutdown(0,false);     // enciende la matriz
  lc.setIntensity(0,4);     // establece brillo
  lc.clearDisplay(0);     // blanquea matriz
}



void loop() {

movi();

  if(BT.available() > 0){
    valor = BT.read();
    Serial.println(valor);
  }

  if(valor == 'A'){
    digitalWrite(l, HIGH);
  }

  if(valor == 'B'){
    digitalWrite(l, LOW);
  }

  if(valor == 'C'){
    digitalWrite(l2, HIGH);
  }

  if(valor == 'D'){
    digitalWrite(l2, LOW);
  }

    if(valor == 'E'){
    digitalWrite(l3, HIGH);
  }

  if(valor == 'F'){
    digitalWrite(l3, LOW);
  }

    if(valor == 'G'){
    digitalWrite(l4, HIGH);
  }

  if(valor == 'H'){
    digitalWrite(l4, LOW);
  }
  
  if(valor == 'H'){
    digitalWrite(l4, LOW);
  }
  
  if(valor == 'I'){
    most();
  }
}

void movi(){
  while(BT.available() > 0){
    valor = BT.read();
    Serial.println(valor);
    servo.write(valor);
    delay(10);
  }
}

void most(){    
  for (int i = 0; i < 8; i++)    
  {
  lc.setRow(0,i,uno[i]);  
  }
}
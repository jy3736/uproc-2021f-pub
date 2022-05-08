#include <Wire.h>

#define I2C_ADDR 11
#define R 11
#define Y 12
#define G 13

unsigned len;
byte msg[20];
byte cmd = 0;
byte busy = 0;

// -----------------------------------------------------
void setup() {
  Wire.begin(I2C_ADDR);
  Serial.begin(9600);
  pinMode(R,OUTPUT); 
  pinMode(Y,OUTPUT); 
  pinMode(G,OUTPUT); 
  Serial.print("I2C Traffic-Light: ");
  Serial.println(I2C_ADDR);
  Serial.println("======================================");
  delay(1000);    
  Wire.onReceive(irsReceive);
  Wire.onRequest(irsRequest);
}

// -----------------------------------------------------
void disp_msg() {
  Serial.print("Received data  : ");
  for(int i=0; i<len; i++) {
    Serial.print(msg[i]);
    Serial.print(" ");
  }
  Serial.println();
}

// -----------------------------------------------------
bool keepgoing() {
  byte chk;
  noInterrupts();
  chk = busy;
  interrupts();
  return chk==0;  
}

// -----------------------------------------------------
void allOff() {
  digitalWrite(Y,0);
  digitalWrite(G,0);
  digitalWrite(R,0);  
}

// -----------------------------------------------------
void BLINK(int led) {
  allOff();
  while (keepgoing()) {
    digitalWrite(led,1);
    delay(50*msg[1]);
    if (!keepgoing()) break;
    digitalWrite(led,0);
    delay(50*msg[1]);
  }
}

// -----------------------------------------------------
void R2G() {
  // *** add your code here ***
}

// -----------------------------------------------------
void G2R() {
  // *** add your code here ***
}

// *** modify this function accordingly ***
// -----------------------------------------------------
void tasks(byte tn, bool once=true) {
  cmd = 0;
  busy = (once)?0:1;
  switch(tn) {
    case 1   : digitalWrite(R,0); break;
    case 2   : digitalWrite(R,1); break;
    case 3   : digitalWrite(Y,0); break;
    case 4   : digitalWrite(Y,1); break;
    case 5   : digitalWrite(G,0); break;
    case 6   : digitalWrite(G,1); break;
    case 11  : BLINK(R); break;
  }  
}

// -----------------------------------------------------
void CMDS() {
  for(int i=1; i<len; i++)
    tasks(msg[i],false);
  busy = 0;
}

// -----------------------------------------------------
void loop() {
   switch(cmd) {
    case 0   : break;
    case 200 : CMDS(); break;
    default  : tasks(cmd);
  }  
  delay(0);
}

// -----------------------------------------------------
void irsReceive(int nb) {
  busy = nb;
  len = 0;
  while (Wire.available())
    msg[len++] = Wire.read();
  cmd = msg[0];  
  disp_msg();
}

// -----------------------------------------------------
void irsRequest() {
  Wire.write(busy); 
}

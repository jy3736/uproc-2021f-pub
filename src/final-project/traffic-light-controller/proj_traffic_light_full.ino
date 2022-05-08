//--------------------------------------------
// Title  : Simple Traffic Light Controller
// Author : Jung-Lin Yang
// Date   : Oct 23, 2020
//--------------------------------------------


// Delay paramaters
//--------------------------------------------
int dR  = 3000;
int dRY = 800;
int dG  = 4000;
int dY  = 800;
int dF  = 400;  // blinking

// I/O pin assignment
//--------------------------------------------
const int RED[2] = {8,2};
const int YELLOW[2] = {10,4};
const int GREEN[2] = {12,6};
const int BT1 = 5;
const int BT2 = 7;

// Other paramaters
//--------------------------------------------
unsigned long tPrev;      // state transition time
int  mode = 4;  // current mode
int  sta = 0;   // current state

// Function prototype
//--------------------------------------------
void  mode0();
void  mode1();
void  mode2();
void  mode3();
void  mode4();
void  mode5();
void  mode6();
void  mode7();
void  mode8();
void  scanBT1();  
void  scanBT2();
void  scanUART();
void  hsImcomplete();

// I/O configuration
//--------------------------------------------
void setup()
{
  Serial.begin(9600);
  for(int d=0; d<2; d++) {  
    pinMode(RED[d], OUTPUT);
    pinMode(GREEN[d], OUTPUT);
    pinMode(YELLOW[d], OUTPUT);
  }
  
  pinMode(BT1,INPUT);
  pinMode(BT2,INPUT);
  
  R(0); R(1);
  tPrev = millis();
}

// Main loop
//--------------------------------------------
void loop()
{
  scanBT1();  
  scanBT2();
  scanUART();
  hsImcomplete(); // remove when complete mode 6/7!
  
  switch(mode) {
    case 0: mode0(); break;
    case 1: mode1(); break;
    case 2: mode2(); break;
    case 3: mode3(); break;
    case 4: mode4(); break;
    case 5: mode5(); break;
    case 6: mode6(); break;
    case 7: mode7(); break;
    case 8: mode8(); break;
    default: mode = 4;
             tPrev = millis();
  }
}

// Scan button 1 => mode 0 ~ 7
//--------------------------------------------
void scanBT1() {
  static int bt1=0;

  if (digitalRead(BT1)==LOW) {
    delay(5);
    if (digitalRead(BT1)==LOW) bt1=0;
  }
  
  if (bt1==0 && digitalRead(BT1)==HIGH) {
    delay(5);
    if (digitalRead(BT1)==HIGH) {
      bt1=1;
      mode+=1;
      if (mode>7 || mode<0) mode=0;
      tPrev = millis();
    }
  }
}

// Scan button 2 => mode 8
//--------------------------------------------
void scanBT2() {
  static int bt2=0;

  if (digitalRead(BT2)==LOW) {
    delay(5);
    if (digitalRead(BT2)==LOW) bt2=0;
  }
  
  if (bt2==0 && digitalRead(BT2)==HIGH) {
    delay(5);
    if (digitalRead(BT2)==HIGH) {
      bt2=1;
      mode=8;
      tPrev = millis();
      sta = (sta==2)?3:0;
    }
  }
}

// Scan srial port => mode 0 ~ 8
//--------------------------------------------
void scanUART() {
  if (Serial.available()) {
    int n = Serial.parseInt();
    if (n>=0 && n<9) {
      mode = n;
      tPrev = millis();
      if (mode==8 && sta==2)
        sta = 3;
      else
        sta = 0;
    }
  }
}

// Handle imcompleted mode 6 and 7
//--------------------------------------------
void hsImcomplete() {
  switch(mode) {
    case 6: mode = 5; break;
    case 7: mode = 4; break;            
  }
}

// RED light on
//--------------------------------------------
void R(int d){
  digitalWrite(GREEN[d],LOW);
  digitalWrite(YELLOW[d],LOW);
  digitalWrite(RED[d],HIGH);
}

// RED/YELLOW lights on
//--------------------------------------------
void RY(int d){
  digitalWrite(GREEN[d],LOW);
  digitalWrite(YELLOW[d],HIGH);
  digitalWrite(RED[d],HIGH);
}

// Green light on
//--------------------------------------------
void G(int d){
  digitalWrite(GREEN[d],HIGH);
  digitalWrite(YELLOW[d],LOW);
  digitalWrite(RED[d],LOW);
}

// Yellow light on
//--------------------------------------------
void Y(int d){
  digitalWrite(GREEN[d],LOW);
  digitalWrite(YELLOW[d],HIGH);
  digitalWrite(RED[d],LOW);
}

// All lights off
//--------------------------------------------
void OFF(int d) {
  digitalWrite(GREEN[d],LOW);
  digitalWrite(YELLOW[d],LOW);
  digitalWrite(RED[d],LOW);
}

// Mode 0 operation
//--------------------------------------------
void mode0() {
  OFF(0);
  OFF(1);
  tPrev = millis();
}

// Mode 1 operation
//--------------------------------------------
void mode1() {
  G(0); R(1);
  tPrev = millis();
}

// Mode 2 operation
//--------------------------------------------
void mode2() {
  G(1); R(0);
  tPrev = millis();
}

// Mode 3 operation
//--------------------------------------------
void mode3() {
  switch(sta) {
    case 0: R(0); R(1);
        if (millis()-tPrev<dF) return;
        sta = 1;
        tPrev = millis();
        OFF(0); OFF(1);
        break;
    case 1: if (millis()-tPrev<dF) return;
        sta = 0;
        tPrev = millis();
         R(0); R(1);
        break;
    default: sta = 0;
  }
}

// Mode 4 operation
//--------------------------------------------
void mode4() {
  switch(sta) {
    case 0: Y(0); Y(1);
        if (millis()-tPrev<dF) return;
        sta = 1;
        tPrev = millis();
        OFF(0); OFF(1);
        break;
    case 1: if (millis()-tPrev<dF) return;
        sta = 0;
        tPrev = millis();
         Y(0); Y(1);
        break;
    default: sta = 0;    
  }
}

// Mode 5 operation
//--------------------------------------------
void mode5(){
  switch(sta) {
    case 0: R(0); G(1);
        if (millis()-tPrev<dR) return;
        sta = 1;
        tPrev = millis();
        RY(0); Y(1);
        break;
    case 1: if (millis()-tPrev<dRY) return;
        sta = 2;
        tPrev = millis();
        G(0); R(1);
        break;
    case 2: if (millis()-tPrev<dG) return;
        sta = 3;
        tPrev = millis();
            Y(0); RY(1);  
        break;
    case 3: if (millis()-tPrev<dY) return;
        sta = 0;
        tPrev = millis();
        R(0); G(1);
        break;
    default: sta = 0;  
  }
}

// Mode 6 operation
//--------------------------------------------
void mode6() {
  // add your code here  
}

// Mode 7 operation
//--------------------------------------------
void mode7() {
  // add your code here  
}

// Mode 8 operation
//--------------------------------------------
void mode8() {
  switch(sta) {
    case 0: R(0); G(1);
        if (millis()-tPrev<dR) return;
        sta = 1;
        tPrev = millis();
        RY(0); Y(1);
        break;
    case 1: if (millis()-tPrev<dRY) return;
        sta = 2;
        tPrev = millis();
        G(0); R(1);
        break;
    case 2: break;
    case 3: if (millis()-tPrev<dG) return;
        sta = 4;
        tPrev = millis();
            Y(0); RY(1);  
        break;
    case 4: if (millis()-tPrev<dY) return;
        sta = 5;
        tPrev = millis();
        R(0); G(1);
        break;
    case 5: break;
    default: sta = 0;  
  }
}

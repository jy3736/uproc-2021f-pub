<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>
<hr style="border:4px solid gray"> </hr>

<div style="text-align: center;">
<br><br>
        
# [Digital I/O & Serial Read/Write](https://www.tinkercad.com/)
### https://www.tinkercad.com/

<br><br>
</div>

<hr style="border:4px solid gray"> </hr>

<br><hr style="border:2px solid orange"> </hr>

### [Lab 01 - Serial-port Controlled LED](https://www.tinkercad.com/things/egx5M5pXnUM-arduino-w05-lab01/editel)

* Receive control commands N from the serial port:
    * N = 1, set the LED blinking cycle to 100ms
    * N = 2, set the LED blinking cycle to 500ms
    * N = 3, set the LED blinking cycle to 1s
    * Others, print "Unknown command!" to the serial port
    
<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/arduino-w05-lab01.png" alt="Arduino-lab01" class="left" style="width: 300px;"/>
</div>

<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Code :*](https://www.tinkercad.com)
```cpp
int dly = 100;
int ledst = LOW;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(13,ledst);
  if (Serial.available()) {
    int cmd = Serial.parseInt();
    Serial.print("Received cmd = ");
    Serial.println(cmd);
    switch(cmd) {
      case 1 : dly = 100; break;
      case 2 : dly = 500; break;
      case 3 : dly = 1000; break;
      default: Serial.println("Unknown command!"); break;
    }
  }
  ledst = ~ledst;
  delay(dly);
}
```

<br><hr style="border:2px solid orange"> </hr>

### [Lab 02 - Blink without Delay](https://www.tinkercad.com/things/8pTZOa1QEup-terrific-elzing-amberis/editel?tenant=circuits)

* Turns on and off a LED connected to pin 13, `without using the delay() function`.
 
<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/arduino-w05-lab02.png" alt="Arduino-lab02" class="left" style="width: 300px;"/>
</div>

<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Code :*](https://www.tinkercad.com)
```cpp
const int led =  13;
int ledSt = LOW;            

unsigned long prevT = 0;        
const long intv = 500;          

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  unsigned long curT = millis();

  if (curT - prevT >= intv) {
    prevT = curT;
    ledSt = ~ledSt;
    digitalWrite(led, ledSt);
  }
}
```

<br><hr style="border:3px solid red"> </hr>
<div style="text-align: center;">         
    
# [*Homework Assignment*](https://www.tinkercad.com/)

</div>
<hr style="border:3px solid red"> </hr>
<br>

### [Homework 01 - Button/Serial Control Traffic Light](https://www.tinkercad.com/things/29ularf7Kgv-arduino-w04-hw01/editel)

* Based one the given Arduino circuit, design a 6-Mode traffic light controller.
* Provide 2 control methods: 
    - Each time the button is pressed, the operation mode is switched.
        * Mode 0 : all LEDs are off
        * Mode 1 : turn on the red LED
        * Mode 2 : red LED flashes with a period of 500ms
        * Mode 3 : turn on the yellow LED
        * Mode 4 : yellow LED flashes with a period of 500ms
        * Mode 5 : repeat the sequence of traffic lights
            * red (800ms)
            * red + yellow (200ms)
            * green (1s)
            * yellow (200ms))
    - Receive control commands from the serial port:
        * When n is received, switch to mode n. n is an integer between 0 and 5.

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/arduino-w05-hw01.png" alt="Arduino-hw01" class="left" style="width: 300px;"/>
</div>

<br><hr style="border:2px solid red"> </hr><br>

<div style="text-align: left;">
<img src="images/break-yang-tr.png" alt="Break" class="center" style="width: 500px;"/>
</div>



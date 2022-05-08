<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>
<hr style="border:4px solid gray"> </hr>

<div style="text-align: center;">
<br><br>
        
# Introduction to [Arduino](https://www.arduino.cc/) & [TinkerCAD](https://www.tinkercad.com/)
### https://www.tinkercad.com/

<br><br>
</div>

<hr style="border:4px solid gray"> </hr>

<br><hr style="border:2px solid orange"> </hr>

### [Lab 01 - Blinking](https://www.tinkercad.com/things/7zmrFTtsUpH-arduino-w04-lab01/editel)

* Turn the LED on/off repeatedly within one second.

<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/lab01.png" alt="Arduino-lab01" class="left" style="width: 300px;"/>
</div>

<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Code :*](https://www.tinkercad.com)
```cpp
int led = LOW;

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  led = ~led;
  digitalWrite(13,led);
  delay(500); 
}
```

<br><hr style="border:2px solid orange"> </hr>

### [Lab 02 - Button Control LED On/Off](https://www.tinkercad.com/things/3aDtvyRm5FH-arduino-w04-lab02/editel)

* LED lights up when the button is pressed.
* LED goes off when the button is released.

<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/lab02.png" alt="Arduino-lab02" class="left" style="width: 300px;"/>
</div>

<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Code :*](https://www.tinkercad.com)
```cpp
int buttonState = 0;

void setup()
{ 
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  delay(10); 
}
```

<br><hr style="border:3px solid red"> </hr>
<div style="text-align: center;">         
    
# [*Homework Assignment*](https://www.tinkercad.com/)

</div>
<hr style="border:3px solid red"> </hr>
<br>

### [Homework 01 - Button Control Blinking](https://www.tinkercad.com/things/29ularf7Kgv-arduino-w04-hw01/editel)

* Plese refer to the Lab 02, reconnect the LED to `pin 8` and the button to `pin 7`.
* The LED `blinks quickly` when the button is released.
* When the button is pressed, the LED `blinks slowly`.


#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/hw01.png" alt="Arduino-hw01" class="left" style="width: 300px;"/>
</div>

<br><hr style="border:2px solid red"> </hr><br>

<div style="text-align: left;">
<img src="images/break-yang-tr.png" alt="Break" class="center" style="width: 500px;"/>
</div>



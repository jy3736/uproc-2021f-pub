<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>
<hr style="border:4px solid gray"> </hr>

<div style="text-align: center;">
<br><br>

    
# [Analog I/O & Serial Communication](https://www.arduino.cc/en/Tutorial/BuiltInExamples)
### Arduino Built-In Examples

<br><br>
</div>

<hr style="border:4px solid gray"> </hr>

<br><hr style="border:2px solid orange"> </hr>

### [Lab 01 - State Change Detection for pushbuttons](https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection)

* Learn how to check the status change of the button
* When the button state changes, send a message to the serial monitor
* Count 4 state changes to turn on/off the on-board LED
    
<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/arduino-w06-lab01.png" alt="Arduino-lab01" class="left" style="width: 300px;"/>
</div>

<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Code :*](https://www.tinkercad.com)
```c++
int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);

  pinMode(13, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(2);
  
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter += 1;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      Serial.println("off");
    }
    delay(5); 
  }
  
  lastButtonState = buttonState;
  
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}
```

<hr style="border:0.5px solid gray"> </hr>
<div style="text-align: left;">
<a href="https://www.tinkercad.com">
<img src="images/tinkercad.png" alt="TinkerCAD" class="left" style="width: 200px;"/>
</a>
</div>

<br><hr style="border:2px solid orange"> </hr>

### [Lab 02 - Analog In, Out Serial](https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial)

* Read the analog input pin and map the result to the range of 0 to 255
* Use the result to set the pulse width modulation (PWM) of the output pin
* Print the result to the serial monitor

    
<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/arduino-w06-lab02.png" alt="Arduino-lab01" class="left" style="width: 300px;"/>
</div>

<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Code :*](https://www.tinkercad.com)
```c++
int sensorValue = 0;
int outputValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  sensorValue = analogRead(A0);
  
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
  analogWrite(9, outputValue);
  
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  delay(2); 
}
```
    
<hr style="border:0.5px solid gray"> </hr>
<div style="text-align: left;">
<a href="https://www.tinkercad.com">
<img src="images/tinkercad.png" alt="TinkerCAD" class="left" style="width: 200px;"/>
</a>
</div>

<br><hr style="border:2px solid orange"> </hr>

### [Lab 03 - Fading](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fading)

* This example shows how to fade an LED on pin 9 using the analogWrite() function.
    
<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/arduino-w06-lab03.png" alt="Arduino-lab01" class="left" style="width: 300px;"/>
</div>

<hr style="border:0.5px solid gray"> </hr>

#### [*Arduino Code :*](https://www.tinkercad.com)
```c++
int brightness = 0;

void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  for (brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(9, brightness);
    delay(30); 
  }
    
  for (brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(9, brightness);
    delay(30); 
  }
}
```
    
<hr style="border:0.5px solid gray"> </hr>
<div style="text-align: left;">
<a href="https://www.tinkercad.com">
<img src="images/tinkercad.png" alt="TinkerCAD" class="left" style="width: 200px;"/>
</a>
</div>


<br><hr style="border:3px solid red"> </hr>
<div style="text-align: center;">         
    
# [*Homework Assignment*](https://www.tinkercad.com/)

</div>
<hr style="border:3px solid red"> </hr>
<br>

### [Homework 01 - Button Controlled LED Operations](https://www.tinkercad.com)

* Lab 01 extention
* Connect a `GREEN` led to the `pin 7`, and a `RED` led to the `pin 11`
* When the status change counter can be divided by `3`, flash the `GREEN` led with a cycle time of `1 second`.
* When the status change counter can be divided by `5`, flash the `RED` led with a cycle time of `2 second`.

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/arduino-w06-hw01.png" alt="Arduino-hw01" class="left" style="width: 300px;"/>
</div>


<hr style="border:2px solid red"> </hr>
<br>

### [Homework 02 - Controllable Fading LED](https://www.tinkercad.com)

* Lab 02 + Lab 03 Extention
* Rewire the LED to `another` PWM output pin
* Read the analog data from the potentiometer and map the result to the range of `5 to 40`
* Use the result to set the changing brightness of the LED

#### [*Arduino Circuit :*](https://www.tinkercad.com)

<div style="text-align: center;">
<img src="images/arduino-w06-hw02.png" alt="Arduino-hw01" class="left" style="width: 300px;"/>
</div>

<hr style="border:2px solid red"> </hr>
<br>

### [Homework 03 - Controllable Fading LED Without Delay](https://www.tinkercad.com)

* Extra points
* Re-implement your Homework 02 `without using the delay(...) function`

<br><hr style="border:2px solid red"> </hr><br>

<div style="text-align: left;">
<img src="images/break-yang-tr.png" alt="Break" class="center" style="width: 600px;"/>
</div>



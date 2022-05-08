import paho.mqtt.client as mqtt
import json
import serial
import time

mode = 0

ser = serial.Serial(
    port='/dev/ttyACM0',
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("p203")

def on_message(client, userdata, msg):
    readdata_mqtt = " "
    readdata_uart = " "
    readdata_mqtt = msg.payload.decode('ascii')
    ser.write(str.encode(readdata_mqtt))
    time.sleep(1)
    readdata_uart=str(ser.readline())[2:]
    client.publish("MQTT" , readdata_uart[:-1])
 
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("192.168.50.12",1883,30)

while True:        
    client.loop()
    c = str(ser.readline())
    if(c != 'b\'\''):
        client.publish(c)
        mode=int(c[2])
        if(mode<=8):
            ser.write(str.encode(str(mode)))

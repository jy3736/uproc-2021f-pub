import paho.mqtt.client as mqtt
import json
import serial
import time


ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("MQTT/setting")

def on_message(client, userdata, msg):
    readdata_mqtt = " "
    readdata_uart = " "
    readdata_mqtt = msg.payload.decode('ascii')
    ser.write(str.encode(readdata_mqtt))
    time.sleep(1)
    readdata_uart=str(ser.readline())[2:]
    print(readdata_mqtt,readdata_uart[:-1])
    client.publish("MQTT/status" , readdata_uart[:-1])

 
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("192.168.11.18",1883,30)




while True:
    client.loop()
    c = str(ser.readline())
    if(c != 'b\'\''):
        print(c)
        payload = {'data' : c}
        client.publish("MQTT/status" , json.dumps(payload))
    time.sleep(1)
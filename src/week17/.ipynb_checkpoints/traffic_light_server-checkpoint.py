import smbus2 as smbus 
import paho.mqtt.client as mqtt
from time import sleep
from random import randrange, random, choice

# I2C 
I2C_ADDR = 11
PORT = 1
I2C = smbus.SMBus(PORT)

# LED-Control command
R0, R1 = 1, 2
Y0, Y1 = 3, 4
G0, G1 = 5, 6
BR, BY, BG = 11, 12, 13
R2G, G2R = 21, 22
CMDS = 200

# MQTT
TOPIC  = "P203-UNO"
BROKER = "broker.emqx.io"
PORT   = 1883
Client = None

# send LED-Control command to Arduino with parameters
# cmd : commands
# dat : additional parameters
def toArduino(cmd, dat=[]):
    global I2C
    bytes_msg = bytes(dat)
    print(f"  [I2C] To Arduino: {cmd}, {dat}")
    I2C.write_i2c_block_data(I2C_ADDR, cmd, bytes_msg)

# MQTT-Connected callback function 
def on_connect(client, userdata, flags, rc):
    global TOPIC
    print("Connected with result code "+str(rc))

# MQTT message retrieval callback function for the subscribed topics
def on_message(client, userdata, msg):
    topic = msg.topic
    payload = msg.payload.decode('utf-8')
    print(f"MQTT[{topic}] : {payload}")
    cmds = payload.split(',')
    try:
        if cmds[0]=='EXIT':
            client.disconnect()
        elif cmds[0]=='CMD':
            cmd = int(cmds[1])
            par = [int(c) for c in cmds[2:]]
            toArduino(cmd, par)
        elif cmds[0]=='CMDS':
            cmd = CMDS
            par = [int(c) for c in cmds[1:]]
            toArduino(cmd, par)
    except:
        print("Something wrong!")

# connect to MQTT broker
def connect_mqtt():
    global Client
    Client = mqtt.Client()
    Client.on_connect = on_connect
    Client.on_message = on_message
    Client.connect(BROKER, PORT, keepalive=60)
    Client.publish(topic=TOPIC, payload=None, retain=True)
    Ｃlient.subscribe(TOPIC)

# main loop
def main():
    global Client
    Client.loop_forever()

if __name__ == "__main__":
    connect_mqtt()
    main()
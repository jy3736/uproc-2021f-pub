import smbus2 as smbus 
from time import sleep
from random import randrange, random

I2C_ADDR = 11
PORT = 1
I2C = smbus.SMBus(PORT)

# LED-Control command
R0, R1 = 1, 2
Y0, Y1 = 3, 4
G0, G1 = 5, 6
CMDS = 200

# send LED-Control command to Arduino with parameters
# cmd : commands
# dat : additional parameters
def toArduino(cmd, dat=[]):
    global I2C
    bytes_msg = bytes(dat)
    print(f"{cmd} : {dat}")
    I2C.write_i2c_block_data(I2C_ADDR, cmd, bytes_msg)

def main(rep=10):    
    err = 0
    for i in range(rep):
        try:
            t=randrange(1,5)
            toArduino(randrange(21,22),[t,t,t,t])
            sleep(randrange(1,3))
            toArduino(randrange(11,13),[randrange(1,3)])
            sleep(randrange(1,3))
            for j in range(10):
                toArduino(200,[randrange(1,6) for _ in range(3)])
                sleep(0.5)
        except: 
            err = err+1
    toArduino(200,[2,4,6])
    sleep(2)
    toArduino(200,[1,3,5])
    print(f"\n\nerr = {err}")
    
if __name__=="__main__":
    main()
    
"""
Bluetooth utility, 2
Used to test connectivity to SMARS Bluetooth module
"""

import time
import serial

DELAY = 1
PORT = "/dev/tty.SMARS-SPPDev"
BLUETOOTH = serial.Serial(PORT, 9600, parity=serial.PARITY_NONE, stopbits=1)
time.sleep(DELAY)
print (BLUETOOTH)
print("connected")

my_input = ""

while my_input != 'q':
    my_input = input()
    BLUETOOTH.write(b'AT')
    time.sleep(DELAY)
    reply = BLUETOOTH.readline()
    print(reply)


# ser = serial.Serial('/dev/ttyUSB0')
# ser.write(b'sending string to Arduino')
# ser.close()

""" SMARS Bluetooth test utility """
import time
import serial
import yaml

DELAY = 0.25

def send_up():
    BLUETOOTH.write('u'.encode('ascii')) # up
    time.sleep(DELAY)
    BLUETOOTH.flush()

def send_down():
    BLUETOOTH.write('d'.encode('ascii')) # down
    time.sleep(DELAY)
    BLUETOOTH.flush()

def yaml_loader(filepath):
    with open(filepath, "r") as file_descriptor:
        data = yaml.load(file_descriptor, Loader=yaml.SafeLoader)
    return data

CONNECTED = False
print("Start")
# PORT = "/dev/tty.SMARS-SPPDev"
CONFIG_FILE = 'config.yml'
try:
    data = yaml_loader(CONFIG_FILE)
    PORT = data['smars']['bluetooth']
    print(f'Connecting to port { PORT }')

    BLUETOOTH = serial.Serial(PORT, 9600, parity=serial.PARITY_NONE, stopbits=1)
    time.sleep(DELAY)
    print (BLUETOOTH)
    print("connected")
    CONNECTED = True
except:
    print("Error connecting to Bluetooth port: " + PORT)

if CONNECTED:
    NB = "1"
    while NB != "q":
        time.sleep(0.1)
        NB = ""
        NB = input('WASD: ')
        NB = NB.strip()
        # print("Got: ", NB)
        if NB == "w":
            send_up()
        if NB == "s":
            send_down()
        if NB == "a":
            BLUETOOTH.write(bytes(b'l')) # left
        if NB == "d":
            BLUETOOTH.write(bytes(b'r')) # right
        if NB == "b":
            BLUETOOTH.write(bytes(b'b')) # buzz
        if NB == "u":
            # print("got U")
            BLUETOOTH.write(bytes(b'u')) # rangefind
            time.sleep(0.1)

            # distance = ""
            distance = BLUETOOTH.readline() # get distance in cm
            print(f"distance is: {distance}")

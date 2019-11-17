""" SMARS Bluetooth test utility """
import time
import serial
import yaml

DELAY = 0.25

def send_up():
    """ send up command """
    BLUETOOTH.write('u'.encode('ascii')) # up
    time.sleep(DELAY)
    BLUETOOTH.flush()

def send_down():
    """ send down command """
    BLUETOOTH.write('d'.encode('ascii')) # down
    time.sleep(DELAY)
    BLUETOOTH.flush()

def yaml_loader(filepath):
    """ load yaml file """
    with open(filepath, "r") as file_descriptor:
        data = yaml.load(file_descriptor, Loader=yaml.SafeLoader)
    return data

CONNECTED = False
print("Start")
# PORT = "/dev/tty.SMARS-SPPDev"
CONFIG_FILE = 'config.yml'

# try to load the yaml config file
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
        if NB == "w":
            send_up()
        if NB == "s":
            send_down()
        if NB == "a":
            # left
            BLUETOOTH.write(bytes(b'l'))
        if NB == "d":
            # right
            BLUETOOTH.write(bytes(b'r'))
        if NB == "b":
            # buzz
            BLUETOOTH.write(bytes(b'b'))
        if NB == "u":
            # rangefind
            BLUETOOTH.write(bytes(b'u'))
            time.sleep(0.1)

            # get distance in cm
            distance = BLUETOOTH.readline()
            print(f"distance is: {distance}")

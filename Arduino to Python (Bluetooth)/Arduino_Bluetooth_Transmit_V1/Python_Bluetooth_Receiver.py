# NOTES
#
# The two Bluetooth ports that show up on my desktop computer are COM8 and COM9
# Adjust the size variable to match the amount of data you intend to send. 
# Reading more than the required amount may result in blending two or more transmissions into one

import serial
import time

size = 20   # Number of bytes that the read function will read

ser = serial.Serial(port="COM8", baudrate=9600, timeout=1)

while(True):    
    s = ser.read(size)
    print(s)

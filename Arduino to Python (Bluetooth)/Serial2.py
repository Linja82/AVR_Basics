import serial

ser = serial.Serial(port="COM25", baudrate=9600, timeout=1)
ser.flushInput()

while True:

    ser_bytes = ser.readline()
    #decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
    print(ser_bytes)
#!/usr/bin/env python3

import sys, signal

# To install: `pip3 install python-can`
import can

# Before running this, I need to do: `sudo ip link set can0 up type can bitrate 1000000`

import time, threading

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    OFF = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def signal_handler(signal, frame):
    print("\nExiting..")
    pcan.cleanup()
    sys.exit(0)
signal.signal(signal.SIGINT, signal_handler)

def _get_message(msg):
    return msg

class PCANBus(object):

    def __init__(self):
        print("Initializing CANbus")
        self.bus = can.interface.Bus(bustype='socketcan', channel='can0', bitrate=1000000)
        self.buffer = can.BufferedReader()
        self.notifier = can.Notifier(self.bus, [self._get_message, self.buffer])

    def _get_message(self, msg):
        return msg

    def send(self, message):
        try:
            self.bus.send(message)
            return True
        except can.CanError:
            print("message not sent!")
            return False

    def receive(self):
        return self.buffer.get_message()

    def receiveOrNone(self):
        return self.buffer.get_message(timeout=0.0)

    def flush_buffer(self):
        msg = self.buffer.get_message()
        while (msg is not None):
            msg = self.buffer.get_message()

    def cleanup(self):

        self.notifier.stop()
        self.bus.shutdown()

pcan = PCANBus()

motor_command = -200
motor_command_bytes = motor_command.to_bytes(2, byteorder=sys.byteorder, signed=True)

print(f"Sending Messages...")

keeprunning = True
messages_sent = 0
msg = can.Message(arbitration_id=0x02B, is_extended_id=False, data=motor_command_bytes)

def send_message():
    global messages_sent, keeprunning
    pcan.send(msg)
    messages_sent = messages_sent + 1
    if keeprunning:
        threading.Timer(0.01, send_message).start()
    message = pcan.receiveOrNone()
    if message != None:
        if message.arbitration_id == 0x23 and message.dlc == 8:
            # Sysinfo Message
            firmware_version = (message.data[0] << 20) | (message.data[1] << 12) | (message.data[2] << 4) | (message.data[3] & 0xF0) >> 4;
            firmware_dirty = True if (message.data[3] & 0x0F) == 0x0F else False;
            temperature = message.data[4];
            if temperature > 60:
                temperature_colour = bcolors.WARNING
            else:
                temperature_colour = bcolors.OKGREEN
            can_esr_rx = message.data[6];
            if can_esr_rx > 0:
                can_esr_rx_colour = bcolors.WARNING
            else:
                can_esr_rx_colour = bcolors.OKGREEN
            can_esr_tx = message.data[7];
            if can_esr_tx > 0:
                can_esr_tx_colour = bcolors.WARNING
            else:
                can_esr_tx_colour = bcolors.OKGREEN

            print("FW: %07x%s, %sTemperature: %+3d°C%s, %sCAN RX Errors: %3d%s, %sCAN TX Errors: %3d%s" \
             % (firmware_version, "-dirty" if firmware_dirty else "-clean", \
                temperature_colour, temperature, bcolors.OFF, \
                can_esr_rx_colour, can_esr_rx, bcolors.OFF, \
                can_esr_tx_colour, can_esr_tx, bcolors.OFF))
        elif message.arbitration_id == 0x24 and message.dlc == 8:
            # Motor info Message
            speed_commanded = int.from_bytes([message.data[0], message.data[1]], byteorder='little', signed=True)
            voltage = int.from_bytes([message.data[2], message.data[3]], byteorder='little', signed=False)
            current = int.from_bytes([message.data[4], message.data[5]], byteorder='little', signed=True)
            ms_since_last_command = message.data[6]
            print(voltage)

            print("Speed: %+4d, Voltage: %.3f, Current: %+.3f, milliseconds since last: %d" \
             % (speed_commanded, \
                (voltage*1.25) / 1000.0, \
                (current*1.25) / 1000.0, \
                ms_since_last_command))

send_message()

time.sleep(5)

print(f"Stopping...")
keeprunning = False
time.sleep(1)
print(f"Sent {messages_sent} messages.")

pcan.cleanup()
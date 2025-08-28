#!/usr/bin/env python3

"""
Detect STM32 serial port with retry (Linux & Windows).
- On Linux/WSL2: looks for /dev/ttyUSB* or /dev/ttyACM*
- On Windows: uses PySerial to list COM ports
- Retries up to 10 seconds
- Prints the detected port (to stdout)
"""

import sys
import time
import platform
import glob

try:
    import serial.tools.list_ports
except ImportError:
    print("PySerial is required. Install with: pip install pyserial", file=sys.stderr)
    sys.exit(1)


def detect_linux():
    """Detect /dev/ttyUSB* or /dev/ttyACM* devices."""
    ports = glob.glob("/dev/ttyUSB*") + glob.glob("/dev/ttyACM*")
    return ports[0] if ports else None


def detect_windows():
    """Detect COMx devices using PySerial."""
    # for p in serial.tools.list_ports.comports():
    #     print(p)
    ports = [p.device for p in serial.tools.list_ports.comports()]
    return ports[0] if ports else None


def main():
    osname = platform.system().lower()
    port = None

    for i in range(10):  # retry up to 10s
        if "windows" in osname:
            port = detect_windows()
        else:
            port = detect_linux()

        if port:
            print(port)
            return 0

        print(f"[INFO] Waiting for STM32 serial port... ({i+1}/10)", file=sys.stderr)
        time.sleep(1)

    print("❌ STM32 serial port not found after 10s", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())

#!/usr/bin/env python3

"""
detect_serial_port.py - Cross-platform serial port detection script

This script detects available serial ports and prints the first matching port.

Usage:
    # Get the first available serial port (default)
    python detect_serial_port.py
    # Output example (Windows): COM5
    # Output example (Linux): /dev/ttyUSB0

    # Search for a port by keyword in its description (case-insensitive)
    python detect_serial_port.py STM32
    # Output example: COM7
    # Only prints a port whose description contains "STM32"

Exit codes:
    0 - Serial port found and printed
    1 - No matching serial port found
"""

import sys
import platform
from serial.tools import list_ports


def find_serial_port(keyword=None):
    ports = list(list_ports.comports())
    if not ports:
        return None

    system = platform.system()

    if keyword:
        keyword = keyword.lower()
        for port in ports:
            if system == "Windows":
                # Check device, description, manufacturer, and hwid
                desc = f"{port.device} {port.description} {port.hwid} {port.manufacturer} {port.product}".lower()
            else:
                # Linux/macOS: check device and description
                desc = f"{port.device} {port.description} {port.hwid} {port.manufacturer} {port.product}".lower()

            if keyword in desc:
                return port.device
        return None
    else:
        return ports[0].device


if __name__ == "__main__":
    keyword = sys.argv[1] if len(sys.argv) > 1 else None
    port = find_serial_port(keyword)
    if port:
        print(port)
    else:
        sys.stderr.write("No matching serial port found.\n")
        sys.exit(1)

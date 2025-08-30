#!/usr/bin/env python3

"""
STM32 Commands Runner
----------------------

This script connects to an STM32F4 board via a serial port, reads a list of
commands from an input file, sends them one by one over UART, and logs the
responses from the board into a log file.

- Input file: plain text file with one command per line.
- Output log file: defaults to the input file name but with `.log` extension
  (can be overridden with `-o`).
- Each command and response pair is printed to the console AND logged
  (with timestamps) for traceability.
- Supports appending logs instead of overwriting via `--append`.

Behavior Update:
- Multi-line responses are fully captured until a line containing "OK" or "ERROR"
  is received, then the function returns.
"""

import serial
import time
import logging
import argparse
from pathlib import Path


def send_command(ser: serial.Serial, cmd: str, max_wait: float = 5.0) -> list[str]:
    """Send a single command and wait for response (max_wait seconds)."""
    if not cmd.endswith("\n"):
        cmd += "\n"

    ser.write(cmd.encode())
    time.sleep(0.1)

    response_lines = []
    start_time = time.time()
    while True:
        line = ser.readline().decode(errors="ignore").strip()
        if line:
            print(f"[RAW] {line}")
            print(f"> {cmd.strip()} | < {line}")
            logging.info(f"CMD: {cmd.strip()} | RESP: {line}")
            response_lines.append(line)
            if "OK" in line or "ERROR" in line:
                break
        if time.time() - start_time > max_wait:
            print(f"⚠ Timeout waiting for response to '{cmd.strip()}'")
            logging.warning(f"Timeout waiting for response to '{cmd.strip()}'")
            break
        time.sleep(0.05)
    return response_lines


def parse_args() -> argparse.Namespace:
    """Parse command-line arguments."""
    parser = argparse.ArgumentParser(description="STM32 UART Test Runner")
    parser.add_argument(
        "-p", "--port", required=True, help="Serial port (e.g., COM3, /dev/ttyUSB0)"
    )
    parser.add_argument(
        "-f", "--file", required=True, help="Input file with commands (one per line)"
    )
    parser.add_argument(
        "-b", "--baudrate", type=int, default=115200, help="Baud rate (default: 115200)"
    )
    parser.add_argument(
        "-o",
        "--output",
        default=None,
        help="Optional log file name (default: same as input file but .log extension)",
    )
    parser.add_argument(
        "--append",
        action="store_true",
        help="Append to existing log instead of overwriting",
    )
    return parser.parse_args()


def setup_logging(
    input_file: str, output: str | None = None, append: bool = False
) -> Path:
    """Configure logging system and return the resolved log file path."""
    log_file: Path = Path(output) if output else Path(input_file).with_suffix(".log")
    logging.basicConfig(
        filename=log_file,
        filemode="a" if append else "w",
        level=logging.INFO,
        format="%(asctime)s [%(levelname)s] %(message)s",
    )
    return log_file


def main() -> None:
    """Main execution flow."""
    args = parse_args()
    log_file: Path = setup_logging(args.file, args.output, args.append)

    try:
        with serial.Serial(args.port, args.baudrate, timeout=1) as ser:
            time.sleep(2)  # Allow time for STM32 reset

            print(f"Connected to STM32F4 on {args.port} @ {args.baudrate} baud")
            logging.info("=== Starting STM32 Unit Test Session ===")

            commands: list[str] = [
                line.strip() for line in open(args.file) if line.strip()
            ]

            for cmd in commands:
                send_command(ser, cmd)

            logging.info("=== Test session completed ===")
            print(f"Logs saved to {log_file}")

    except FileNotFoundError:
        print(f"Error: Command file '{args.file}' not found.")
    except serial.SerialException as e:
        print(f"Serial error: {e}")
        logging.error(f"Serial error: {e}")


if __name__ == "__main__":
    main()

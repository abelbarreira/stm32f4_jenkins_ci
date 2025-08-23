# Connect to USB based serial ports

- Linux uses `ttySx` for a serial port device name.
  - For example, COM1 (DOS/Windows name) is `ttyS0`, COM2 is `ttyS1`, and so on.
  - USB based serial ports might use a name such as `ttyACM0`.
  - All these devices are located under /dev/ directory.

- `dmesg | grep tty`
- `dmesg | grep -i serial`
- `sudo dmesg | more`
- `lsusb`
- `lsusb -v -s 010`
- `dmesg | grep -i tty`
- `openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "init; reset init; exit"`

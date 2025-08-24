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

## About UART for Unit Testing Unity results

Using a FTDI USB to TTL Serial Converter Adapter, for example `FT232RL`, connect to the emualtion board as for:

- PA2 (TX from STM32) → RXD on FTDI
- PA3 (RX on STM32) ← TXD on FTDI
- GND shared

Then connect the USB to the PC and check:

- `dmesg | grep tty`:
  - `FTDI USB Serial Device converter now attached to ttyUSB0`
- `lsusb`:
  - `Bus 003 Device 020: ID 0403:6001 Future Technology Devices International, Ltd FT232 Serial (UART) IC`

Then connect a serial terminal (e.g., PuTTY, minicom) setting **115200 8N1**.

#!/bin/bash

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo

# My USB TTL is Future Technology Devices International, Ltd FT232 Serial (UART) IC

SERIAL_PORT=$(./scripts/detect_serial_port.py FTDI | tr -d '\r\n')
echo "Detected serial port: $SERIAL_PORT"

./scripts/stm32_commands_runner.py -p $SERIAL_PORT -f ./stm32f4_prj/tests/run_test_commands.txt -b 115200

popd > /dev/null

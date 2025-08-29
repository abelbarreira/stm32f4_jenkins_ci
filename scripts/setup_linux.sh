#!/bin/bash

set -e

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo "=== Updating package lists ==="
sudo apt update --assume-yes && sudo apt upgrade

echo "=== Installing build tools (make, gcc, g++) ==="
sudo apt install --assume-yes build-essential

echo "=== Installing ARM GCC Toolchain (arm-none-eabi-gcc) ==="
sudo apt install --assume-yes gcc-arm-none-eabi binutils-arm-none-eabi gdb-multiarch gdb-arm-none-eabi

echo "=== Installing OpenOCD ==="
sudo apt install --assume-yes openocd

echo "=== Cleaning ==="
sudo apt clean
sudo apt autoclean
sudo apt autoremove

echo "=== Done! ==="
echo
echo "Versions installed:"

make --version | head -n 1
arm-none-eabi-gcc --version | head -n 1
gdb-multiarch --version | head -n 1
openocd --version | head -n 1

popd > /dev/null

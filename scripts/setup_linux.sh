#!/bin/bash
set -e

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo "=== Updating package lists ==="
sudo apt update
sudo apt upgrade

echo "=== Installing build tools (make, gcc, g++) ==="
sudo apt install -y build-essential

echo "=== Installing ARM GCC Toolchain (arm-none-eabi-gcc) ==="
sudo apt install -y gcc-arm-none-eabi binutils-arm-none-eabi gdb-multiarch
# sudo apt install -y gcc-arm-none-eabi gdb-arm-none-eabi

echo "=== Installing OpenOCD ==="
sudo apt install -y openocd

echo "=== Done! ==="
echo
echo "Versions installed:"

make --version | head -n 1
arm-none-eabi-gcc --version | head -n 1
gdb-multiarch --version | head -n 1
openocd --version | head -n 1

popd > /dev/null

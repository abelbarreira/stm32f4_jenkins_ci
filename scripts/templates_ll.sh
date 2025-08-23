#!/bin/bash

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo
echo "🔎 Adding STM32CubeF4 MCU Firmware Package submodule..."
git submodule add -b master --depth=1 https://github.com/STMicroelectronics/STM32CubeF4 templates/stm32f4_disc
cd templates/stm32f4_disc
# Enable sparse checkout (delete content)
git sparse-checkout init --cone
# Pick only the folders needed (checkout only those)
git sparse-checkout set Projects/STM32F4-Discovery/Templates_LL

popd > /dev/null

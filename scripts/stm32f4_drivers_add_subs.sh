#!/bin/bash

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo "🔎 Adding STM32CubeF4 CMSIS Device MCU Component submodule..."
git submodule add -b master --depth=1 https://github.com/STMicroelectronics/cmsis-device-f4 stm32f4_prj/drivers/cmsis/device

echo
echo "🔎 Adding CMSIS Version 5 submodule..."
git submodule add -b develop --depth=1 https://github.com/ARM-software/CMSIS_5 stm32f4_prj/drivers/cmsis/core
cd stm32f4_prj/drivers/cmsis/core
# Enable sparse checkout (delete content)
git sparse-checkout init --cone
# Pick only the folders needed (checkout only those)
git sparse-checkout set CMSIS/Core/Include
cd -

echo
echo "🔎 Adding STM32CubeF4 HAL Driver MCU Component..."
git submodule add -b master --depth=1 https://github.com/STMicroelectronics/stm32f4xx-hal-driver stm32f4_prj/drivers/stm32f4xx-hal-driver

popd > /dev/null

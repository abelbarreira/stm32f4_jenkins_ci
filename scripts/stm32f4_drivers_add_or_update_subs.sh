#!/bin/bash

# -----------------------------------------------------------------------------
# This script sets up required Git submodules for the STM32F4 project.
# It adds or initializes/update submodules for:
#   - STM32CubeF4 CMSIS Device
#   - ARM CMSIS v5 (with sparse-checkout of CMSIS/Core/Include)
#   - STM32CubeF4 HAL Driver
#
# If a submodule already exists in .gitmodules, it will be updated instead
# of re-added. Designed to be run from any location within the repository.
# -----------------------------------------------------------------------------

set -e

SCRIPT_DIR="$(dirname "$0")"
ROOT_DIR="$SCRIPT_DIR/.."

pushd "$ROOT_DIR" > /dev/null

add_or_update_submodule() {
    local repo_url=$1
    local path=$2
    local branch=$3

    if grep -q "$path" .gitmodules 2>/dev/null; then
        echo "✅ Submodule $path already exists. Initializing/updating..."
        git submodule update --init --recursive "$path"
    else
        echo "➕ Adding submodule $path..."
        git submodule add -b "$branch" --depth=1 "$repo_url" "$path"
    fi
}

echo "🔎 Adding STM32CubeF4 CMSIS Device MCU Component..."
add_or_update_submodule https://github.com/STMicroelectronics/cmsis-device-f4 stm32f4_prj/drivers/cmsis/device master

echo
echo "🔎 Adding CMSIS Version 5..."
add_or_update_submodule https://github.com/ARM-software/CMSIS_5 stm32f4_prj/drivers/cmsis/core develop

pushd stm32f4_prj/drivers/cmsis/core > /dev/null
# Enable sparse checkout (delete content)
git sparse-checkout init --cone
# Pick only the folders needed (checkout only those)
git sparse-checkout set CMSIS/Core/Include
popd > /dev/null

echo
echo "🔎 Adding STM32CubeF4 HAL Driver MCU Component..."
add_or_update_submodule https://github.com/STMicroelectronics/stm32f4xx-hal-driver stm32f4_prj/drivers/stm32f4xx-hal-driver master

popd > /dev/null

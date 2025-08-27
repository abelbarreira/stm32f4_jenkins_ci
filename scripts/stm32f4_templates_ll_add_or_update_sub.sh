#!/bin/bash

# -----------------------------------------------------------------------------
# This script sets up the STM32CubeF4 MCU Firmware Package as a Git submodule
# for the STM32F4 project. It adds or initializes/updates the submodule under
# "templates/stm32f4_disc", then configures sparse-checkout so that only the
# "Projects/STM32F4-Discovery/Templates_LL" folder is checked out.
# -----------------------------------------------------------------------------

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

add_or_update_submodule() {
    local repo_url=$1
    local path=$2
    local branch=$3

    if grep -q "$path" .gitmodules 2>/dev/null; then
        echo "✅ Submodule $path already exists. Initializing/updating..."
        git submodule update --init "$path" # not needed --recursive here
    else
        echo "➕ Adding submodule $path..."
        git submodule add -b "$branch" --depth=1 "$repo_url" "$path"
    fi
}

echo
echo "🔎 Adding STM32CubeF4 MCU Firmware Package submodule..."
add_or_update_submodule https://github.com/STMicroelectronics/STM32CubeF4 templates/stm32f4_disc master

pushd templates/stm32f4_disc > /dev/null
# Enable sparse checkout (delete content)
git sparse-checkout init --cone
# Pick only the folders needed (checkout only those)
git sparse-checkout set Projects/STM32F4-Discovery/Templates_LL
popd > /dev/null

# # Sparse clone without submodules
# git clone --filter=blob:none --sparse https://github.com/STMicroelectronics/STM32CubeF4 templates/stm32f4_disc
# pushd templates/stm32f4_disc
#
# # Checkout the specific release tag
# git fetch --tags
# git checkout tags/v1.28.3
#
# # Enable sparse-checkout for only the folder you need
# git sparse-checkout init --cone
# git sparse-checkout set Projects/STM32F4-Discovery/Templates_LL
#
# popd

popd > /dev/null

#!/bin/bash
# -----------------------------------------------------------------------------
# This script sets up the Unity test framework as a Git submodule
# for the STM32F4 project. It adds or initializes/updates the Unity
# submodule, then configures sparse-checkout so that only the "src/"
# folder is checked out to keep the working tree minimal.
# -----------------------------------------------------------------------------

set -e

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

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

echo
echo "🔎 Adding Unity..."
add_or_update_submodule https://github.com/ThrowTheSwitch/Unity stm32f4_prj/tests/unity master

pushd stm32f4_prj/tests/unity > /dev/null
# Enable sparse checkout (delete content)
git sparse-checkout init --cone
# Pick only the folders needed (checkout only those)
git sparse-checkout set src/
popd > /dev/null

popd > /dev/null

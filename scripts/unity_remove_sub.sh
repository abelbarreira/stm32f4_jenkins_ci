#!/bin/bash

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo

# Remove the entry from .gitmodules
git submodule deinit -f stm32f4_prj/tests/unity

# Remove the entry from .git/config
git rm -f stm32f4_prj/tests/unity

# Remove leftover files (optional, just in case)
rm -rf .git/modules/stm32f4_prj/tests/unity

popd > /dev/null

#!/bin/bash

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo

# Remove the entry from .gitmodules
git submodule deinit -f stm32f4_prj/drivers/cmsis/device

# Remove the entry from .git/config
git rm -f stm32f4_prj/drivers/cmsis/device

# Remove leftover files (optional, just in case)
rm -rf .git/modules/stm32f4_prj/drivers/cmsis/device

echo

# Remove the entry from .gitmodules
git submodule deinit -f stm32f4_prj/drivers/cmsis/core

# Remove the entry from .git/config
git rm -f stm32f4_prj/drivers/cmsis/core

# Remove leftover files (optional, just in case)
rm -rf .git/modules/stm32f4_prj/drivers/cmsis/core

echo

# Remove the entry from .gitmodules
git submodule deinit -f stm32f4_prj/drivers/stm32f4xx-hal-driver

# Remove the entry from .git/config
git rm -f stm32f4_prj/drivers/stm32f4xx-hal-driver

# Remove leftover files (optional, just in case)
rm -rf .git/modules/stm32f4_prj/drivers/stm32f4xx-hal-driver

# Remove the entry from .gitmodules
git submodule deinit -f templates/stm32f4_disc

# Remove the entry from .git/config
git rm -f templates/stm32f4_disc

# Remove leftover files (optional, just in case)
rm -rf .git/modules/templates/stm32f4_disc

popd > /dev/null

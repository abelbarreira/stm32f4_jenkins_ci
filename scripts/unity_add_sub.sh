#!/bin/bash

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo
echo "🔎 Adding Unity Test submodule..."
git submodule add -b master --depth=1 https://github.com/ThrowTheSwitch/Unity stm32f4_prj/tests/unity
cd stm32f4_prj/tests/unity
# Enable sparse checkout (delete content)
git sparse-checkout init --cone
# Pick only the folders needed (checkout only those)
git sparse-checkout set src/
cd -

popd > /dev/null

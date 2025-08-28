#!/bin/bash

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo

./scripts/stm32_commands_runner.py -p /dev/ttyUSB0 -f ./stm32f4_prj/tests/run_test_commands.txt -b 115200

popd > /dev/null

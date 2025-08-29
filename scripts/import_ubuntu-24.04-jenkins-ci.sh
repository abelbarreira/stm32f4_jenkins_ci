#!/bin/bash

# Define the distribution name.
dist_name=ubuntu-24.04-jenkins-ci

SCRIPT_DIR=`dirname $0`

# Check if wsl is installed.
if ! wsl --version > /dev/null ; then
    echo
    echo "Windows Subsystem for Linux (WSL) is not installed."
    echo "Refer to https://git.mee-spn.com/unisoc-tee-sim/setup/setup-environment/-/wikis/wsl"
    exit
fi

pushd $SCRIPT_DIR > /dev/null

# Check if tar file is created.
if [ ! -f "../$dist_name.tar" ]; then
    echo
    echo "$dist_name.tar file doesnt exist."
    echo "Please follow README.md steps to create the file."
    exit
fi

# Check if the distribution is installed.
if ! wsl --list --verbose | iconv -f UTF-16LE -t UTF-8 | grep -E "(^|[[:space:]])$dist_name(\$|[[:space:]])" > /dev/null ; then
    echo
    echo "Importing distribution $dist_name..."
    wsl --shutdown
    wsl --set-default-version 2
    wsl --import $dist_name c:/Users/$USERNAME/AppData/Local/Packages/$dist_name ./../$dist_name.tar --version 2
    wsl --setdefault $dist_name
else
   echo "$dist_name was already installed."
fi

popd > /dev/null

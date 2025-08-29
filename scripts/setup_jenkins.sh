#!/bin/bash
set -e

# =========================================================
# Setup Jenkins on Ubuntu (best practices, stable repo)
# =========================================================

SCRIPT_DIR=`dirname $0`
ROOT_DIR=$SCRIPT_DIR/..

pushd $ROOT_DIR > /dev/null

echo "[INFO] Updating system..."
sudo apt update --assume-yes && sudo apt upgrade

echo "[INFO] Installing Java (required by Jenkins)..."
sudo apt install --assume-yes fontconfig openjdk-17-jre

echo "[INFO] Adding Jenkins repo and key..."
curl -fsSL https://pkg.jenkins.io/debian-stable/jenkins.io-2023.key | sudo tee \
  /usr/share/keyrings/jenkins-keyring.asc > /dev/null
echo deb [signed-by=/usr/share/keyrings/jenkins-keyring.asc] \
  https://pkg.jenkins.io/debian-stable binary/ | sudo tee \
  /etc/apt/sources.list.d/jenkins.list > /dev/null

echo "[INFO] Installing Jenkins..."
sudo apt update --assume-yes
sudo apt install --assume-yes jenkins

echo "[INFO] Enabling and starting Jenkins service..."
sudo systemctl enable jenkins
sudo systemctl start jenkins

echo "[INFO] Jenkins status:"
sudo systemctl status jenkins --no-pager

echo
echo "========================================================="
echo " Jenkins installed! "
echo
echo " Access it in your browser: http://localhost:8080"
echo
echo " To get the initial admin password, run:"
echo "   sudo cat /var/lib/jenkins/secrets/initialAdminPassword"
echo
echo "========================================================="

popd > /dev/null

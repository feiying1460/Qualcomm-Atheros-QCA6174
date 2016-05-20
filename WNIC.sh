#!/usr/bin/env bash

cd backports-20150731/ && \
sudo make defconfig-ath10k && \
sudo make install && \
cd ../ath10k-firmware-master/ && \
sudo cp -R ath10k/ /lib/firmware && \
sudo bash -c 'echo "options ath10k_core skip_otp=y" > /etc/modprobe.d/ath10k.conf' && \
sudo reboot

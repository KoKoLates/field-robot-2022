#! /usr/bin/bash

sudo apt update
sudo apt-get update
python_version=`python --version 2>&1|awk '{print $2}'|awk -F '.' '{print $1}'`

if (! $python_version); then
    echo "[ERROR] No python installed."
    sudo apt install python3 -y
fi

if ($python_version == 3); then
    echo "The python version is 3"
elif ($python_version == 2); then
    echo "The python version is 2"
fi

pip install python-opencv opencv-contrib -y
pip install numpy
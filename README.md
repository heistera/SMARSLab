# SMARSLab
![Build Status](https://travis-ci.org/kevinmcaleer/SMARSLab.svg?branch=master)

SMARS Lab - A simple web app for playing with SMARS Robots.

# Contents
 - [Install](to-install)
 - [New Configuration File](#new-configuration-file)

---

[](#To-Install)
[To Install](#to-install):
* log on to your raspberry pi
* clone the SMARS Lab github repository:
 `git clone https://www.github.com/kevinmcaleer/SMARSLab`
* change to the SMARSLab directory:
 `cd SMARSLab`
* install virtualenv:
 `pip install virtualenv`
 or
 'sudo apt-get install virtualenv'
* create a new virtual python environment:
`virtualenv -p python3 venv`
* activate the new python environment:
`source venv/bin/activate`
* install the pre-requisites:
`pip install -r requirements.txt`
* load SMARSLab:
`python smarslab.py`
* Open a webbrowser at:
either `http://localhost:5000` or `http://raspberrypi-IP-ADDRESS:5000`
* Enjoy!

 ---

# [New Configuration file](#new-configuration-file)
There is a new configuration file `config.yml` that can be used to set specific options for SMARS Lab. The options available are:
- [x] bluetooth: <path to bluetooth device
- [x] name: "<name of smars>"]

# ERRATA
Had to remove support for Python 3.3 as Flask is not compatible with this version.

# Arduino Bluetooth control
## version 1.3
// September 2019 - troubleshooting bluetooth control
- fixed bluetooth control - use pins 2 & 3 and setup software serial for arduino
## version 1.2
// September 2019 - troubleshooting bluetooth control
## Version 1.1
// May 2019 - added buzzer feature
// Requires a Fundomoto sheild

## Version 1.0
- Basic control commands
- known issue with commands not being received correctly


## S.H.O.U.T
(Screen Hardware Output Usecase Test)
This project is intended as a simple exploratory hello world project for interacting with an i2c display, using a compound of (for me) at the moment interesting techniques.


#### Project goals
Produce output on a lcd display.

#### Setup

###### Build host
tbd

###### Target hardware
- raspberry pi 3
- adafruit i2c 16x2 lcd pi plate

#### Build the software
command to compile:
g++ -std=c++11 displayHello.cpp

the typedefs uint8_t (defined in <cstdint> header) are part of c++11 standard.

This should be incorporated into a yocto build setup. (todo)

#### Deploy on target
building via yocto produces an image file. This file is written to an sd card.
(more documentation to be added as the process matures)

###### Running software
When the raspberry pi is booted, you must login. Currently the only existing user is root, with root as password. Next you need to activate the i2c kernel modulewith the command 'modprobe i2c-dev'
After this you can use the i2-tools (which are installed by default).
To find the address of the display, type
'i2cdetect 1' this will show the memory mapping of the i2c bus number 1.

To run the shout test program run 'helloworld_display'
This will light up the display.
 

###### Todo's
- find a good way to build and produce the source
- read in and understand how the bristolwatch code (using wiringPi) works.
- based on this knowledge, create my own interfacing source code.

This should enable me to write out text to the display.
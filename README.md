
## S.H.O.U.T
(Screen Hardware Outpu Usecase Test)
This project is intended as a simple exploratory hello world project for interacting with an i2c display, using a compound of (for me) at the moment interesting techniques.


#### Project goals
 


#### Setup

###### Build host

###### Target hardware

#### Build the software
command to compile:
g++ -std=c++11 displayHello.cpp

the typedefs uint8_t (defined in <cstdint> header) are part of c++11 standard.


#### Deploy on target

###### Running software
When the raspberry pi is booted, you must login. Currently the only existing user is root, with root as password. Next you ned to activate the i2c kernel modulewith the command 'modprobe i2c-dev'
After this you can use the i2-tools (which are installed by default).
To find the address of the display, type
'i2cdetect 1' this will show the memory mapping of the i2c bus number 1.

To run the shout test program run 'helloworld_display'
This will light up the display.
 

###### Todo's
- port source code to this repository
- find a good way to build and produce the source
- read in and understand how the bristolwatch code (using wiringPi) works.
- based on this knowledge, create my own interfacing source code.

This should enable me to write out text to the display.
# libdht
Abstraction of the Adafruit DHT11/22 Python accessor

# Usage

include "dht_read.c"

Link your application to libdhtsensor.so

dht_read(char *pin, int type, float *, float *)

pin is a string representing the BBB pin you are using
type is either DHT11 or DHT22
The two float pointers are to store humidity and temperature as measured

It returns 0 on succes, and < 0 on an error

# About
This library is created using the original C code from Adafruit. They use
python as the interface, but the C code works for C/C++ just as well.

Right now, it only works with a BeagleBone Black, but I will port it to
Raspberry PI when I get the chance. It would work fine for a RPI, but 
it does some PIN figuring out based on the BBB, so that's the restriction.

You must run as root. The original code makes some assumptions about
how GPIO works, due to how you read and write using a memory map and timings.
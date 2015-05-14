# libdht
Abstraction of the Adafruit DHT11/22 Python accessor

# Usage

dht_read(char *pin, int type, float *, float *)

pin is a string representing the BBB pin you are using
type is either DHT11 or DHT22
The two float pointers are to store humidity and temperature as measured

It returns 0 on succes, and < 0 on an error
 
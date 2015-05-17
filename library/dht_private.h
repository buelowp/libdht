/*
 // Copyright (c) 2014 Adafruit Industries
// Author: Tony DiCola

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// Simple fast memory-mapped GPIO library for the Beaglebone Black.
// Allows reading and writing GPIO at very high speeds, up to ~2.6mhz!

/*
  // Example usage:

  #include <stdio.h>
  #include "bbb_mmio.h"

  int main(int argc, char* argv[]) {
    // Get GPIO pin.
    // See the giant table of of pins in the system reference manual for details
    // on the base and number for a given GPIO:
    //  https://github.com/CircuitCo/BeagleBone-Black/blob/master/BBB_SRM.pdf?raw=true
    // Section 7 Connectors, table 12 shows P8_11 maps to GPIO1_13, so 1 is the
    // gpio base and 13 is the gpio number.
    gpio_t p8_11;
    if (bbb_mmio_get_gpio(1, 13, &p8_11) < 0) {
      printf("Couldn't get requested GPIO pin!\n");
      return 1;
    }
    // Set pin as output.
    bbb_mmio_set_output(p8_11);
    // Toggle the pin high and low as fast as possible.
    // This generates a signal at about 2.6mhz in my tests.
    // Each pulse high/low is only about 200 nanoseconds long!
    while (1) {
      bbb_mmio_set_high(p8_11);
      bbb_mmio_set_low(p8_11);
    }
    return 0;
  }

*/

#ifndef LIBRARY_DHT_PRIVATE_H_
#define LIBRARY_DHT_PRIVATE_H_

#include <stdint.h>

// Define errors and return values.
#define DHT_ERROR_TIMEOUT -1
#define DHT_ERROR_CHECKSUM -2
#define DHT_ERROR_ARGUMENT -3
#define DHT_ERROR_GPIO -4
#define DHT_SUCCESS 0

// Define sensor types.
#define DHT11 11
#define DHT22 22
#define AM2302 22

int bbb_dht_read(int type, int gpio_base, int gpio_number, float* humidity, float* temperature);
int dht_read(char *pin, int type, float *humidity, float *temperature);

// Busy wait delay for most accurate timing, but high CPU usage.
// Only use this for short periods of time (a few hundred milliseconds at most)!
void busy_wait_milliseconds(uint32_t millis);

// General delay that sleeps so CPU usage is low, but accuracy is potentially bad.
void sleep_milliseconds(uint32_t millis);

// Increase scheduling priority and algorithm to try to get 'real time' results.
void set_max_priority(void);

// Drop scheduling priority back to normal/default.
void set_default_priority(void);

#define MMIO_SUCCESS 0
#define MMIO_ERROR_ARGUMENT -1
#define MMIO_ERROR_DEVMEM -2
#define MMIO_ERROR_MMAP -3

#define MMIO_OE_ADDR 0x134
#define MMIO_GPIO_DATAOUT 0x13C
#define MMIO_GPIO_DATAIN 0x138
#define MMIO_GPIO_CLEARDATAOUT 0x190
#define MMIO_GPIO_SETDATAOUT 0x194

// Define struct to represent a GPIO pin based on its base memory address and number.
typedef struct {
  volatile uint32_t* base;
  int number;
} gpio_t;

int bbb_mmio_get_gpio(int base, int number, gpio_t* gpio);

static inline void bbb_mmio_set_output(gpio_t gpio) {
  gpio.base[MMIO_OE_ADDR/4] &= (0xFFFFFFFF ^ (1 << gpio.number));
}

static inline void bbb_mmio_set_input(gpio_t gpio) {
  gpio.base[MMIO_OE_ADDR/4] |= (1 << gpio.number);
}

static inline void bbb_mmio_set_high(gpio_t gpio) {
  gpio.base[MMIO_GPIO_SETDATAOUT/4] = 1 << gpio.number;
}

static inline void bbb_mmio_set_low(gpio_t gpio) {
  gpio.base[MMIO_GPIO_CLEARDATAOUT/4] = 1 << gpio.number;
}

static inline uint32_t bbb_mmio_input(gpio_t gpio) {
  return gpio.base[MMIO_GPIO_DATAIN/4] & (1 << gpio.number);
}


#endif /* LIBRARY_DHT_PRIVATE_H_ */

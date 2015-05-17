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

// Created by Peter Buelow on May 15, 2015

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "dhtdaemon.h"

#include "../library/bbb_dht.h"

int run_daemon(char *pin, int type)
{
    int shmid;
    int rval;
    dht22 *values;
    float humidity = 0.0;
    float temperature = 0.0;

    memset(&values, 0, sizeof(dht22));

    /*
     * Create the segment.
     */
    if ((shmid = shmget(DHT22_KEY, sizeof(dht22), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((values = shmat(shmid, NULL, 0)) == (void*) -1) {
        perror("shmat");
        exit(1);
    }

    while (1) {
    	if ((rval = dht_read(pin, type, &humidity, &temperature)) == DHT_SUCCESS) {
    		values->humidity = humidity;
    		values->temperature = temperature;
    		values->mutex = MUTEX_VALID;
    		fprintf(stdout, "%s: humidity=%f, temperature=%f\n", __FUNCTION__, humidity, temperature);
    		sleep(3);
    	}
    	else {
    		fprintf(stderr, "%s: dht_read returned %d\n", __FUNCTION__, rval);
    		sleep(1);
    	}
    }
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage: %s <gpio pin> <sensor type>\n", argv[0]);
		fprintf(stderr, "where <gpio pin> is something like P9_12\n");
		fprintf(stderr, "and <sensor type> is 11 or 22\n");
		exit(1);
	}

	run_daemon(argv[1], atoi(argv[2]));
	return 0;
}

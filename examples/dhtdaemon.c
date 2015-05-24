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
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <errno.h>
#include <signal.h>

#include "../library/bbb_dht.h"

/**
 * \func int run_daemon(char *pin, int type)
 * \param pin BBB Pin to attach to
 * \param type Is this an 11 or 22
 * \returns No return
 * Loop forever reading values from the sensor and
 * store them to the shared memory area. Anyone can
 * read them.
 */
void run_daemon(char *pin, int type)
{
    int shmid;
    int rval;
    dht22 *values;
    float humidity = 0.0;
    float temperature = 0.0;

    openlog("dhtdaemon", LOG_ODELAY, LOG_USER);

    if ((shmid = shm_open(DHT_MEM_SEGMENT, O_CREAT|O_RDWR, 0666)) < 0) {
    	syslog(LOG_ERR, "Daemon exiting: %s(%d)", strerror(errno), errno);
    	exit(-1);
    }

    ftruncate(shmid, sizeof(dht22));

    if ((values = (dht22*)mmap (0, sizeof(dht22), PROT_READ|PROT_WRITE, MAP_SHARED, shmid, 0)) == MAP_FAILED) {
    	syslog(LOG_ERR, "Daemon exiting: %s(%d)", strerror(errno), errno);
    	closelog();
    	exit(-1);
    }

    memset(values, 0, sizeof(dht22));

    while (1) {
    	if ((rval = dht_read(pin, type, &humidity, &temperature)) == DHT_SUCCESS) {
    		values->humidity = humidity;
    		values->temperature = temperature;
    		values->mutex = MUTEX_VALID;
    		sleep(3);
    	}
    	else {
    		sleep(1);
    	}
    }
}

int main(int argc, char *argv[])
{
    pid_t pid;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <gpio pin> <sensor type>\n", argv[0]);
		fprintf(stderr, "where <gpio pin> is something like P9_12\n");
		fprintf(stderr, "and <sensor type> is 11 or 22\n");
		exit(1);
	}

	signal(SIGCHLD, SIG_IGN);
	signal(SIGHUP, SIG_IGN);

	/* Fork off the parent process */
	pid = fork();
	if (pid < 0) {
		perror("fork");
		return -1;
	}
	else if (pid == 0) {
		run_daemon(argv[1], atoi(argv[2]));
	}
	else {
		fclose(stderr);
		fclose(stdout);
		fclose(stdin);
	}
    return 0;
}

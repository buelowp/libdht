/*
 * dhtdaemon.h
 *
 *  Created on: May 15, 2015
 *      Author: pete
 */

#ifndef EXAMPLES_DHTDAEMON_H_
#define EXAMPLES_DHTDAEMON_H_

#define DHT22_KEY	4567
#define MUTEX_VALID	1
#define MUTEX_INVALID -1

typedef struct {
	int mutex;
	float humidity;
	float temperature;
} dht22;

#endif /* EXAMPLES_DHTDAEMON_H_ */

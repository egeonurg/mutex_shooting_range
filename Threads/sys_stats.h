/*
 * statistics.h
 *
 *  Created on: Mar 10, 2023
 *      Author: egeonurg
 */

#ifndef SYS_STATS_H_
#define SYS_STATS_H_
#include "stdint.h"

#include "sys_threads.h"

typedef struct
{
	uint32_t semaphore_received;
	uint32_t mutex_receive_failed;
	uint32_t mutex_receive_success;
	uint32_t mutex_release_success;
}stat_type_t;

extern stat_type_t system_statistics[NUMBER_OF_THREADS];

#endif /* SYS_STATS_H_ */

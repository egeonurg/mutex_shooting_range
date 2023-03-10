/*
 * mutex.h
 *
 *  Created on: Mar 9, 2023
 *      Author: egeonurg
 */

#ifndef MUTEX_H_
#define MUTEX_H_
#include <pthread.h>
#include "mutex.h"

#define PTHREAD_MUTEX 0

void lock_init();

void unlock_mutex(int other);

extern char flag[2];
extern char turn ;

#if PTHREAD_MUTEX
extern pthread_mutex_t lock_mutex;

#else
void lock_mutex(int other);
#endif

#endif /* MUTEX_H_ */

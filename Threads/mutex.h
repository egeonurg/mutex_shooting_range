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

#define PTHREAD_MUTEX  0
#define PETERSON_MUTEX 1

#define MUTEX_ALGORITHM   PETERSON_MUTEX

#if MUTEX_ALGORITHM == PTHREAD_MUTEX
extern pthread_mutex_t lock;

#else
void lock_init();
void lock(int self);
void unlock(int self);
#endif

#endif /* MUTEX_H_ */

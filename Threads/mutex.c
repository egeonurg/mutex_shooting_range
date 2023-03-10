/*
 * mutex_algorithm.c
 *
 *  Created on: Mar 9, 2023
 *      Author: egeonurg
 */

#include "system.h"
#include "mutex.h"
#include <assert.h>
#include <stdio.h>

#if MUTEX_ALGORITHM == PTHREAD_MUTEX
#else

int flag[2] = {0};
int turn = 0 ;

void lock_init()
{
    // Initialize lock by resetting the desire of
    // both the threads to acquire the locks.
    // And, giving turn to one of them.
    flag[0] = flag[1] = MUTEX_UNLOCKED;
    turn = 0;
}

// Executed before entering critical section
void lock(int self)
{
    // Set flag[self] = 1 saying you want to acquire lock
    flag[self] = MUTEX_LOCKED;

    // But, first give the other thread the chance to
    // acquire lock
    turn = 1-self;

    // Wait until the other thread looses the desire
    // to acquire lock or it is your turn to get the lock.
    while (flag[1-self]== MUTEX_LOCKED && turn == 1-self)
    {
    	printf("thread %d is waiting !\n", self);
    }
}

// Executed after leaving critical section
void unlock(int self)
{
    // You do not desire to acquire lock in future.
    // This will allow the other thread to acquire
    // the lock.
	printf("thread %d has ran !\n", self);
    flag[self] = MUTEX_UNLOCKED;
}

#endif

/*
 * mutex_algorithm.c
 *
 *  Created on: Mar 9, 2023
 *      Author: egeonurg
 */

#include "system.h"
#include "mutex.h"


char flag[2] = {0};
char turn = 0;


void lock_init()
{
    // They are reset by resetting their preference to acquire locks. This is done by giving one of them a turn.
    flag[0] = flag[1] = 0;
    turn = 0;
}

// function for locking Petersons Algorithm

void lock_mutex(int other)
{
    flag[other] = 1;  // Marking this thread wants to enter the critical section
    turn = 1 - other; // Assuming that the order thread has priority
    while (flag[1 - other] == 1 && turn == 1 - other);
}
#if PTHREAD_MUTEX

#else
#endif

// Method for unlocking Petersonbs algorithm

void unlock_mutex(int other)
{
    flag[other] = 0; // Marking that this thread is no longer wants to enter the critical section
}



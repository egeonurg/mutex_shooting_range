/*
 * mutex_algorithm.c
 *
 *  Created on: Mar 9, 2023
 *      Author: egeonurg
 */

#include "mutex.h"
#include <assert.h>
#include <stdio.h>

#include "sys_stats.h"

#if MUTEX_ALGORITHM == PTHREAD_MUTEX


#else

int flag[2] = {0};
int turn = 0 ;
mutex_lock_t thread_mutex_status[2] = {0};
//long long run_counter[2] = {0};
//long long busy_counter[2] = {0};

void peterson_mutex_init()
{
    // Initialize lock by resetting the desire of
    // both the threads to acquire the locks.
    // And, giving turn to one of them.
    flag[0] = flag[1] = MUTEX_UNLOCKED;
    turn = 0;
}

// Executed before entering critical section
void peterson_mutex_lock(uint8_t self, uint8_t id)
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
    	printf("i am suffering on %d  as %d \n", self, id);

    	system_statistics[id].mutex_receive_failed ++;
    }
	system_statistics[id].mutex_receive_success ++;

	printf("i got mutex %d  as %d \n", self, id);
}

// Executed after leaving critical section
void peterson_mutex_unlock(uint8_t self, uint8_t id)
{
    // You do not desire to acquire lock in future.
    // This will allow the other thread to acquire
    // the lock.
	//run_counter[self] ++ ;
    flag[self] = MUTEX_UNLOCKED;
	system_statistics[id].mutex_release_success ++;

    printf("i am going out of %d as %d \n", self, id);
}

#endif

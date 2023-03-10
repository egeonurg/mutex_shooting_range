// Filename: peterson_spinlock.c
// Use below command to compile:
// gcc -pthread peterson_spinlock.c -o peterson_spinlock

#include <stdio.h>
#include <pthread.h>
#include "thread_fct.h"
#include <assert.h>

mutex_lock_t thread_mutex_status[2] = {0};

void* x1_write()
{
	int self = PROCESSOR_X1;
	while(1)
	{
	    lock(self);
		thread_mutex_status[self] = MUTEX_LOCKED;
	    // Critical section (Only one thread
		_SYS_CHECK_MUTEX_OWNERS();
	    // can enter here at a time)
		thread_mutex_status[self] = MUTEX_UNLOCKED;
	    unlock(self);
	    sleep(1);
	}
}


void* x1_read()
{
	int self = PROCESSOR_X1 ;
	while(1)
	{
	   // printf("Thread Entered: %d\n", self);

	    lock(self);
		thread_mutex_status[self] = MUTEX_LOCKED;
	    // Critical section (Only one thread
		_SYS_CHECK_MUTEX_OWNERS();
	    // can enter here at a time)
		thread_mutex_status[self] = MUTEX_UNLOCKED;
	    unlock(self);
	    sleep(1);

	}
}

void* x2_write()
{
	int self = PROCESSOR_X2;
	while(1)
	{
	    lock(self);
		thread_mutex_status[self] = MUTEX_LOCKED;
	    // Critical section (Only one thread
		_SYS_CHECK_MUTEX_OWNERS();
	    // can enter here at a time)
		thread_mutex_status[self] = MUTEX_UNLOCKED;
	    unlock(self);
	    sleep(1);

	}
}


void* x2_read()
{
	int self = PROCESSOR_X2 ;
	while(1)
	{
	   // printf("Thread Entered: %d\n", self);

	    lock(self);
		thread_mutex_status[self] = MUTEX_LOCKED;
	    // Critical section (Only one thread
		_SYS_CHECK_MUTEX_OWNERS();
	    // can enter here at a time)
		thread_mutex_status[self] = MUTEX_UNLOCKED;
	    unlock(self);
	    sleep(1);

	}
}


// Driver code
int main()
{
    // Initialized the lock then fork 2 threads
    pthread_t p1, p2,p3,p4;
    lock_init();

    // Create two threads (both run func)
    pthread_create(&p1, NULL, x1_write, (void*)0);
    pthread_create(&p2, NULL, x1_read, (void*)0);
    pthread_create(&p3, NULL, x2_write, (void*)0);
    pthread_create(&p4, NULL, x2_read, (void*)0);

    // Wait for the threads to end.
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    return 0;
}

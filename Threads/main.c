/*
 * main.c
 *
 *  Created on: Mar 9, 2023
 *      Author: egeonurg
 */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "mutex.h"
#include "system.h"
#include "thread_fct.h"

#if PTHREAD_MUTEX
pthread_mutex_t lock;
#else

#endif
mutex_lock_t thread_mutex_status[NUMBER_OF_PROCESSORS] = {0};

int main()
{
#if PTHREAD_MUTEX
	  if (pthread_mutex_init(&lock, NULL) != 0) {
	        printf("\n mutex init has failed\n");
	        return 1;
	    }
#else
	  lock_init();
#endif

	pthread_t threads[NUMBER_OF_PROCESSORS][NUMBER_OF_OPERATIONS]= {0};

	pthread_create(&threads[PROCESSOR_X1][READ_OPERATION] , NULL, (void*)&x1_read_function ,	NULL);
	pthread_create(&threads[PROCESSOR_X1][WRITE_OPERATION], NULL, (void*)&x1_write_function,	NULL);
	pthread_create(&threads[PROCESSOR_X2][READ_OPERATION] , NULL, (void*)&x2_read_function ,	NULL);
	pthread_create(&threads[PROCESSOR_X2][WRITE_OPERATION], NULL, (void*)&x2_write_function,	NULL);

	pthread_join(threads[PROCESSOR_X1][READ_OPERATION],NULL);
	pthread_join(threads[PROCESSOR_X1][WRITE_OPERATION],NULL);
	pthread_join(threads[PROCESSOR_X2][READ_OPERATION],NULL);
	pthread_join(threads[PROCESSOR_X2][WRITE_OPERATION],NULL);

}


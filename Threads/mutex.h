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
#include "stdint.h"

enum
{
	PROCESSOR_X1,
	PROCESSOR_X2,
	NUMBER_OF_PROCESSORS
};
enum
{
	READ_OPERATION,
	WRITE_OPERATION,
	NUMBER_OF_OPERATIONS
};

typedef enum
{
	MUTEX_UNLOCKED,
	MUTEX_LOCKED
}mutex_lock_t;

#define PTHREAD_MUTEX  0
#define PETERSON_MUTEX 1

#define MUTEX_ALGORITHM   PETERSON_MUTEX

#if MUTEX_ALGORITHM == PTHREAD_MUTEX
extern pthread_mutex_t peterson_mutex_lock;

#else
void peterson_mutex_init();
void peterson_mutex_lock(uint8_t self, uint8_t id);
void peterson_mutex_unlock(uint8_t self, uint8_t id);
#endif

extern mutex_lock_t thread_mutex_status[2] ;

#define _SYS_PRINT_ALL_MUTEX_STATUS()   	printf("SYSTEM FAILURE ! ");                                \
											printf("[PROCESSOR_X1]  = %d   ",thread_mutex_status[0]);   \
											printf("[PROCESSOR_X2]  = %d \n",thread_mutex_status[1]);


#define _SYS_CHECK_MUTEX_OWNERS() 	       if(thread_mutex_status[0]== MUTEX_LOCKED && \
									         thread_mutex_status[1] == MUTEX_LOCKED )\
											{\
												_SYS_PRINT_ALL_MUTEX_STATUS();\
												assert(0);\
											};\

#define _SYSMASTER_CHECK_MUTEX_OWNERS() 	if(thread_mutex_status[0] != MUTEX_UNLOCKED && \
									    	   thread_mutex_status[1] != MUTEX_UNLOCKED ) \
											{\
												_SYS_PRINT_ALL_MUTEX_STATUS();\
												assert(0);\
											};\



#endif /* MUTEX_H_ */

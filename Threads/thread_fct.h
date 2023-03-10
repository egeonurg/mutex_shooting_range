/*
 * thread_fct.h
 *
 *  Created on: Mar 9, 2023
 *      Author: egeonurg
 */

#ifndef THREAD_FCT_H_
#define THREAD_FCT_H_
#include <assert.h>
#include "mutex.h"
#include "system.h"
#include "thread_fct.h"

void x1_read_function(void);
void x1_write_function(void);
void x2_read_function(void);
void x2_write_function(void);

extern mutex_lock_t thread_mutex_status[NUMBER_OF_PROCESSORS];

#define _SYS_PRINT_ALL_MUTEX_STATUS()   	printf("SYSTEM FAILURE ! ");                                         \
											printf("[PROCESSOR_X1]  = %d   ",thread_mutex_status[0]);   \
											printf("[PROCESSOR_X2]  = %d \n",thread_mutex_status[1]);


#define _SYS_CHECK_MUTEX_OWNERS() 	 if(thread_mutex_status[0]== MUTEX_LOCKED && \
									    thread_mutex_status[1] == MUTEX_LOCKED )\
											{\
												_SYS_PRINT_ALL_MUTEX_STATUS();\
												assert(0);\
											};\

#endif /* THREAD_FCT_H_ */

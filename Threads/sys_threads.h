/*
 * threads.h
 *
 *  Created on: May 9, 2022
 *      Author: ege
 */

#ifndef SYS_THREADS_H_
#define SYS_THREADS_H_

#include <semaphore.h>


#define NUMBER_OF_THREADS            (4)

	typedef struct
	{
	  unsigned int id;
	  unsigned int nodes[2];
	}mst_thread_type_t;


void slave_thread0_func (void *p);
void slave_thread1_func (void *p);
void slave_thread2_func (void *p);
void slave_thread3_func (void *p);
void master_thread_func (void *p);

extern sem_t sem_thread0, sem_thread1,sem_thread2, sem_thread3;
extern sem_t sem_master0, sem_master1, sem_master2, sem_master3;
extern pthread_t slave_thread0, slave_thread1, slave_thread2, slave_thread3, master_thread;

#endif /* SYS_THREADS_H_ */

/*
 * main.c
 *
 *  Created on: Mar 7, 2022
 *      Author: ege
 */

#include <sched.h>
#include <unistd.h>
#include <pthread.h>
#include "mutex.h"
#include "sys_threads.h"

int main()
{

	peterson_mutex_init();

	/* Semaphores for the slave tasks, which synchronizes it to the master */

	sem_init(&sem_thread0, 0, 0);
	sem_init(&sem_thread1, 0, 0);
	sem_init(&sem_thread2, 0, 0);
	sem_init(&sem_thread3, 0, 0);

	/* Semaphores for the master task, which synchronizes master task to the end of slave task events */
	sem_init(&sem_master0, 0, 1);
	sem_init(&sem_master1, 0, 1);
	sem_init(&sem_master2, 0, 1);
	sem_init(&sem_master3, 0, 1);

    pthread_create( &slave_thread0, NULL, (void*)&slave_thread0_func, NULL);
    pthread_create( &slave_thread1, NULL, (void*)&slave_thread1_func, NULL);
    pthread_create( &slave_thread2, NULL, (void*)&slave_thread2_func, NULL);
    pthread_create( &slave_thread3, NULL, (void*)&slave_thread3_func, NULL);
    pthread_create( &master_thread, NULL, (void*)&master_thread_func, NULL);

	pthread_join(master_thread,NULL);
	pthread_join(slave_thread0,NULL);
	pthread_join(slave_thread1,NULL);
	pthread_join(slave_thread2,NULL);
	pthread_join(slave_thread3,NULL);

	while(1)
		{

		}
}

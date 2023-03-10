/*
 * threads.c
 *
 *  Created on: May 9, 2022
 *      Author: ege
 */

#include "sys_threads.h"

#include <stdio.h>
#include <assert.h>
#include "mutex.h"
#include "stdint.h"

#include "sys_stats.h"

pthread_t slave_thread0, slave_thread1, slave_thread2, slave_thread3, master_thread;
sem_t sem_thread0, sem_thread1, sem_thread2, sem_thread3;
sem_t sem_master0, sem_master1, sem_master2, sem_master3;

void master_sem_wait_all(void)
	{
		sem_wait(&sem_master0);
		sem_wait(&sem_master1);
		sem_wait(&sem_master2);
		sem_wait(&sem_master3);
	}

void master_sem_post_all(void)
	{
		sem_post(&sem_thread0);
		sem_post(&sem_thread1);
		sem_post(&sem_thread2);
		sem_post(&sem_thread3);
	}

void slave_thread0_func(void *p)
	{
		uint8_t thread_id = 0 ;

		while(1)
			{
		        sem_wait(&sem_thread0);
		        system_statistics[thread_id].semaphore_received ++;

		        peterson_mutex_lock(0,thread_id);
		        _SYS_CHECK_MUTEX_OWNERS();
		        peterson_mutex_unlock(0,thread_id);

		        sem_post(&sem_master0);
			}

		pthread_exit(NULL);
	}

void slave_thread1_func(void *p)
	{
		uint8_t thread_id = 1 ;

		while(1)
			{
		        sem_wait(&sem_thread1);
		        system_statistics[thread_id].semaphore_received ++;

		        peterson_mutex_lock(0,thread_id);
		        _SYS_CHECK_MUTEX_OWNERS();
		        peterson_mutex_unlock(0,thread_id);

		        sem_post(&sem_master1);
			}

		pthread_exit(NULL);
	}

void slave_thread2_func(void *p)
	{
		uint8_t thread_id = 2 ;

		while(1)
			{
		        sem_wait(&sem_thread2);
		        system_statistics[thread_id].semaphore_received ++;

		        peterson_mutex_lock(1,thread_id);
		        _SYS_CHECK_MUTEX_OWNERS();
		        peterson_mutex_unlock(1,thread_id);

			    sem_post(&sem_master2);
			}

		pthread_exit(NULL);
	}

void slave_thread3_func(void *p)
	{
		uint8_t thread_id = 3;

		while(1)
			{
		        sem_wait(&sem_thread3);
		        system_statistics[thread_id].semaphore_received ++;

		        peterson_mutex_lock(1,thread_id);
		        _SYS_CHECK_MUTEX_OWNERS();
		        peterson_mutex_unlock(1,thread_id);

		        sem_post(&sem_master3);
			}

		pthread_exit(NULL);
	}

void master_thread_func(void *p)

	{
		while (1)
			{
				master_sem_wait_all();
		        _SYSMASTER_CHECK_MUTEX_OWNERS();
				master_sem_post_all();
			}

		pthread_exit(NULL);
	}

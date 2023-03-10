
#include <stdio.h>
#include <assert.h>
#include "mutex.h"
#include "system.h"
#include "thread_fct.h"



void x1_read_function(void)
{
//	while(1)
//	{
//#if PTHREAD_MUTEX
//		 pthread_mutex_lock(&lock)	;	//MUTEX_LOCK(PROCESSOR_X1);
//
//#else
//		 lock_mutex(PROCESSOR_X1);
//#endif
//		 thread_mutex_status[PROCESSOR_X1] = MUTEX_LOCKED;
//
//		/* Do * whatever
//		 * you * want
//		 * in * here
//		 */
//
//		 _SYS_CHECK_MUTEX_OWNERS();
//		thread_mutex_status[PROCESSOR_X1] = MUTEX_UNLOCKED;
//
//#if PTHREAD_MUTEX
//	    pthread_mutex_unlock(&lock);
//
//#else
//	    unlock(PROCESSOR_X1);
//#endif
//	 }
}

void x1_write_function(void)
{
	while(1)
	{
#if PTHREAD_MUTEX
		 pthread_mutex_lock(&lock)	;	//MUTEX_LOCK(PROCESSOR_X1);

#else
		 lock_mutex(PROCESSOR_X1);
#endif
		thread_mutex_status[PROCESSOR_X1]= MUTEX_LOCKED;
		/* Do * whatever
		 * you * want
		 * in * here
		 */
		_SYS_CHECK_MUTEX_OWNERS() ;

		thread_mutex_status[PROCESSOR_X1]= MUTEX_UNLOCKED;

#if PTHREAD_MUTEX
	    pthread_mutex_unlock(&lock);

#else
	    unlock_mutex(PROCESSOR_X1);
#endif
	}
}

void x2_read_function(void)
{
//	while(1)
//	{
//#if PTHREAD_MUTEX
//		 pthread_mutex_lock(&lock)	;	//MUTEX_LOCK(PROCESSOR_X1);
//
//#else
//		 lock_mutex(PROCESSOR_X2);
//#endif
//		 thread_mutex_status[PROCESSOR_X2]= MUTEX_LOCKED;
//		/* Do * whatever
//		 * you * want
//		 * in * here
//		 */
//		printf("i am running btch x2_read_function\n");
//		_SYS_CHECK_MUTEX_OWNERS() ;
//
//		thread_mutex_status[PROCESSOR_X2] = MUTEX_UNLOCKED;
//
//#if PTHREAD_MUTEX
//	    pthread_mutex_unlock(&lock);
//
//#else
//	    unlock(PROCESSOR_X2);
//#endif
//	}
}

void x2_write_function(void)
{
	while(1)
	{
#if PTHREAD_MUTEX
		 pthread_mutex_lock(&lock)	;	//MUTEX_LOCK(PROCESSOR_X1);

#else
		 lock_mutex(PROCESSOR_X2);
#endif
		 thread_mutex_status[PROCESSOR_X2]= MUTEX_LOCKED;
		/* Do
		 * whatever
		 * you
		 * want
		 * in
		 * here
		 * */
		 _SYS_CHECK_MUTEX_OWNERS();
	    thread_mutex_status[PROCESSOR_X2] = MUTEX_UNLOCKED;
#if PTHREAD_MUTEX
	    pthread_mutex_unlock(&lock);

#else
	    unlock_mutex(PROCESSOR_X2);
#endif
	    }
}

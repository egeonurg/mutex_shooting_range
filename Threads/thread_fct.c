//
//#include <stdio.h>
//#include <assert.h>
//#include "mutex.h"
//#include "system.h"
//#include "thread_fct.h"
//
//
//
//void x1_read_function(void)
//{
//	while(1)
//	{
////#if MUTEX_ALGORITHM == PTHREAD_MUTEX
////		 pthread_mutex_lock(&lock)	;	//MUTEX_LOCK(PROCESSOR_X1);
////#else
////		 lock(PROCESSOR_X1);
////#endif
////		 thread_mutex_status[PROCESSOR_X1] = MUTEX_LOCKED;
////
////		/* Do * whatever
////		 * you * want
////		 * in * here
////		 */
////
////		 _SYS_CHECK_MUTEX_OWNERS();
////		thread_mutex_status[PROCESSOR_X1] = MUTEX_UNLOCKED;
////
////#if MUTEX_ALGORITHM == PTHREAD_MUTEX
////	    pthread_mutex_unlock(&lock);
////#else
////	    unlock(PROCESSOR_X1);
////#endif
//	 }
//}
//
//void x1_write_function(void)
//{
//	while(1)
//	{
//#if MUTEX_ALGORITHM == PTHREAD_MUTEX
//		 pthread_mutex_lock(&lock)	;	//MUTEX_LOCK(PROCESSOR_X1);
//#else
//		 lock_mutex(0);
//#endif
//		thread_mutex_status[0]= 1;
//		/* Do * whatever
//		 * you * want
//		 * in * here
//		 */
//		printf("i am running x1_write_function \n");
//
//		if ((thread_mutex_status[0] == 1) && (thread_mutex_status[1] == 1) )
//		{
//			//_SYS_PRINT_ALL_MUTEX_STATUS();
//			//assert(0);
//		}
//
//		thread_mutex_status[0]= 0;
//
//#if MUTEX_ALGORITHM == PTHREAD_MUTEX
//	    pthread_mutex_unlock(&lock);
//#else
//	    unlock_mutex(0);
//#endif
//	}
//}
//
//void x2_read_function(void)
//{
////	while(1)
////	{
////#if MUTEX_ALGORITHM == PTHREAD_MUTEX
////		 pthread_mutex_lock(&lock)	;	//MUTEX_LOCK(PROCESSOR_X1);
////#else
////		 lock(PROCESSOR_X2);
////#endif
////		 thread_mutex_status[PROCESSOR_X2]= MUTEX_LOCKED;
////		/* Do * whatever
////		 * you * want
////		 * in * here
////		 */
////		 _SYS_CHECK_MUTEX_OWNERS() ;
////		thread_mutex_status[PROCESSOR_X2] = MUTEX_UNLOCKED;
////
////#if MUTEX_ALGORITHM == PTHREAD_MUTEX
////	    pthread_mutex_unlock(&lock);
////#else
////	    unlock(PROCESSOR_X2);
////#endif
////	}
//}
//
//void x2_write_function(void)
//{
//	while(1)
//	{
//#if MUTEX_ALGORITHM == PTHREAD_MUTEX
//		 pthread_mutex_lock(&lock)	;	//MUTEX_LOCK(PROCESSOR_X1);
//#else
//		 lock_mutex(1);
//#endif
//		 thread_mutex_status[1]= 1;
//		/* Do
//		 * whatever
//		 * you
//		 * want
//		 * in
//		 * here
//		 * */
//		 printf("i am running x2_write_function \n");
//
//			if ((thread_mutex_status[0] == 1	)&& (thread_mutex_status[1] == 1) )
//			{
//				//_SYS_PRINT_ALL_MUTEX_STATUS();
//				//assert(0);
//			}
//
//			thread_mutex_status[1] = 0;
//#if MUTEX_ALGORITHM == PTHREAD_MUTEX
//	    pthread_mutex_unlock(&lock);
//#else
//	    unlock_mutex(1);
//#endif
//	    }
//}

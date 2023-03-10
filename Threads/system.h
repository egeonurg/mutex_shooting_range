/*
 * system.h
 *
 *  Created on: Mar 9, 2023
 *      Author: egeonurg
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

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

#endif /* SYSTEM_H_ */

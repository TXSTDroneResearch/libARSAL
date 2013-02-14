/**
 * @file libARSAL/ARSAL_Sem.h
 * @brief This file contains headers about semaphore abstraction layer
 * @date 12/27/2012
 * @author nicolas.brulez@parrot.com
 */
#ifndef _ARSAL_SEM_H_
#define _ARSAL_SEM_H_

#include <time.h>

/**
 * @brief Define a semaphore type.
 */
typedef void* ARSAL_Sem_t;

/**
 * @brief Initializes a semaphore.
 *
 * @param sem The semaphore to initialize
 * @param shared Flag asking for a multi-process shared semaphore
 * @param value Initial value of the semaphore
 * @retval On success, ARSAL_Sem_init() returns 0. Otherwise, it returns -1 and set errno (See errno.h)
 */
int ARSAL_Sem_Init(ARSAL_Sem_t *sem, int shared, int value);

/**
 * @brief Destroys a semaphore
 *
 * @param sem The sem to destroy
 * @retval On success, ARSAL_Sem_destroy() returns 0. Otherwise, it returns -1 and set errno (See errno.h)
 */
int ARSAL_Sem_Destroy(ARSAL_Sem_t *sem);

/**
 * @brief Wait for a semaphore
 *
 * @param sem The sem to wait for
 * @retval On success, ARSAL_Sem_wait() returns 0. Otherwise, it returns -1 and set errno (See errno.h)
 */
int ARSAL_Sem_Wait(ARSAL_Sem_t *sem);

/**
 * @brief Non blocking wait for a semaphore
 *
 * @param sem The sem to wait for
 * @retval If the semaphore was successfully decremented, ARSAL_Sem_trywait() returns 0. If the call would have blocked, it returns -1 and sets errno to "EAGAIN". On any other error, return -1 and set errno (See errno.h)
 */
int ARSAL_Sem_Trywait(ARSAL_Sem_t *sem);

/**
 * @brief Wait for a semaphore with a timeout
 *
 * @param sem The sem to wait for
 * @param timeout Maximum time to wait
 * @warning POSIX.1-2001 semaphore use an absolute time as timeout. Instead, libSAL use a relative time !
 * @retval If the semaphore was sucessfully decremented, ARSAL_Sem_timedwait() returns 0. If the call has timed-out, it returns -1 and sets errno to "ETIMEDOUT". On any other error, return -1 and set errno (See errno.h)
 */
int ARSAL_Sem_Timedwait(ARSAL_Sem_t *sem, const struct timespec *timeout);

/**
 * @brief Increment a semaphore
 *
 * @param sem The semaphore to increment
 * @retval On success, ARSAL_Sem_post() returns 0. Otherwise, it returns -1 and set errno (See errno.h)
 */
int ARSAL_Sem_Post(ARSAL_Sem_t *sem);

/**
 * @brief Get the current value of a semaphore
 *
 * @param sem The semaphore to get value from
 * @param value Pointer which will hold the current value of the semaphore
 * @retval On success, ARSAL_Sem_getvalue() returns 0. Otherwise, it returns -1 and set errno (See errno.h)
 */
int ARSAL_Sem_Getvalue(ARSAL_Sem_t *sem, int *value);

#endif // _ARSAL_SEM_H_


#ifndef __SVR_LOCKABLE_H
#define __SVR_LOCKABLE_H

#include <pthread.h>

/**
 * \addtogroup Lockable
 * \{
 */

/** Define an object type as lockable */
#define SVR_LOCKABLE pthread_mutex_t __svr_lock

/** Get a reference to the underlying lock of the given object */
#define SVR_GET_LOCK(object) (&((object)->__svr_lock))

/** Initialize the a lockable object */
#define SVR_LOCKABLE_INIT(object) (pthread_mutex_init(SVR_GET_LOCK(object), &__svr_lockable_recursive))

/** Lock the object */
#define SVR_LOCK(object) (pthread_mutex_lock(SVR_GET_LOCK(object)))

/** Perform a conditional wait using the objects lock as the mutex */
#define SVR_LOCK_WAIT(object, cond) (pthread_cond_wait((cond), SVR_GET_LOCK(object)))

/** Unlock the object */
#define SVR_UNLOCK(object) (pthread_mutex_unlock(SVR_GET_LOCK(object)))

/** \} */

#ifndef __SVR_LOCKABLE_C
extern pthread_mutexattr_t __svr_lockable_recursive;
#endif // #ifndef __SVR_LOCKABLE_C

void SVR_Lockable_initMutexAttributes(void);

#endif // #ifndef __SVR_LOCKABLE_H

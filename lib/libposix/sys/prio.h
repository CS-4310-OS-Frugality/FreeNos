#ifndef __LIBPOSIX_PRIO_H
#define __LIBPOSIX_PRIO_H

#include <Macros.h>
#include "types.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libposix
 * @{
 */

/**
 * @brief Set the priority of a process
 *
 * @param pid Process ID of process to set priority.
 * @param priority New priority to set for the process.
 * @param options Optional flags.
 *
 * @return Process ID of the process on success or -1 on error
 */
extern C pid_t setprio(pid_t pid, unsigned int priority, int options);

/**
 * @}
 * @}
 */

#endif /* __LIBPOSIX_PRIO_H */

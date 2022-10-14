#include "unistd.h"
#include "sys/types.h"
#include <FreeNOS/User.h>
#include <errno.h>

pid_t renice(pid_t pid, unsigned int priority){

    ProcessInfo *info = new ProcessInfo();
    info->priority = priority;

    const ulong result = (ulong) ProcessCtl(pid, SetPrioPID, (Address) &info);

    switch ((const API::Result) (result & 0xffff))
    {
        case API::NotFound:
            errno = ESRCH;
            return (pid_t) -1;

        case API::Success:
            return pid;

        default:
            errno = EIO;
            return (pid_t) -1;
    }
}
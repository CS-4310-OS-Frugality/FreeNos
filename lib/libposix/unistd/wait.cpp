#include <FreeNOS/User.h>
#include <Timer.h>
#include "unistd.h"
#include "errno.h"

unsigned int wait(ProcessID id)
{
    // Wait until the timer expires
    if (ProcessCtl(id, WaitPID) != API::Success)
    {
        errno = EIO;
        return id;
    }

    // Done
    return 0;
}
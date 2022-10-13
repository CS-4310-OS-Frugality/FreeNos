#include "unistd.h"
#include "sys/types.h"
#include <FreeNOS/User.h>

void renice(pid_t pid, unsigned int priority){
    const ulong result = (ulong) ProcessCtl(pid, SetPrioPID);
}
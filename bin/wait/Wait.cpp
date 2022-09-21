#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Wait.h"
#include <Types.h>
#include <unistd.h>

Wait::Wait(int argc, char **argv): POSIXApplication(argc, argv){
    parser().setDescription("Wait until another process finishes execution");
    parser().registerPositional("process_id", "ProcessID of the Process to wait for");
}

Wait::~Wait(){
}

Wait::Result Wait::exec(){
    ProcessID id = 0;

    if ((id = atoi(arguments().get("process_id"))) <= 0)
    {
        ERROR("invalid process id `" << arguments().get("process_id") << "'");
        return InvalidArgument;
    }

    // Sleep now
    if (wait(id) != 0)
    {
        ERROR("failed to sleep: " << strerror(errno));
        return IOError;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Wait.h"
#include <Types.h>
#include "sys/wait.h"

Wait::Wait(int argc, char **argv): POSIXApplication(argc, argv){
    parser().setDescription("Wait until another process finishes execution");
    parser().registerPositional("process_id", "ProcessID of the Process to wait for");
}

Wait::~Wait(){
}

Wait::Result Wait::exec(){
    pid_t id = 0;
    int status;

    if ((id = atoi(arguments().get("process_id"))) < 0)
    {
        ERROR("invalid process id `" << arguments().get("process_id") << "'");
        return InvalidArgument;
    }

    if (waitpid(id, &status, 0) != id)
    {
        ERROR("failed to wait: " << strerror(errno));
        return IOError;
    }
}
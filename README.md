# Project 3: Prioritize It
==========================

This branch adds in priority levels to processes. The base priority for each newly created process is level 3

In order to look at the process levels, use the command
```
  $ ps -l
```

In order to change a priority level of a process, use the command
```
  $ renice [-n] priorityLevel PID
```
The flag -n is optional when using renice. Please ensure that the priority level you are changing to is within 1-5

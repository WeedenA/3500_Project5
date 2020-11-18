#ifndef _CMDINPUT_H_
#define _CMDINPUT_H_

#define MAX_TASK_ARRAY 32

typedef unsigned int uInt;

typedef struct task {
  uInt pid;
  uInt arrivalTime;
  uInt burstTime;
  uInt startTime;
  uInt finTime;
  uInt resTime;
  uInt tatTime;
  uInt waitTime;
  uInt quantumTime;
}task_t;

void openFile (int argc, char *argv[], int *size, task_t taskArray[]);


#endif

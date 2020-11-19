/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  cmdinput.h
 *  Dr. Qin's provided starter code "scheduler.h" used as reference
 *  no other outside references used.
 */
#ifndef _CMDINPUT_H_
#define _CMDINPUT_H_

#define MAX_TASK_ARRAY 32

typedef unsigned int uInt;

/*
 *  Task struct initially populated in cmdinput.c
 *  After simulation, analysis.c analyzes wait/tat/response time
 */
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
  uInt origBurst;
  uInt exitTime;
}task_t;

/*
  prototype of function in cmdinput.c
*/
int openFile (FILE **fileDes, char *name, char *argv[], int *size, task_t taskArray[]);


#endif

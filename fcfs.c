/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  fcfs.c
 *  High-level generalized algorithm in Exercise 2, slide 15 of ppt for Lecture 29 used
 *  No outside reference was used for specific code/implementations
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* file includes */
#include "scheduler.h"
#include "cmdinput.h"

/*
 *  Simulates a CPU Scheduler using First Come First Serve
 *  Task arrivals are continuously monitored to determine readiness
 *  Burst times are stored for analysis then decremented as the process gets CPU time
 *  start and finish times are populated
 */
void fcfsRun (task_t tasks[], int size) {
  uInt clock = 0;
  uInt i = 0;
  uInt q = 0;

  int readyQ[size];
  int finishQ[size];
  int done = 0;

  while (done != 1) {
    /* Evaluate task readiness */
    if (i < size) {
      if (!(tasks[i].arrivalTime > clock)) {
        readyQ[i] = 1;
        i++;
      }
    }
    /* first time task gets resources */
    if (readyQ[q] == 1) {
      tasks[q].startTime = clock;
      tasks[q].origBurst = tasks[q].burstTime;
      readyQ[q] = 2;
    }
    /* Every time task gets resources */
    if (readyQ[q] == 2) {
      printf("<time %u> process %u is running\n", clock, tasks[q].pid);
      tasks[q].burstTime--;
      clock++;
    } else {clock++;} /* if no task is ready, clock still runs */
    /* When a task is finished */
    if (tasks[q].burstTime == 0) {
      finishQ[q] = 1;
      tasks[q].finTime = clock;
      printf("<time %u> process %u is finished -->\n", clock, tasks[q].pid);
      q++;
      if (q == size) {
        done = 1;
      }
    }
  }
  /* Final process finish time preserved for analysis */
  tasks[0].exitTime = clock;
  printf("<time %u> All processes have finished\n", clock);
}

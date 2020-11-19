/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  rr.c
 *  High-level generalized algorithm in Exercise 2, slide 15 of ppt for Lecture 29 used
 *  Googled how to break out of a nested loop, followed multiple sites' advice of using goto (as SKIP here)
 *  No specific code was referenced or used, just the suggestion of implementing goto's
 *  No other references used
 *  While researching goto's, I found that there is some animosity towards them,
 *      so I feel the need to explain my usage of two additional goto's.
 *      My previous implementation only checked if the final task finished
 *      in order to exit the while loop, which I fixed with a goto (DONE)
 *      Secondly, the program initially only added at most one task to the ready queue,
 *      which I used another goto to solve (ADD)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* file includes */
#include "scheduler.h"
#include "cmdinput.h"

/*
 *  Simulates a CPU Scheduler using Round Robin
 *  Task arrivals are continuously monitored to determine readiness
 *  Burst times are stored for analysis then decremented as the process gets CPU time
 *  start and finish times are populated
 */
void rrRun (task_t tasks[], int size, int timeQuantum) {
  uInt clock = 0;
  uInt i = 0;
  uInt q = 0;
  uInt nextFree = 0;

  int readyQ[size];
  int finishQ[size];
  int turnQ[size];

  int done = 0;
  DONE:
  while (done != 1) {
    /* Evaluate task readiness */
    ADD:
    if (!(tasks[i].arrivalTime > clock)) {
      tasks[i].quantumTime = timeQuantum;
      readyQ[i] = 1;
      turnQ[nextFree] = i;
      nextFree++;
      i++;
      goto ADD;
    }
    /* first time task gets resource */
    if (readyQ[turnQ[0]] == 1) {
      readyQ[turnQ[0]] = 2;
      tasks[turnQ[0]].startTime = clock;
      tasks[turnQ[0]].origBurst = tasks[turnQ[0]].burstTime;
    }
    /* every time task gets resource */
    if (readyQ[turnQ[0]] == 2) {
      printf("<time %u> process %u is running\n", clock, tasks[turnQ[0]].pid);
      tasks[turnQ[0]].burstTime--;
      tasks[turnQ[0]].quantumTime--;
      clock++;
    } else {clock++;} /* if no task is ready, clock still runs */
    int j;
    /* When a task is finished */
    if (tasks[turnQ[0]].burstTime == 0) {
      finishQ[turnQ[0]] = 1;
      tasks[turnQ[0]].finTime = clock;
      printf("<time %u> process %u is finished -->\n", clock, tasks[turnQ[0]].pid);
      readyQ[turnQ[0]] = 3;
      for (j =0; j < nextFree - 1; j++) {
        turnQ[j] = turnQ[j+1];
      }
      nextFree--;
      turnQ[nextFree] = 0;
      goto SKIP;
    }
    /* When a task's time quantum runs out for that turn */
    if (tasks[turnQ[0]].quantumTime == 0) {
      tasks[turnQ[0]].quantumTime = timeQuantum;
      turnQ[nextFree] = turnQ[0];
      for (j=0; j <= nextFree; j++) {
        turnQ[j] = turnQ[j+1];
      }
      turnQ[nextFree] = 0;
    }

    int k;
    /* Checks if any tasks are unfinished */
    SKIP:
    for (k =0; k < size; k++) {
      done = 1;
      if (finishQ[k] == 0) {
        done = 0;
        goto DONE;

      }
    }


  }
  /* Final process finish time preserved for analysis */
  tasks[0].exitTime = clock;
  printf("<time %u> All processes have finished\n", clock);

}

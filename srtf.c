/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  srtf.c
 *  High-level generalized algorithm in Exercise 2, slide 15 of ppt for Lecture 29 used
 *  No other outside references used.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* file includes */
#include "scheduler.h"
#include "cmdinput.h"

/*
 *  Simulates a CPU Scheduler using Shortest Remaining Time First
 *  Task arrivals are continuously monitored to determine readiness
 *  Burst times are stored for analysis then decremented as the process gets CPU time
 *  start and finish times are populated
 */
void srtfRun (task_t tasks[], int size) {
  uInt clock = 0;
  uInt i = 0;
  uInt q = 0;
  int k;
  uInt min, next, turn;

  int readyQ[size];
  int finishQ[size];

  int done = 0;
  DONE:
  while (done != 1) {
    /* Evaluate task readiness */
    ADD:
    if (!(tasks[i].arrivalTime > clock)) {
      readyQ[i] = 1;
      finishQ[i] = 0;
      i++;
      goto ADD;
    }
    min = 999;
    turn = 0;
    int j;
    /* Determines shortest remaining time left out of ready tasks */
    for (j =0; j < size; j++) {
      if (readyQ[j] == 1 | readyQ[j] == 2) {
        next = tasks[j].burstTime;
        if (next < min) {
          min = next;
          turn = j;
        }
      }
    }
    /* first time task gets resources */
    if (readyQ[turn] == 1) {
      readyQ[turn] = 2;
      tasks[turn].startTime = clock;
      tasks[turn].origBurst = tasks[turn].burstTime;
    }
    /* Every time task gets resources */
    if (readyQ[turn] == 2) {
      printf("<time %u> process %u is running\n", clock, tasks[turn].pid);
      tasks[turn].burstTime--;
      clock++;
    } else {clock++;} /* if no task is ready, clock still runs */
    /* When a task is finished */
    if (tasks[turn].burstTime == 0) {
      finishQ[turn] = 1;
      tasks[turn].finTime = clock;
      printf("<time %u> process %u is finished -->\n", clock, tasks[turn].pid);
      readyQ[turn] = 3;
    }
    /* Checks if any tasks are unfinished */
    for (k = 0; k < size; k++){
      done = 1;
      if (finishQ[k] == 0) {
        done = 0;
        goto DONE;
      }
    }
  }
  tasks[0].exitTime = clock;
  printf("<time %u> All processes have finished\n", clock);
}

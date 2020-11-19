/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  fcfs.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* file includes */
#include "scheduler.h"
#include "cmdinput.h"

void fcfsRun (task_t tasks[], int size) {
  uInt clock = 0;
  uInt i = 0;
  uInt q = 0;

  int readyQ[size];
  int finishQ[size];
  int done = 0;

  while (done != 1) {
    if (!(tasks[i].arrivalTime > clock)) {
      readyQ[i] = 1;
      i++;

    }
    if (readyQ[q] == 1) {
      tasks[q].startTime = clock;
      tasks[q].origBurst = tasks[q].burstTime;
      readyQ[q] = 2;

    }

    if (readyQ[q] == 2) {
      printf("<time %u> process %u is running\n", clock, tasks[q].pid);
      tasks[q].burstTime--;
      clock++;
    } else {clock++;}

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
  tasks[0].exitTime = clock;
  printf("<time %u> All processes have finished\n", clock);



}

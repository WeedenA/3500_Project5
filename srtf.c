/*
  Alex Weeden
  Project 5
  srtf.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* file includes */
#include "scheduler.h"
#include "cmdinput.h"

void srtfRun (task_t tasks[], int size) {
  uInt clock = 0;
  uInt i = 0;
  uInt q = 0;
  uInt min, next, turn;

  int readyQ[size];
  int finishQ[size];

  while (finishQ[size-1] == 0) {
    if (!(tasks[i].arrivalTime > clock)) {
      readyQ[i] = 1;
      i++;
    }
    min = 999;
    turn = 0;
    int j;
    for (j =0; j < size; j++) {
      if (readyQ[j] == 1 | readyQ[j] == 2) {
        next = tasks[j].burstTime;
        if (next < min) {
          min = next;
          turn = j;
        }
      }
    }
    if (readyQ[turn] == 1) {
      readyQ[turn] = 2;
      tasks[turn].startTime = clock;
    }
    if (readyQ[turn] == 1 | readyQ[turn] == 2) {
      printf("<time %u> process %u is running\n", clock, tasks[turn].pid);
      tasks[turn].burstTime--;
      clock++;
    }
    if (tasks[turn].burstTime == 0) {
      finishQ[turn] = 1;
      tasks[turn].finTime = clock;
      printf("<time %u> process %u is finished -->\n", clock, tasks[turn].pid);
      readyQ[turn] = 3;
    }
  }
  printf("<time %u> All processes have finished\n", clock);

}

/*
  Alex Weeden
  Project 5
  printstat.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* file includes */
#include "scheduler.h"
#include "cmdinput.h"

void printStats (stat_t stats[]) {
  printf("====================================================\n");
  printf("Average waiting time:   %f\n", stats[0].avgWait);
  printf("Average response time:   %f\n", stats[0].avgResp);
  printf("Average turnaround time:   %f\n", stats[0].avgTAT);
  printf("Overall CPU usage:   %f%%\n", stats[0].usage);



}

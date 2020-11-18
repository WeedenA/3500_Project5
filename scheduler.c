/*
  Alex Weeden
  Project 5
  scheduler.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* file includes */
#include "scheduler.h"
#include "cmdinput.h"
#include "analysis.h"
#include "fcfs.h"
#include "srtf.h"
#include "rr.h"
#include "printstat.h"



int main( int argc, char *argv[] ) {
  task_t startArray[MAX_TASK_ARRAY];
  stat_t statsArray[1];
  FILE *fd;
  char *fileName;
  char *policyChoice;
  uInt count;
  int quantum;

  if (argc < 3 | argc > 4) {
    printf("Incorrect arguments given. Input <fileName> [FCFS|RR|SRTF] [time_quantum].\n");
    return EXIT_FAILURE;
  }

  fileName = argv[1];
  if (! (fd = fopen(fileName, "r"))) {
    printf("File, named %s, is invalid or cannot be opened. Check your file name and retry\n", fileName);
    return EXIT_FAILURE;
  }

  policyChoice = argv[2];
  printf("Scheduling Policy: %s\n", policyChoice);


  count = 0;
  openFile(argc, argv, &count, startArray);

  if (strcmp(policyChoice,"FCFS") == 0) {
    printf("here");
    fcfsRun(startArray, count);
  }
  if (strcmp(policyChoice, "SRTF") == 0) {
    srtfRun(startArray, count);
  }
  if (strcmp(policyChoice, "RR")== 0) {
    if (argc != 4) {
      printf("No time quantum given\n");
      return EXIT_FAILURE;
    }
    quantum = atoi(argv[3]);
    rrRun(startArray, count, quantum);
  }

  analyzeTime(startArray, count, statsArray);
  printStats(statsArray);


  printf("p: %u\n", startArray[3].arrivalTime);
  printf("Made it\n");
  return EXIT_SUCCESS;
}

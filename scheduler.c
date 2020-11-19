/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  scheduler.c
 *  Main program file
 *  Multiple error message implementations pulled from Dr. Qin's sample code provided on Canvas
 *  No other outside references used.
 *
 *  Compilation instructions commented in scheduler.h
 *
 *  Run instructions:
 *  If too few arguments are provided, input requirement is printed
 *  ./scheduler
 *  Incorrect arguments given. Input <fileName> [FCFS|RR|SRTF] [time_quantum].
 *
 *  If the file doesn't exist, but a policy choice is given,
 *      an error is printed in cmdinput.c suggesting validation of fileName
 *  ./scheduler notAFile
 *  File, named notAFile, is invalid or cannot be opened. Check your file name and retry
 *
 *  If the file is valid, but the policy choice is not, an error is displayed
 *      after confirming loading of the file, providing necessary policy format.
 *  ./scheduler task.list RRR 10
 *  <task attribute data displayed>
 *  Invalid Policy Coice. Input [FCFS|SRTF|RR [int quantum]]
 *
 *    (While it may be prudent to send this error before loading the file,
 *        this process clearly shows the user that their data and file are valid,
 *        and displays their policy choice, though invalid, in output before closing)
 *
 *  If Round Robin is chosen for a valid file, but no time quantum is given,
 *  an error "No time quantum given" is printed after loading the file.
 *
 *  If all arguments are valid, the scheduler displays the following:
 *  Policy Choice
 *  Tasks loaded from file, with attributes pid, arrival, and burst times
 *  User input prompt to run simulation
 *  Scheduler simulation of running tasks, and confirmation of all tasks finished
 *  Average wait, response, and turnaround times, along with CPU usage
 *
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
/*
 *  Uses command line to pass user input to cmdinput.c, which populates the task struct
 *  After error-checking input, a policy choice is made to simulate a CPU scheduler of that type
 *  One of these three functions populates statistical times in the task struct
 *  The task struct and empty statistics struct are passed to analysis.c,
 *  the latter of which is populated then passed to and printed by printstat.c
 */
int main( int argc, char *argv[] ) {
  task_t startArray[MAX_TASK_ARRAY];
  stat_t statsArray[1];
  FILE *fd; /* file denotation */
  char *fileName; /* file name from user */
  char *policyChoice; /* policy input from user */
  uInt count; /* number of tasks read by cmdinput.c, used by process flow to iterate */
  int quantum; /* time quantum from user, if Round Robin is chosen */
  int error; /* error handling from cmdinput.c */

  /* Validates quantity of arguments */
  if (argc < 3 | argc > 4) {
    printf("Incorrect arguments given. Input <fileName> [FCFS|RR|SRTF] [time_quantum].\n");
    return EXIT_FAILURE;
  }

  fileName = argv[1];
  policyChoice = argv[2];
  count = 0;

  printf("Scheduling Policy: %s\n", policyChoice);

  /* populates task struct */
  error = openFile(&fd, fileName, argv, &count, startArray);
  if (error == 1) {
    return EXIT_FAILURE;
  }

  /* directs task struct to simulated policy, finishes population */
  if (strcmp(policyChoice,"FCFS") == 0) {
    fcfsRun(startArray, count);
  } else if (strcmp(policyChoice, "SRTF") == 0) {
    srtfRun(startArray, count);
  } else if (strcmp(policyChoice, "RR")== 0) {
    /* Validates time quantum is given */
    if (argc != 4) {
      printf("No time quantum given\n");
      return EXIT_FAILURE;
    }
    quantum = atoi(argv[3]);
    rrRun(startArray, count, quantum);
  } else {
    /* Validates policy choice */
    printf("Invalid Policy Coice. Input [FCFS|SRTF|RR [int quantum]]\n");
    return EXIT_FAILURE;
  }

  /* uses finished task times to populate statistic array */
  analyzeTime(startArray, count, statsArray);

  /* Displays statistics for User */
  printStats(statsArray);

  fclose(fd);
  return EXIT_SUCCESS;
}

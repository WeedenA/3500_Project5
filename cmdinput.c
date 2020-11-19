/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  cmdinput.c
 *  Referenced Dr. Qin's input.c sample code to design general flow
 *  Pulled file scanner and task population from Dr. Qin's provided starter code (input.c)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* file includes */
#include "cmdinput.h"
/*
 *  Passed a file to validate and read, populating the task list with pid, arrival time, and burst time
 *  Displays number of tasks, and their attributes
 *  Waits on user response to return to simulated scheduling
 */
int openFile( FILE **fileDes, char *name, char *argv[], int *size, task_t taskArray[] ) {
  uInt i;
  int num = 0;
  /* Validate file */
  if (! (*fileDes = fopen(name, "r"))) {
    printf("File, named %s, is invalid or cannot be opened. Check your file name and retry\n", name);
    return 1;
  }
  /* Populate task struct */
  while (fscanf(*fileDes, "%u %u %u", &taskArray[num].pid, &taskArray[num].arrivalTime, &taskArray[num].burstTime) != EOF) {
    num++;
  }
  *size = num; /* pass number of tasks back to scheduler */
  printf("%d tasks have been loaded from the file named %s: \n", num, name);
  /* Print tasks and their attributes */
  for (i=0; i < num; i++) {
    printf("Process ID: %u, Arrival Time: %u, Burst Time: %u\n", \
            taskArray[i].pid, taskArray[i].arrivalTime, taskArray[i].burstTime);
  }
  /* Await user input to continue simulation */
  printf("Press any key to simulate scheduling:\n");
  getchar();
  return 0;


}

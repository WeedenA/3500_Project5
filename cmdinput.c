/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  cmdinput.c
 *  Pulled process flow and scanning while loop from Dr. Qin's sample code input.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmdinput.h"

int openFile( FILE **fileDes, char *name, char *argv[], int *size, task_t taskArray[] ) {


  uInt i;
  int num = 0;
  if (! (*fileDes = fopen(name, "r"))) {
    printf("File, named %s, is invalid or cannot be opened. Check your file name and retry\n", name);
    return 1;
  }


  while (fscanf(*fileDes, "%u %u %u", &taskArray[num].pid, &taskArray[num].arrivalTime, &taskArray[num].burstTime) != EOF) {
    num++;
  }
  *size = num;

  printf("%d tasks have been loaded from the file named %s: \n", num, name);

  for (i=0; i < num; i++) {
    printf("Process ID: %u, Arrival Time: %u, Burst Time: %u\n", \
            taskArray[i].pid, taskArray[i].arrivalTime, taskArray[i].burstTime);

  }

  printf("Press any key to simulate scheduling:\n");
  getchar();

  return 0;


}

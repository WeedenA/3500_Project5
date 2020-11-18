/*
Alex Weeden
Project 5
cmdinput.c

Pulled process pull and scanning while loop from Dr. Qin's sample code input.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmdinput.h"

void openFile( int argc, char *argv[], int *size, task_t taskArray[] ) {
  char *fileName;
  FILE *fd;

  uInt i;
  int num = 0;

  fileName = argv[1];
  fd = fopen(fileName, "r");

  while (fscanf(fd, "%u %u %u", &taskArray[num].pid, &taskArray[num].arrivalTime, &taskArray[num].burstTime) != EOF) {
    num++;
  }
  *size = num;

  printf("%d tasks have been loaded from the file named %s \n", num, fileName);

  for (i=0; i < num; i++) {
    printf("Process ID: %u, Arrival Time: %u, Burst Time: %u\n", \
            taskArray[i].pid, taskArray[i].arrivalTime, taskArray[i].burstTime);

  }

  printf("Press any key to simulate scheduling:\n");
  getchar();
  fclose(fd);


}

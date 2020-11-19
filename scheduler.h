/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  scheduler.h
 *  main program file
 */
#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

/*
 *  Statistics struct populated in analysis.c
 *  After analyzing, passed to printstat.c to display average times
 *    and cpu usage for chosen simulation.
 */
typedef struct stats {
  double avgWait;
  double avgTAT;
  double avgResp;
  double usage;
  int totalBurst;
}stat_t;

#endif

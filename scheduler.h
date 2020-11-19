/*
 *  Alex Weeden
 *  COMP 3500 Project 5
 *  scheduler.h
 *  main program file
 *  Dr. Qin's provided starter code "scheduler.h" used as reference
 *  no other outside references used.
 *
 *  Use "make" to compile using Makefile
 *
 *  Manual compilation:
 *  Use "gcc -c <fileName>" to compile cmdinput.c, fcfs.c, rr.c, srtf.c, analysis.c, printstat.c
 *  "gcc cmdinput.o, fcfs.o, rr.o, srtf.o, analysis.o, printstat.o scheduler.c -o scheduler"
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

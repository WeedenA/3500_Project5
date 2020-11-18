#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

typedef struct stats {
  double avgWait;
  double avgTAT;
  double avgResp;
  double usage;
  int totalBurst;
}stat_t;

#endif

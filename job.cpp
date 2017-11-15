#include "job.h"

Job::Job(){
  arrivalTime = 0;
  serviceTime = 0;
  responseTime = 0;
  hasArrived = false;
  isServiced = false;
  serviceCounter = 0;
}

Job::Job(const double arrive){
  procNum = num;
  myLine = "I am job" + string(procNum);
}

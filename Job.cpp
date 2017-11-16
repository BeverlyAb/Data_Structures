#include "Job.h"

Job::Job()
{
  arrivalTime = 0;
  serviceTime = 0;
  responseTime = 0;
  ID = 0;
}

Job::Job(int myID)
{
  arrivalTime = 0;
  serviceTime = 0;
  responseTime = 0;
  ID = myID;
}
void Job::setArrival(double t)
{
  arrivalTime = t;
}

void Job::setService(double t)
{
  serviceTime = t;
}

void Job::setResponse(double t)
{
  responseTime = t;
}

void Job::setUtil(double t)
{
  util = t;
}

double Job::getArrival()
{
  return arrivalTime;
}

double Job::getService()
{
  return serviceTime;
}

double Job::getResponse()
{
  return responseTime;
}

double Job::getUtil()
{
  return util;
}

int Job::getID()
{
  return ID;
}

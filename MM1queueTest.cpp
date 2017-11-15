//MM1queueTest

#include <iostream>
#include <time.h>
#include <vector>
#include "MM1queue.h"
#include "Job.h"
using namespace std;

int main()
{
  vector<Job> myJobs;
  for(int i = 0; i <10; i++)
  {
    myJobs.push_back(Job(i));
  }
  MM1queue<Job> mm1;
  time_t endTime = time(0) + 200;
  int j = 0;
  while(time(0) < endTime) {
    while(!mm1.isServable()) {
      mm1.push(myJobs[j++]);
    }
    mm1.serve();
  }
}

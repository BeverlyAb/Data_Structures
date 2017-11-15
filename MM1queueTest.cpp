//MM1queueTest

#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include "MM1queue.h"
#include "Job.h"

using namespace std::chrono;
/*int main ()
{

  duration<int,std::ratio<200> > one_day (1);

  system_clock::time_point today = system_clock::now();
  system_clock::time_point tomorrow = today + one_day;

  time_t tt;

  tt = system_clock::to_time_t ( today );
  std::cout << "today is: " << ctime(&tt);

  tt = system_clock::to_time_t ( tomorrow );
  std::cout << "tomorrow will be: " << ctime(&tt);

  return 0;
} */

int main()
{
  std::vector<Job> myJobs;
  for(int i = 0; i <10; i++)
  {
    myJobs.push_back(Job(i));
  }
  MM1queue<Job> mm;

  duration<int,std::ratio<2> > period (1);

  system_clock::time_point currentTime = system_clock::now();
  system_clock::time_point endTime = currentTime + period;
  int j = 0;
  int counter = 0;
  while(endTime > currentTime ) {
    //while(!mm1.isServable()) {
    //  mm1.push(myJobs[j]);
  //  cout << "endtime " <<  endTime(sec).count() <<endl;
    currentTime = system_clock::now();
  /*  duration<double> dur = endTime - currentTime;
    cout << dur.count() <<endl;
    counter++; */
  }
  //  mm1.serve();
//  }
}

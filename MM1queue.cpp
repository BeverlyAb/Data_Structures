#include "MM1queue.h"
#include <random>


#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <time.h>
#include "Job.h"

using namespace std;

#define mu 1
#define lambda 1

//template <class T, template <class T, class = allocator<T> > class Container = queue>
//template<typename T, template <typename, typename> class Container = queue>
template<class T>
MM1queue<T>::MM1queue()
{
	std::queue<T> myQueue;
	enqID = -1;
	serveID = -2;
	enqueueTime = 0;
	serveTime = 0;
	currentTime = 0;
	timer = 0;
	servable = false;
}

template<class T>
void MM1queue<T>::push(const T & myJob, double timeIn)
{

	currentTime = timeIn;
	if(currentTime >= enqueueTime){
		myQueue.push(myJob);
		back().setArrival(currentTime);
		enqID = back().getID();
		servable = true;
	}
}

template<class T>
double MM1queue<T>::serve(double timeIn)
{
	if(!isEmpty()){
	//	servable = true;
		double temp = timeIn;
		currentTime = temp;
		myQueue.front().setService(serveTime);

		//currently Serving
		double updateCounter = 0;
		while(currentTime < temp + serveTime){
			currentTime++;
			updateCounter++; //busy wait, need to update glob_counter
		}
			myQueue.front().setUtil(currentTime - temp);

			double myArrive = myQueue.front().getArrival();
			myQueue.front().setResponse(currentTime - myArrive);
			myQueue.pop();
			serveID = front().getID();
	//		servable = false;
			return updateCounter;
	}
	//servable = false;
	return 0;
}

template<class T>
void MM1queue<T>::setEnqueue(double timeIn)
{
	if(isEmpty() || back().getID() != enqID){
		std::default_random_engine generator(rand());

	  std::exponential_distribution<double> distribution(lambda);
		double calc = distribution(generator) * pow(10,1);
		//relative value
		enqueueTime = timeIn + calc;
	}
}

template<class T>
void MM1queue<T>::setServe()
{
	//if(front().getID() != serveID){
		std::default_random_engine generator(rand());
	  std::exponential_distribution<double> distribution(mu);
		double calc = distribution(generator);

		//set value
		serveTime = calc * pow(10,1);
	//}
}

template<class T>
bool MM1queue<T>::isEmpty()
{
	return myQueue.empty();
}

template<class T>
bool MM1queue<T>::isServable()
{
	return servable;
}

template<class T>
int MM1queue<T>::size()
{
	return myQueue.size();
}

template<class T>
T & MM1queue<T>::front()
{
	return myQueue.front();
}

template<class T>
T & MM1queue<T>::back()
{
	return myQueue.back();
}
/*
	Typically, test main() should have its own file, but due to linking errors
	with MM1queue(), I was forced to compile and run it from here.
*/
int main()
{
  std::vector<Job> myJobs;
  for(int i = 0; i <1000; i++)
  {
    myJobs.push_back(Job(i));
  }
  MM1queue<Job> mm1;

  int j = 0;
	int jobServed = 0;
	double glob_counter = 0;
	int mySize = mm1.size();

	mm1.setServe();
	mm1.setEnqueue(glob_counter);
  while(glob_counter < 200) {
  	//if(!mm1.isServable()){
      mm1.push(myJobs[j++], glob_counter++);
			cout << "s1 " << mm1.size() <<endl;
			if(mm1.size() != mySize) { // actually enqueued!
				mm1.setServe(); //set when to serve and enqueue next one
				mm1.setEnqueue(glob_counter);
				cout << "s2 " << mm1.size() <<endl;
				mySize = mm1.size();
			}
	//	}
	 	 if(!mm1.isEmpty()){
				jobServed++;
				cout << "ID "<< mm1.front().getID() << ", ";
				cout << mm1.front().getArrival() << ", ";
				cout << mm1.front().getService() << ", ";
				cout << mm1.front().getResponse() << ", ";
				cout << mm1.front().getUtil() << ", "<< endl;
				glob_counter += mm1.serve(glob_counter);
				glob_counter++;
		}
	}
	cout << "# jobs served " << jobServed << endl;
}

#include "MM1queue.h"
#include <random>

//#include <iostream>
#include "Job.h"

#define mu 1
#define lambda 1

//template <class T, template <class T, class = allocator<T> > class Container = queue>
//template<typename T, template <typename, typename> class Container = std::queue>

//template<class T>
void MM1queue::push(const T & myJob)
{
	currentTime = time(&timer);
	while(currentTime < enqueueTime){
		currentTime = time(&timer);
	}
	back().setArrival(currentTime);
	container.push_back(myJob);
}

//template<class T>
void MM1queue::serve(const T & myJob)
{
	if(!isEmpty()){
		double temp = time(&timer);
		currentTime = temp;
		front().setService(serveTime);

		servable = true; //currently serving
		while(currentTime < temp + serveTime){
			currentTime = time(&timer);
		}
		front().setUtil(currentTime - temp);

		double myArrive = front.().getArrival();
		front().setResponse(currentTime - myArrive);
		container.pop_front();
		servable = false;
	}
}

//template<class T>
void MM1queue::setEnqueue()
{
	default_random_engine generator;
  exponential_distribution<double> distribution(lambda);
	double calc = distribution(generator);

	//relative value
	enqueueTime = time(&timer)) + calc;
}

//template<class T>
void MM1queue::setServe()
{
	default_random_engine generator;
  exponential_distribution<double> distribution(mu);
	double calc = distribution(generator);

	//set value
	serveTime = calc;
}

//template<class T>
T & MM1queue::isEmpty()
{
	return container.empty();
}

//template<class T>
T & MM1queue::isServable()
{
	return servable;
}

//template<class T>
T & MM1queue::front()
{
	container.front();
}

//template<class T>
T & MM1queue::back()
{
	container.back();
}

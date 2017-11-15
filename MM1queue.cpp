#include "MM1queue.h"
#include <queue>
#include <random>

//#include <iostream>
#include "job.h"

#define mu 1
#define lambda 1

template <class T, template <class T, class = allocator<T> > class Container = queue>

template<class T>
void MM1queue<T>::push(const T & myJob)
{
	currentTime = time(&timer);
	while(currentTime < enqueueTime){
		currentTime = time(&timer);
	}
	back().setArrival(currentTime);
	container.push_back(myJob);
}

template<class T>
void MM1queue<T>::serve(const T & myJob)
{
	if(!isEmpty()){
		double temp = time(&timer);
		currentTime = temp;
		front().setService(serveTime);

		while(currentTime < temp + serveTime){
			currentTime = time(&timer);
		}
		double myArrive = front.().getArrival();
		front().setResponse(time(&timer) - myArrive);
		container.pop_front();
	}
}

template<class T>
void MM1queue<T>::setEnqueue()
{
	default_random_engine generator;
  exponential_distribution<double> distribution(lambda);
	double calc = distribution(generator);

	//relative value
	enqueueTime = time(&timer)) + calc;
}

template<class T>
void MM1queue<T>::setServe()
{
	default_random_engine generator;
  exponential_distribution<double> distribution(mu);
	double calc = distribution(generator);

	//set value
	serveTime = calc;
}

template<class T>
T & MM1queue<T>::isEmpty()
{
	return container.empty();
}


template<class T>
T & MM1queue<T>::front()
{
	container.front();
}

template<class T>
T & MM1queue<T>::back()
{
	container.back();
}

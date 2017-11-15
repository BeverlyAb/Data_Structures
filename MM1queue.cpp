#include "MM1queue.h"
#include <random>

//#include <iostream>

#define mu 1
#define lambda 1

//template <class T, template <class T, class = allocator<T> > class Container = queue>
//template<typename T, template <typename, typename> class Container = queue>
template<class T>
MM1queue<T>::MM1queue()
{
	std::queue<T> myQueue;
	//myQueue();
	enqueueTime = 0;
	serveTime = 0;
	currentTime = 0;
	timer = 0;
	servable = false;
}

template<class T>
void MM1queue<T>::push(const T & myJob)
{
	currentTime = time(&timer);
	while(currentTime < enqueueTime){
		currentTime = time(&timer);
	}
	back().setArrival(currentTime);
	myQueue.push(myJob);
}

template<class T>
void MM1queue<T>::serve()
{
	if(!isEmpty()){
		double temp = time(&timer);
		currentTime = temp;
		myQueue.front().setService(serveTime);

		servable = true; //currently serving
		while(currentTime < temp + serveTime){
			currentTime = time(&timer);
		}
		myQueue.front().setUtil(currentTime - temp);

		double myArrive = myQueue.front().getArrival();
		myQueue.front().setResponse(currentTime - myArrive);
		myQueue.pop();
		servable = false;
	}
}

template<class T>
void MM1queue<T>::setEnqueue()
{
	std::default_random_engine generator;
  std::exponential_distribution<double> distribution(lambda);
	double calc = distribution(generator);

	//relative value
	enqueueTime = time(&timer) + calc;
}

template<class T>
void MM1queue<T>::setServe()
{
	std::default_random_engine generator;
  std::exponential_distribution<double> distribution(mu);
	double calc = distribution(generator);

	//set value
	serveTime = calc;
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
T & MM1queue<T>::front()
{
	myQueue.front();
}

template<class T>
T & MM1queue<T>::back()
{
	myQueue.back();
}


int main()
{
//  Job myJob = Job();
//  cout << myJob.getArrival();
  MM1queue<int> mm1;

}

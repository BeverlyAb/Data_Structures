#ifndef MM1QUEUE_H
#define MM1QUEUE_H
#include <time.h>
#include <queue>
//#include "Job.h"
//template<typename T, template <typename, typename> class Container = std::queue>
//template<typename T, template <typename, typename> class Container = std::queue>
template <class T>
class MM1queue {
	private:
	//	double glob_counter;
		std::queue<T> myQueue;
		int enqID;
		int serveID;
		double enqueueTime;
  	double serveTime;
	 	double currentTime;
		time_t timer;
		bool servable;

	public:
		  MM1queue();
			void push(const T & myJob, double timeIn);
			double serve(double timeIn);
			void setEnqueue(double timeIn);
			void setServe();
			bool isEmpty();
			bool isServable();
			int size();
		//	void getCurrentTime(double t);
			T & back();// returns value at the back of Queue; O(1)
 			T & front();						// returns value at the front of Queue; O(1)
};
#endif //MM1QUEUE_H

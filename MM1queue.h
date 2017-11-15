#ifndef MM1QUEUE_H
#define MM1QUEUE_H
#include <time.h>
#include <queue>

//template<typename T, template <typename, typename> class Container = std::queue>
template<typename T, template <typename, typename> class Container = std::queue>
//template <class T>
class MM1queue {
	private:
		double enqueueTime;
  	double serveTime;
	 	double currentTime;
		time_t timer;
		bool servable;

	public:
		  //MM1queue(); queue should have constructor and destructor
			void push(const T & myJob);
			void serve();
			void setEnqueue();
			void setServe();
			bool isEmpty();
			bool isServable();
		//	void getCurrentTime(double t);
			T & back();// returns value at the back of Queue; O(1)
 			T & front();						// returns value at the front of Queue; O(1)
};
#endif //MM1QUEUE_H

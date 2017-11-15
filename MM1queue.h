#ifndef MM1QUEUE_H
#define MM1QUEUE_H
#include <time.h>


class MM1queue {
	private:
		Container<T> container;
		double enqueueTime;
  	double serveTime;
	 	double currentTime;
		time_t timer;

	public:
		  //MM1queue(); queue should have constructor and destructor
			void push(const T & myJob);
			void serve();
			void setEnqueue();
			void setServe();
			bool isEmpty();
		//	void getCurrentTime(double t);
			T & back();// returns value at the back of Queue; O(1)
 			T & front();						// returns value at the front of Queue; O(1)
};
#endif /* NODE_HPP */

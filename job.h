#ifndef JOB_H
#define JOB_H

class Job {
	double arrivalTime;
	double serviceTime; //p(x) = mu....
	double responseTime;
	bool hasArrived;
	bool isServiced;
	int serviceCounter;

	public:
			Job(); //default
			Job(const double arrive);
			void setArrival(double t);
			void setService(double t);
			void setResponse(double t);
			//accessors
		//	bool getArrivalStatus();
			double getArrival());
			double getService());
			double getResponse();

};
#endif /* NODE_HPP */
//wait in queue = arrivalTime + serviceTime

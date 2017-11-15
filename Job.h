#ifndef JOB_H
#define JOB_H

class Job {
	private:
		double arrivalTime;
		double serviceTime;
		double responseTime;
		double util;
		int ID;

	public:
			Job(); //default
			Job(int myID);
			void setArrival(double t);
			void setService(double t);
			void setResponse(double t);
			void setUtil(double t);
			//accessors
			double getArrival();
			double getService();
			double getResponse();
			double getUtil();
			int getID();

};
#endif //JOB_H

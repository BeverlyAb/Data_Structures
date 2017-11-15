test: MM1queueTest.o MM1queue.o Job.o
	g++ -o test MM1queueTest.o MM1queue.o Job.o

MM1queueTest.o: MM1queueTest.cpp
	g++ -c MM1queueTest.cpp

MM1queue.o: MM1queue.cpp
	g++ -c MM1queue.cpp

Job.o: Job.cpp
	g++ -c Job.cpp

clean:
	rm MM1queueTest.o MM1queue.o Job.o

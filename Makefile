.PHONY: pipes clean queues shared_memory signals thread exceptions const

all: pipes queues shared_memory signals thread exceptions const
	
pipes:
	gcc -o pipes pipes.c

queues:
	gcc -o message_queues message_queues.c

shared_memory:
	gcc -o shared_memory shared_memory.c

signals:
	gcc -o signals signals.c

thread:
	g++ -o thread thread.cpp -pthread -std=c++11

exceptions:
	g++ -o exceptions exceptions.cpp

const:
	g++ -o const const.cpp

clean:
	rm -rf pipes message_queues shared_memory signals thread exceptions const

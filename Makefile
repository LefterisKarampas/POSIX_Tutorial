.PHONY: pipes clean

all: pipes queues shared_memory
	
pipes:
	gcc -o pipes pipes.c

queues:
	gcc -o message_queues message_queues.c

shared_memory:
	gcc -o shared_memory shared_memory.c

clean:
	rm -rf pipes message_queues shared_memory

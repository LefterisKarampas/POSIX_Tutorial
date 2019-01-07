.PHONY: pipes clean

all: pipes queues
	
pipes:
	gcc -o pipes pipes.c

queues:
	gcc -o message_queues message_queues.c

clean:
	rm -rf pipes message_queues

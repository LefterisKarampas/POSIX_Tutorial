.PHONY: web_server client clean
all: web_server client

web_server:
	gcc -o web_server web_server.c worker.c producer.c list.c -pthread

client:
	gcc -o client client.c
clean:
	rm -rf web_server client list

#include "web_server.h"

void* producer(void* args)
{
	struct arg_struct* arg = args;
	int sock = arg->sock;
	int newsock;
	struct sockaddr_in client;
	struct sockaddr *clientptr= (struct sockaddr*)&client ;
	
	//initialize value 
	socklen_t clientlen = sizeof(struct sockaddr_in);
	while(1)
	{
		
		if ((newsock = accept(sock, clientptr, &clientlen)) == -1)
		{	
				perror("Failed: accept");
		}
		pthread_mutex_lock(&mtx);
		while(l.count >= 10)
		{
			pthread_cond_wait(&cond_nonfull, &mtx);
		}

		// insert fd to buffer
		List_Push(&l,newsock);
		pthread_cond_broadcast(&cond_nonempty);
		pthread_mutex_unlock(&mtx);
	}
}
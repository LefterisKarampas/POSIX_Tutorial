#include "web_server.h"

void* worker(void* arg)
{
	int count = 0;
	struct arg_struct *arg_strct = (void*)arg;
	int fd;
	char buffer[400];
	char responsebuf[400];
	while(1)
	{
		pthread_mutex_lock(&mtx);
		while(l.count <= 0)
		{
			pthread_cond_wait(&cond_nonempty, &mtx);
		}
		
		// take first fd from queue
		fd = List_Pop(&l);
		pthread_cond_broadcast(&cond_nonfull);
		pthread_mutex_unlock(&mtx);
		
		read(fd, buffer, sizeof(buffer));
		count++;
		sprintf(responsebuf,"%s: %d -> %s","Thread",count,buffer);
		write(fd, responsebuf, strlen(responsebuf));
	}
				
	close(fd);
	return (void*)1;
}
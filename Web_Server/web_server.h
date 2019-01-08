#ifndef _SERVERH_
#define _SERVERH_
#include <stdio.h>
#include <stdlib.h>			//malloc , exit
#include <sys/wait.h>		//sockets
#include <sys/types.h>		//sockets
#include <sys/select.h>		//select()
#include <netinet/in.h>		//htons,htonl,ntohs,ntohl
#include <netdb.h>			//gethostbyaddr, gethostbyname
#include <sys/socket.h>		//all socket functions
#include <unistd.h>			//access
#include <ctype.h>			//toupper
#include <signal.h>			//signal
#include <pthread.h>		//threads - compile with -pthread at end
#include <string.h>			//strerror , error printing for threads
#include <time.h>			//strftime
#include <sys/timeb.h>		//timeb struct
#include <sys/sendfile.h>	//more efficient way to send file than read-write , no use in here
#include "list.h"		//queue to hold fds

struct arg_struct
{
	int sock;
	int pid;
};

extern List l;
extern pthread_t *tid;
extern pthread_t prod;
extern pthread_mutex_t mtx , clock_mtx , stat_mtx, shtdw_mtx;
extern pthread_cond_t cond_nonempty;
extern pthread_cond_t cond_nonfull;
void* worker(void*);
void* producer(void*);

#endif
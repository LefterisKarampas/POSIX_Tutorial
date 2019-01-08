#include "web_server.h"

List l;
pthread_t *tid;
pthread_t prod;
pthread_mutex_t mtx;
pthread_cond_t cond_nonempty;
pthread_cond_t cond_nonfull;


int main(void){
	int i , sockopt_val=1;
	int nthr, port, sock, newsock;
	struct sockaddr_in server;
	struct sockaddr *serverptr = (struct sockaddr*)&server ;
	struct hostent *rem;
	port = 8080;
	nthr = 5;

	pthread_mutex_init(&mtx, 0);
	pthread_cond_init(&cond_nonempty, 0);
	pthread_cond_init(&cond_nonfull, 0);
	List_Initialize(&l);


	//create socket for clients
	if ((sock=socket(AF_INET,SOCK_STREAM,0)) == -1)
		perror("Failed to create socket");

	// enable option for both sockets 
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &sockopt_val, sizeof(int)) == -1)
	{
		perror("Failed: setsockopt");
		exit(1);
	}

	server.sin_family = AF_INET;					//internet domain
	server.sin_addr.s_addr = htonl(INADDR_ANY);		//any ip address
	server.sin_port = htons(port);					//given port
	//bind socket to address
	if (bind(sock,serverptr,sizeof(server)) == -1)
		perror("Failed to bind socket to port");

	//listen for connections
	if (listen(sock,128) == -1)
		perror("Failed: listen");

	struct arg_struct arg_strct;
	arg_strct.sock = sock;


	tid = malloc(sizeof(pthread_t)*nthr);
	//create #nthr threads
	for (int i=0;i<nthr;i++){
		arg_strct.pid = i+1;
		pthread_create(tid+i, 0, worker, (void*)&arg_strct);
	}

	//create one thread in order to insert fd to buff
	pthread_create(&prod, 0, producer, (void*)&arg_strct);


	for (int i=0;i<nthr;i++)
		pthread_join(tid[i], NULL);
	pthread_join(prod, NULL);


	pthread_mutex_destroy(&mtx);
	pthread_cond_destroy(&cond_nonempty);
	pthread_cond_destroy(&cond_nonfull);
	List_Free(&l);
	free(tid);
}
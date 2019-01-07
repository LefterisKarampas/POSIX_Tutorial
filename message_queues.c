#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

/*ftok(): is use to generate a unique key.

msgget(): either returns the message queue identifier for a newly created message 
queue or returns the identifiers for a queue which exists with the same key value.

msgsnd(): Data is placed on to a message queue by calling msgsnd().

msgrcv(): messages are retrieved from a queue.

msgctl(): It performs various operations on a queue. Generally it is use to 
destroy message queue.*/

typedef struct mesg_buffer
{
	long mesg_type;
	char mesg_text[100];
}message;

int main(){
	key_t key;
	int msgid;

	pid_t childpid;
	if((childpid = fork()) == -1){
		perror("fork");
		exit(1);
	}
	// ftok to generate unique key 
	key = ftok("progfile",65);
	msgid = msgget(key,0666 | IPC_CREAT);


	if(childpid == 0){
		message p;
		// msgrcv to receive message 
	    msgrcv(msgid, &p, sizeof(message), 1, 0); 
	  
	    // display the message 
	    printf("Data Received is : %s \n",  
	                    p.mesg_text); 
	  
	    // to destroy the message queue 
	    msgctl(msgid, IPC_RMID, NULL); 
  		exit(0);
	}
	else{
		message k;
		k.mesg_type = 1;
		printf("Write Data : \n");
		read(1,k.mesg_text,sizeof(k.mesg_text));

		// msgsnd to send message 
	    msgsnd(msgid, &k, sizeof(message), 0); 
	    // display the message 
	    printf("Data send is : %s \n", k.mesg_text); 
	}

	return 0;
}
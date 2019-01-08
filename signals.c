#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


void catchkill(int signo){
	fprintf(stderr,"Program is about time to exit\n");
	exit(0);
}

void catchstop(int signo){
	fprintf(stderr, "Suppose to be stopped!\n");	
}




int main(int argc, char const *argv[])
{
	static struct sigaction act;
	act.sa_handler=catchkill;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT,&act,NULL);
	
	static struct sigaction actt;
	actt.sa_handler=catchstop;
	sigfillset(&(actt.sa_mask));
	sigaction(SIGTSTP,&actt,NULL);

	while(1){
		;
	}

	return 0;
}
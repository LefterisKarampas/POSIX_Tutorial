#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	
	int fd[2];
	pid_t childpid;
	char string[] = "Hello World";
	char buffer[256];
	int nbytes;

	if(pipe(fd) == -1){
		perror("Pipe");
		exit(1);
	}

	if((childpid = fork()) == -1){
		perror("fork");
		exit(1);
	}

	if(childpid == 0){
		/* Child Process */
		close(fd[0]);
		write(fd[1],string,strlen(string)+1);
		exit(0);
	}
	else{
		close(fd[1]);
		nbytes = read(fd[0],buffer,sizeof(buffer));
		printf("Received string: %s\n",buffer);
	}

	/* code */
	return 0;
}
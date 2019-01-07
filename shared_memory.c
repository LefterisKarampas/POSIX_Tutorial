#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
#include <sys/sem.h>

#define READ 156
#define WRITE 157
#define MEMORY 158

typedef struct mesg{
	int key
}message;

int main(void){

	int shmid;
	key_t key;
	message * shm;
	//key = ftok("progfile",65);
	//Create the segment
	if ((shmid = shmget(MEMORY, sizeof(message), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    //Now we attach the segment to our data space.
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    //Create Semaphore
	int read = semget(READ, 1, 0600|IPC_CREAT );
	int write = semget(WRITE, 1, 0600|IPC_CREAT );
	struct sembuf up[1];
	up[0].sem_num  = 0;
	up[0].sem_op   = 1;
	up[0].sem_flg  = 0;
	struct sembuf down[1];
	down[0].sem_num  = 0;
	down[0].sem_op   = 1;
	down[0].sem_flg  = 0;

	// reset initial value
	short zero = 0;
	semctl(read,0,SETALL,&zero);
	semctl(write,0,SETALL,&zero);
	semop(write,up,1);

    pid_t childpid;
	if((childpid = fork()) == -1){
		perror("fork");
		exit(1);
	}
	if(childpid == 0){
		int test = -1;
		semop(read,down,1);
		test = shm->key;
		printf("Key read: %d\n",test);
		semop(write,up,1);
		exit(0);
	}
	else{
		int count = 0;
		while(count != 2){
			semop(write,down,1);
			shm->key = count;
			semop(read,up,1);
			count++;
		}
	}
	shmdt(shm);
	shmctl(shmid,IPC_RMID,NULL);
	semctl(read,0,IPC_RMID,0);
	semctl(write,0,IPC_RMID,0);
	return 0;
}
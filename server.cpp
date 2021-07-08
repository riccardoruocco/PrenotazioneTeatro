#include "procedure.h"
#define PR 0
#define SE 1

#define NS 50
int main(int argc,char* argv[])
{
	int pid,chiave_m,id_m;
	int chiave_s,id_s;
	buf* b;
	
	chiave_m=ftok(".",'a');
	chiave_s=ftok(".",'b');
	id_m=shmget(chiave_m,sizeof(buf),IPC_CREAT|IPC_EXCL|0664);
	if(id_m==-1){
		id_m=shmget(chiave_m,sizeof(buf),0|0664);
	}	
	if(id_m==-1){
		perror("\nErrore shmget\n");
		_exit(0);
	}	
	b=(buf*)shmat(id_m,NULL,0);	
	if(b==(void*)-1)
	{
		perror("\nErrore shmat\n");
		_exit(0);
	}
	id_s=semget(chiave_s,2,IPC_CREAT|IPC_EXCL|0664);
	if(id_s==-1){
		id_s=semget(chiave_s,2,0|0664);
	}
	semctl(id_s,PR,SETVAL,0);
	semctl(id_s,SE,SETVAL,0);

	wait_sem(id_s,PR);
	
	while((b->disp > 0) && (b->terminato != 1))
	{	
		leggi(b);
		printf("\n****************\n");
	}
	signal_sem(id_s,SE);
	printf("\nPrenotazioni Finite\n");		
	return 0;
}

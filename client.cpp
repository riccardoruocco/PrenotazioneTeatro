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
	
	//ora dobbiamo inizializzare il monitor
	init_monitor(&(b->m),1);
	b->disp=DIM;
	for(int i=0;i<DIM;i++)
	{
		(b->teatro[i]).stato=LIBERO;
		(b->teatro[i]).id_cliente=0;
	}
	signal_sem(id_s,PR); //visualizzatore può partire
	//ora dobbiam forkarci
	for(int i=0;i<NS;i++)
	{
		pid=fork();
		if(pid==0)
		{	
			scrivi(b,(i+1));
			i=NS;
		}
	}
	if(pid>0)
	{
		for(int i=0;i<NS;i++)
		{
			wait(NULL);
		}
		printf("\nProgramma Terminato\n");
		enter_monitor(&(b->m));				
		b->terminato=1;
		leave_monitor(&(b->m));
		
		wait_sem(id_s,SE);
		sleep(1);
		shmctl(id_m,IPC_RMID,0);
		remove_monitor(&(b->m));
		semctl(id_s,0,IPC_RMID);
	}



	return 0;
}

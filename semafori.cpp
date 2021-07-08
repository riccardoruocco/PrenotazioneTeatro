#include "semafori.h"

void wait_sem(int id_s,int n_s)
{
	struct sembuf sem_buf;
	sem_buf.sem_num=n_s;
	sem_buf.sem_flg=0;
	sem_buf.sem_op=-1;
	semop(id_s,&sem_buf,1);
}
void signal_sem(int id_s,int n_s)
{
	struct sembuf sem_buf;
	sem_buf.sem_num=n_s;
	sem_buf.sem_flg=0;
	sem_buf.sem_op=11;
	semop(id_s,&sem_buf,1);
}

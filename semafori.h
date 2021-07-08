#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>

#ifndef SEMAFORI_H
#define SEMAFORI_H

void wait_sem(int,int);
void signal_sem(int,int);

#endif

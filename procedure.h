
#include "monitor.h"
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<time.h>
#include "semafori.h"

#define DIM 80

#define LIBERO 0
#define OCCUPATO 1
#define INUSO 2
//risolviamo il problema con il modello lettori-scrittori con 50 scrittori ed un lettore

#ifndef PROCEDURE_H
#define PROCEDURE_H

typedef struct{
	int id_cliente=0;
	int stato=LIBERO;
}posto;
typedef struct{
	posto teatro[DIM];		
	int disp=DIM;
	Monitor m;
	int terminato=0;
}buf;

void scrivi(buf* b,int val);
void leggi(buf* b);
void stampa_teatro(posto* p);

#endif


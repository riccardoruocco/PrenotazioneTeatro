#include "procedure.h"

void scrivi(buf* b,int val){
	int tempo;	
	int n_posti;
	int cont=0;
	srand(val*time(0));	
	tempo=(rand()%60);
	sleep(tempo); //attendo un tempo tra 0 e 5s
	n_posti=1+(rand()%4);

	enter_monitor(&(b->m));
	//verifichiamo la disponibilita
	if((b->disp <= 0) || ((b->disp - n_posti) <= 0)){
		printf("\nDisponibilità Esaurita\n");
		leave_monitor(&(b->m));
		_exit(0);
	}
	for(int i=0;i<n_posti;i++)
	{
		while((b->teatro[cont]).stato != LIBERO)
		{
			cont++;
		}
		(b->teatro[cont]).stato = OCCUPATO;
		(b->teatro[cont]).id_cliente=getpid();
		cont = 0;
	}
	b->disp=b->disp-n_posti;
	printf("\nSono il cliente %d,prenoto",getpid());
	printf(" %d post",n_posti);
	if(n_posti==1){
		printf("o\n");
	}else if(n_posti>1){
		printf("i\n");
	}
	leave_monitor(&(b->m));
}
void leggi(buf* b){
	sleep(1);	
	enter_monitor(&(b->m));
	stampa_teatro(b->teatro);
	leave_monitor(&(b->m));




}
void stampa_teatro(posto* p){
	for(int i=0;i<DIM;i++)
	{
		printf("\nposto %d ",(i+1));
		if(p[i].stato == LIBERO)
		{
			printf("LIBERO ");
		}
		if(p[i].stato == OCCUPATO)
		{
			printf("OCCUPATO DA ");
			printf("%d",p[i].id_cliente);
		}
	}

}

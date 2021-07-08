 ``# PrenotazioneTeatro ``

Si vuole realizzare in linguaggio C/C++ un'applicazione multiprocesso per la simulazione di un servizio di prenotazione posti in un teatro che può ospitare fino ad 80 persone
L'applicazione è costituita da 50 processi client che possono prenotare da uno a 4 posti.
Ad ogni tentativo di prenotazione, il client stabilisce se c'è spazio, altrimenti termina subito con un messaggio di "disponibilità esaurita".
Se c'è disponiblità il client occupa i primi posti liberi che trova,assegnando ai posti il proprio id_cliente.
Si sviluppi inoltre un processo visualizzatore che stampa a video ogni secondo la situazione dei posti nel teatro scrivendo su ogni riga il numero di posto, lo stato, ed eventualmente il cliente che ha occupato il posto.


L'applicazione è stata sviluppata attraverso le primitive di sincronizzazione tipiche dei sistemi UNIX ed il tutto è stato provato su LINUX MINT.
L'utente che desidera provare l'applicaione su sistemi UNIX/LINUX deve:

1)copiare l'intero contenuto della cartella

2)Aggiornare la variabile d'ambiente del proprio sistema accodandogli il path fino alla cartella che contiene i file, cio può essere ottenuto aprendo una shell e digitando
```c
>>export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:@path_cartella
```
dove @path_cartella è  il path fino alla cartella che contiene i file,senza specificare nessuno dei file.

3)compilare l'applicazione attraverso il makefile digitando nella stessa shell aperta precedentemente
```c
>>make
```
4)aprire un'altra shell

5)lanciare,ognuno in una shell,i due eseguibili client e server con i comandi
```c
SHELL1
>>./client
```
```c
SHELL2
>>./server
```
è raccomandabile cercare di lanciare i due eseguibili quasi in contemporanea o comunque non far passare troppo tempo tra l'avvio delle esecuzioni.

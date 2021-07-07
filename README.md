# PrenotazioneTeatro
Si vuole realizzare in linguaggio C/C++ un'applicazione multiprocesso per la simulazione di un servizio di prenotazione posti in un teatro che può ospitare fino ad 80 persone
L'applicazione è costituita da 50 processi client che possono prenotare da uno a 4 posti e da un processo visualizzatore che stampa a video ogni secondo la situazione dei posti nel teatro.
Ad ogni tentativo di prenotazione, il client stabilisce se c'è spazio, altrimenti termina subito con un messaggio di "disponibilità esaurita".
Se c'è disponiblità il client occupa i primi posti liberi che trova,assegnando ai posti il proprio id_cliente.

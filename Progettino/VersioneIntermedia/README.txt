Progettino APCM
Valentina Astore e Giacomo Fregona

----- Esempio caso d'uso del progetto -----

L'ospedale di Trento dispone di un server attraverso cui recuperare il codice identificativo di una visita medica per effettuarne il pagamento. Per ottenere i propri codici, il paziente si collega al server e inserisce i propri nome e cognome, che verranno oscurati nella stampa a video per mantenere la privacy dell'utente. Se risultano pagamenti non esitinti, il server invierà l'elenco delle visite non ancora pagate e i relativi identificatori.


----- Struttura -----

Un Server(S) ed un Client(C), scritti in Java, comunicano mediante socket. I messaggi sono cifrati mediante AES128 in CFB mode, assumendo che le parti abbiano già scambiato una chiave ed un vettore di inizializzazione lunghi 128 bit.
S dispone di un database costituito da diversi file di testo. A ciascun file è assegnato un titolo e il suo contenuto è conservato in chiaro.

Le due parti (C ed S) interagiscono mediante il seguente protocollo:

    1. C si connette ad S (la stampa a video dei titoli disponibili è stata rimossa per rendere il progetto coerente con l'esempio di utilizzo proposto);
    2. l'utente del Client sceglie un titolo via console;
    3. C invia ad S il titolo cifrato;
    4. S decifra la richiesta e invia il contenuto del file corrispondente cifrato;
    5. C decifra il contenuto ricevuto e lo stampa a video.
    6. Si chiudono Stream e Socket di entrambe le parti.

C ed S utilizzano pipes per comunicare con i processi di cifratura e decifratura scritti in C.


----- Setup -----

Per compilare è possibile usare il MakeFile allegato.
Verranno generati gli eseguibi in C
	AES.Lib
	AES_CFB_E
	AES_CFB_D
e i bytecode in java
	Server.class
	Client.class
	AES_CFB_E.class
	AES_CFB_D.class.

Client e Server comunicano attraverso la porta 2022 resa disponibile dal Server.
Al loro interno, entrambe le parti chiamano i metodi di encryption e decryption delle classi java AES_CFB_E e AES_CFB_D rispettivamente. Tali metodi si appoggiano alle medesime procedure in C, che eseguono nel concreto la cifratura e decifratura dei messaggi scambiati tra Client e Server. La comunicazione tra Java e C avviene attraverso pipes, differenziate sia per Client/Server e per encryption/decryption, per un totale di 8 pipes distinte.
Le relazioni tra i due linguaggi possono essere schematizzate come segue: 

ENCRYPTION:

+--------+    Java2CEid     +---------+
|        |>---------------->|         |
|  Java  |                  |    C    | 	dove id = Client/Server
|        |<----------------<|         |
+--------+    C2JavaEid     +---------+


DECRYPTION:

+--------+    Java2CDid     +---------+
|        |>---------------->|         |
|  Java  |                  |    C    |  	dove id = Client/Server
|        |<----------------<|         |
+--------+    C2JavaDid     +---------+



----- How To -----

Generare i file
	mkfifo Java2CEClient
	mkfifo Java2CEServer
	mkfifo C2JavaEClient
	mkfifo C2JavaEServer

	mkfifo Java2CDClient
	mkfifo Java2CDServer
	mkfifo C2JavaDClient
	mkfifo C2JavaDServer

Lanciare i due processi
	java Server
	java Client


I processi in C di Client e Server vengono lanciati da appositi ProcessBuilders definiti all'interno di Client e Server.
Poichè non è possibile far eseguire direttamente i processi in background, i ProcessBuilders lanceranno un terminale per ogni processo, che a sua volta eseguirà il processo stesso.
In partcolare, il Server lancerà 2 terminali in cui verranno eseguiti
	./AES_CFB_E Server
	./AES_CFB_D Server
mentre il Client lancerà 2 terminali in cui verranno eseguiti
	./AES_CFB_E Client
	./AES_CFB_D Client.

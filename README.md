# homework1

# Corso ciberfisico univr

- Autore: Francesco trotti

- Data: 12/04/2018
# Esecuzione:

Per eseguire i vari nodi è stato implementato un launch file "launch/homework1.launch", eseguibile da terminale tramite il comando:
"roslaunch <nome_package> homework1.launch".

# Progettazione:

Sono stati implementati tre nodi talker, listener, handler 

# talker.cpp

Nodo che pubblica un messaggio al secondo sul topic "chatterTalker" composto da nome, età e corso di studi, strutturato nel file    "msg/messaggio.msg". 

# handler.cpp

Nodo che pubblica sul topic "chatterHandler" un messaggio composto da una carattere che corrisponde alla parte del messaggio da visualizzare, secondo un menù stampato a video:

Digita uno dei caratteri per visualizzare le eventuali infomazioni 
- a - Stampa tutto il messaggio 
- n - Stampa il nome
- e - Stampa l'età
- c - Stampa il corso di studi 
- q - Esci
 
# listener.cpp 

Nodo che ascolta il topic "chatterTalker" e "chatterHandler" da cui riceve la stringa completa, ne seleziona una parte in base al messaggio proveniente dal nodo handler e ne stampa il risultato a video ogni secondo.

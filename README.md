# galilei-4I

Progetto per esercizi e lezioni della **4I**.

ciao a Edoardo & Co

# Istruzioni per java pakages

Per creare sottocrtelle del vostro progetto che contengano packages la procedura è la seguente:

1. Dalla cartella principale del vostro progetto eseguire il seguente comando:
```
javac -d ./dist -sourcepath . -cp . <sottocartella>/*.java
```
Il comando prende la cartella corrente (.) del vostro progetto come fonte di tutti i file sorgente e di tutte le classi compilate ( opzione **-sourcepath** e **-cp**), compila tutti i file **.java** nella cartella \<sottocartella\> e ricrea la struttura di cartelle e file **.class** nella cartella **dist** del vostro progetto.
2. Sempre dalla cartella principale eseguire il comando:
```
javac -cp .;./dist Program.java
```
Il comando prende la cartella corrente (.) e la cartella **dist** come fonte di tutti i file sorgente e di tutte le classi compilate e compila la vostra classe principale con la funzione **Main**.
3. Eseguire il comando seguente epr lanciare il programma:
```
java -cp .;./dist Program 
```
Per il comando è essenziale l'opzione **-cp** che indica dove trovare le classi dei pacchetti compilate.

**NOTA**: per chi ha il Mac, nei punti 2 e 3, invece dei ";" nelle opzioni -cp, usate ":".
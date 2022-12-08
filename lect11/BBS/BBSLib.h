// Questa funzione setta le variabili globali n e X. Al suo interno saranno definiti p, q, etc.
void BBSSetup(int seed);
// Prende il bit meno significativo di X e lo restituisce in uint8_t
uint8_t outBit();
// Calcola un byte usando le funzioni outBit e nextX.
// Vedi l'implementazione di A5/1
uint8_t BBSByte();
// Calcola il valore successivo di X
void nextX();
// Libera la memoria allocata dalle variabili globali n e X allocate in BBSSetup.
void BBSEnd();


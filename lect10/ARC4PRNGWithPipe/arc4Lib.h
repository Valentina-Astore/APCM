#define MAXBUF  655536
#define MAXKEY      40
#define MAXFILE     30
// Aggiunto per la nuova versione con diversi lanci indipendenti di arc4!
#define NRMAXARC4 1000
// L'identificatore dello stato è dato da id. Esso è implementato in arc4Setup e arc4KeyStream
void swap(uint8_t *a, uint8_t *b);
void arc4Setup(int id, const uint8_t key[], uint8_t len);
void arc4KeyStream(int id, uint8_t out[], uint64_t len);
void arc4PrintState(int id);



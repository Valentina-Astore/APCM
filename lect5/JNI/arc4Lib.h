#define MAXBUF  655536
#define MAXKEY      40
#define MAXFILE     30


void swap(uint8_t *a, uint8_t *b);
void arc4Setup(const uint8_t key[], uint8_t len);
void arc4KeyStream(uint8_t out[], uint64_t len);
uint8_t arc4TranslateByte(uint8_t bytein);
void arc4PrintState();


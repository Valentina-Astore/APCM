#include <inttypes.h>
/* 
   Le Maschere  dei registri a cosa servono? 
*/
#define R1MASK	0x07FFFF /* 19 bit */
#define R2MASK	0x3FFFFF //22
#define R3MASK	0x7FFFFF //23


#define R1CLOCKBIT 8  
#define R2CLOCKBIT 10 
#define R3CLOCKBIT 10 

#define R1FBBITS 0x072000 /* Corrisponde ai  bit 18,17,16,13 */
#define R2FBBITS 0x600000 //22, 21
#define R3FBBITS 0xE00100 //23, 22, 21, 8

#define R1OUT	18  
#define R2OUT	21  
#define R3OUT	22  

struct registers {
  uint32_t val;
  uint32_t mask;
  uint8_t clockbit;
  uint32_t feedbackbits;
  uint8_t out;
}; 


void setupRegisters();
uint32_t parity(uint32_t x);
void updateRegister(uint8_t id);
void printRegister(uint8_t id);
void printRegisters();
void printOut(uint8_t id);
void updateAll();
void printMajority();
void updateMajority();
uint8_t outBit();
uint8_t outByte();
void printKeyFrame(uint8_t key[8], uint32_t frame);
void keySetup(uint8_t key[8], uint32_t frame);

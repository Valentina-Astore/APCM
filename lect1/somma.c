#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int i, sum = 0;

  for (i = 1; i < argc; i++) {
    sum += atoi(argv[i]);
  }

  printf("Somma=%d\n", sum);
}

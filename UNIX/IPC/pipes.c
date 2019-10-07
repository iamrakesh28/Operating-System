#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

const int SIZE = 16;

char *msg1 = "Message 1";
char *msg2 = "Message 2";
char *msg3 = "Message 3";

int main() {

  char buffer[SIZE];
  int p[2];
  if (pipe(p) < 0)
    exit(1);

  // p[1] -> writing end
  // p[0] -> reading end
  printf("%d %d\n", p[0], p[1]);
  write(p[1], msg1, SIZE);
  write(p[1], msg2, SIZE);
  write(p[1], msg3, SIZE);

  close(p[1]);
  while (read(p[0], buffer, SIZE) != 0)
    puts(buffer);
  close(p[0]);
  return 0;
}

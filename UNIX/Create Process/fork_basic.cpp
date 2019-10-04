#include <stdio.h>
#include <iostream>
#include <unistd.h>

using namespace std;

void create(void) {

  int pid = fork();
  if (pid == 0)
    puts("Child Process");
  else
    printf("Parent Process, pid = %d\n", pid);
  return;
}

int main() {
  create();
}

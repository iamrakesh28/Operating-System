#include <iostream>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

const int size = 100;

struct mesg_buffer {
  long type;
  char text[size];
} message, msg ;

void send(int msgid) {
  if (fork()) {
    wait(NULL);
    puts("Parent Exiting!");
    return;
  }
  msgrcv(msgid, &msg, sizeof(message), 1, 0);
  puts("Message from Child");
  puts(msg.text);
  msgctl(msgid, IPC_RMID, NULL);
  return;
}

int main() {

  key_t key;
  int msgid;

  key = ftok("/root/Desktop", 1);
  msgid = msgget(key, 0666 | IPC_CREAT);

  message.type = 1;
  fgets(message.text, sizeof(char) * size, stdin);
  msgsnd(msgid, &message, sizeof(message), 0);
  send(msgid);
  return 0;
}

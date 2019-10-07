#include <iostream>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std;

const int N = 100;

struct msg_buffer {
	long msg_type;
	char msg_text[N];
} message;

int main() {

	key_t key;
	int msgid;

	// ftok generates unique key
	key = ftok("/root/Desktop", 65);

	// msgget creates a message queue and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	// msgsnd to send message
	puts("Recieved Data :");
	puts(message.msg_text);

	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}

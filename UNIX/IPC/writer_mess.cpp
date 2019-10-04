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
	key = ftok("/root/Desktop", 1);

	// msgget creates a message queue and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.msg_type = 1;

	puts("Write Data : ");
	fgets(message.msg_text, sizeof(100) * N, stdin);

	// msgsnd to send message
	puts("Sent Data :");
	puts(message.msg_text);
	return 0;
}

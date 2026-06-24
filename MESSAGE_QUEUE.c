#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf
{
    long mtype;
    char mtext[100];
};

int main()
{
    struct msgbuf message;

    int msgid = msgget(1234, 0666 | IPC_CREAT);

    message.mtype = 1;
    strcpy(message.mtext, "Hello Queue");

    msgsnd(msgid, &message, sizeof(message.mtext), 0);

    msgrcv(msgid, &message, sizeof(message.mtext), 1, 0);

    printf("Received: %s\n", message.mtext);

    return 0;
}

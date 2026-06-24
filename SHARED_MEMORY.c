#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shmid;
    char *ptr;

    shmid = shmget(1234, 1024, 0666 | IPC_CREAT);

    ptr = (char *)shmat(shmid, NULL, 0);

    strcpy(ptr, "Hello Shared Memory");

    printf("Data in Shared Memory: %s\n", ptr);

    return 0;
}

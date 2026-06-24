7. Send the message "Hello Child" from the parent process to the child process through a pipe.
    
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    char buffer[100];

    pipe(fd);

    if(fork() == 0)
    {
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    }
    else
    {
        char msg[] = "Hello Child";
        write(fd[1], msg, strlen(msg)+1);
    }

    return 0;
}

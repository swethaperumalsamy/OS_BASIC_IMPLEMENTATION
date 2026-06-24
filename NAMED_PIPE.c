writer.c 

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;

    char msg[] = "Hello FIFO";

    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_WRONLY);

    write(fd, msg, strlen(msg) + 1);

    printf("Message Sent\n");

    close(fd);

    return 0;
}


reader.c


#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];

    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Received Message: %s\n", buffer);

    close(fd);

    return 0;
}

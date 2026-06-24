1. Create a file named test.txt and write the text "Hello Linux" into it.
    
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // Create and open the file
    fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write data to the file
    write(fd, "Hello Linux", 11);

    // Close the file
    close(fd);

    printf("Data written successfully to test.txt\n");

    return 0;
}

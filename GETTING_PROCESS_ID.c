2. Display the Process ID (PID) of the running program.
    
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process ID: %d\n", getpid());
    return 0;
}

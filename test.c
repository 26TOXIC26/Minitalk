#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    int id = getgid();
    printf("this is your prossec id: %d \n", id);
}
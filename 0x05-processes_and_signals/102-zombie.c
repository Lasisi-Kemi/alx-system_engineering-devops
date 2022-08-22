#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

/**
 * infinite_while - makes the process to sleep for 1 se
 *
 * Return: always success
 */
int infinite_while(void)
{
while (1)
{
sleep(1);
}
return (0);
}


/**
 * main - the driver code to create 5 zombie processes
 *
 * Return: always success
 */
int main(void)
{
pid_t child_pid;
int i = 0;

while (i < 5)
{
child_pid = fork();
if (child_pid == 0)
{
printf("Zombie process created, PID: %d\n", getpid());
exit(0);
}
i++;
}
infinite_while();

return (0);
}

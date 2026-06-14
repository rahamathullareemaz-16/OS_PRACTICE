#include <stdio.h>
#include <unistd.h>
#include <spawn.h>
#include <pthread.h>
#include <sys/wait.h>
extern char **environ;
void *numbers(void *arg)
{
    int i;
    for(i=1;i<=5;i++)
    {
        printf("Number = %d\n",i);
        sleep(1);
    }
    return NULL;
}
void *alphabets(void *arg)
{
    char ch;
    for(ch='A';ch<='E';ch++)
    {
        printf("Alphabet = %c\n",ch);
        sleep(1);
    }
    return NULL;
}
int main(int argc,char *argv[])
{
    if(argc>1)
    {
        pthread_t t1,t2;
        printf("Child PID = %d\n",getpid());
        pthread_create(&t1,NULL,numbers,NULL);
        pthread_create(&t2,NULL,alphabets,NULL);
        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
        return 0;
    }
    pid_t pid;
    printf("Parent PID = %d\n",getpid());
    char *args[] = {argv[0],"child",NULL};
    posix_spawn(&pid,argv[0],NULL,NULL,args,environ);
    wait(NULL);
    return 0;
}

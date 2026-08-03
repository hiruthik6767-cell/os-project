#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    pid_t pid;
    int status;
    printf("Parent process : PID = %d\n",getpid());
    pid = fork();
    if(pid < 0){
        perror("fork failed");
        exit(1);
    }
     else{
         printf("Parent waiting for child (PID= %d)to finish ....\n",pid);
         wait(&status);
         if(WIFEXITED(status))
         printf("Child terminated normally with  exit code %d\n ");
         else
         printf("Child terminated abnormally \n ");
         printf("Parent process finished execution.\n");
         
     }
    return 0;
}

/* To write a C program that demonstrates the use of fundamental UNIX operating system calls for
process management: fork(), wait(), and getpid(). */

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    pid_t pid;
    int status;
    
    // Create a new process
    pid = fork();
    if(pid == -1){
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }
    
    // Child process
    else if(pid == 0){
        printf("Child Process: PID = %d\n",getpid());
        printf("Child Process: Parent PID = %d\n",getppid());
        sleep(2);
        printf("Child Process Exiting...\n");
        exit(EXIT_SUCCESS);
    }
    
    // Parent process
    else{
        printf("Parent Process: PID = %d\n",getpid());
        printf("Parent Process: Child PID = %d\n",pid);
        waitpid(pid,&status,0);
        printf("Parent Process : child %d finished execution\n",pid);
    }
    
    return EXIT_SUCCESS;
}


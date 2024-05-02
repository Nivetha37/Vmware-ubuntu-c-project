/*
shmget() - used to create a new shared memory segment
shmat() - used to attach the shared memory segment
shmctl() - to remove shmid(can be used to get info about shmid)
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define SEGSIZE 100

//initialising variables

int main(int argc,char *argv[]){
    int shmid;
    key_t key;
    char *segptr;
    char buff[] = "I am Nivi..";
    
    key = ftok(".",'s');
    
// create shared memory
    if((shmid = shmget(key, SEGSIZE, IPC_CREAT|IPC_EXCL|0666))== -1)
    if((shmid = shmget(key,SEGSIZE,0)) == -1){
        perror("shmget");
        exit(1);
    }
    
    else{
        printf("\ncreated new shared memory");
        printf("\nSHMID: %d",shmid);
        system("ipc s -m");  // to get basic info about the created shared memory
    }
    
// attach the shared memory
    if((segptr = (char*)shmat(shmid,0,0))==(char*)-1){
        perror("shmat");
        exit(1);
    }
    
// writing data into shared memory
    printf("\nWritting data into the shared memory");
    strcpy(segptr,buff);
    segptr[SEGSIZE - 1] = '\0'; //creating a nul terminated string
    printf("\nDone");
    
//Reading data from shared memory
    printf("\nReading data from shared memory");
    printf("\nData: %s",segptr);
    printf("\nDone");

//removing shared memory
   printf("\nRemoving shared memory");
   if(shmctl(shmid,IPC_RMID,0)==-1){
       perror("shmctl");
       printf("\n can't remove shared memory");
   }
   else{
       printf("\nRemoved Successfully");
   }
 return 0;   
}

/*
mutex (mutual exclision) ---> to ensure shared memory is used by one at a time

full   --> to track the buffer(shared memory) is full or not
empty  --> to track the buffer(shared memory) is empty or not
wait   --> used to decrement the value
signal --> used to increment the value

x      --> represents the stock in the buffer
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    
    int mutex = 1; //initially it is in free state
    int full= 0   //initally buffer is empty nothing to fill
    int empty= 3;//here maximum buffer size is 3
    int x=0;    //since no buffer produced
    int n;     // to get choice from the user
    
    int wait(int s){
        return (--s);
    }
    
    int signal(int s){
        return (++s);
    }
    
    void producer(){
        mutex = wait(mutex);
        full = signal(full);
        empty = wait(empty);
        
        x++;
        printf("\n Producer produces items : %d",x);
        mutex = signal(mutex);
    }
    
    void consumer(){
        mutex = wait(mutex);
        full = wait(full);
        empty = signal(empty);
        
        printf("\nConsumer consumes item: %d",x);
        x--;
        mutex = signal(mutex);
    }
    
    printf("\n 1. producer \n 2. Consumer \n 3. Exit");
    
    while(1){
        printf("\n Enter your choice:");
        scanf("%d",&n);
        
        switch(n){
            
            case 1 : 
            if(mutex==1 && empty !=0)
            producer();
            else
            printf("\n Buffer is full");
            break;
            
            
            case 2:
            if(mutex==1 && full!=0)
            consumer();
            else
            printf("\n Buffer is empty");
            break;
            
            case 3:
            exit(0);
            break;
            
            default:
            printf("\nInvalid Choice");
        
        }
    }
    
  return 0;  
}

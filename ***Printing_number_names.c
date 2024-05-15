//If 1<=n<=9 , then print the lowercase English word corresponding to the number (e.g., one for , two for , etc.); otherwise, print Greater than 9 instead.

#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    
    char *a[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    if(n>=1 && n<=9){
        printf("%s",a[n-1]);
    }
    else{
        printf("Greater than 9");
    }
}

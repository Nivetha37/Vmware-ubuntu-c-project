#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b, n;
    scanf("%d\n%d", &a, &b);
    char *arr[9]={"one","two","three","four","five","six","seven","eight","nine"};
  	for(n=a;n<=b;n++){
          if(n>=1 && n<=9){
              printf("%s\n",arr[n-1]);
          }
          else if(n%2==0){
              printf("even\n");
          }
          else{
              printf("odd\n");
          }
      }

    return 0;
}


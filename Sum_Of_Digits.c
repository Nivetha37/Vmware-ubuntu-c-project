/*Given a five digit integer, print the sum of its digits.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,r,temp,sum=0;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    for(int i =0;i<5;i++){
        r = n % 10;
        sum += r;
        n = n / 10;
    }
    
    printf("%d",sum);
    return 0;
}

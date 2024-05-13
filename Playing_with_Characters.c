#include<stdio.h>

int main(){
    char ch;
    char s[100];
    char sen[100];
    
    scanf("%c%s\n%[^\n]%*c",&ch,s,sen);
    printf("%c\n%s\n%s",ch,s,sen);
   
    
    return 0;
}


/*-------------------( or )-----------------
    
    scanf("%c",&ch);
    scanf("%s",s);
    scanf("\n");
    scanf("%[^\n]%*c",sen);
    
    
    printf("%c\n",ch);
    printf("%s\n",s);
    printf("%s",sen);

--------------------------------------------*/

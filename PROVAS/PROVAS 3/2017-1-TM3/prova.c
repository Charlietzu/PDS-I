#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int numEspacos(char *str){
    int i;
    for(i = 0; str[i]!='\0'; i++);

    if(i == 0 && str[i]!=' '){
        return 0;
    }
    
    if(str[i] == ' '){
        return 1 + numEspacos(&str[i - 1]);
    }else{
        return numEspacos(&str[i - 1]);
    } 
    
}

void imp2Cont(int i, int n){
    if(i == n){
        printf("%d\n", i);
        return;
    }
    printf("%d\n", i);
    imp2Cont(i+1, n);
    printf("%d\n", i);
   
}

int main(){
    imp2Cont(1,3);
    return 0;
}
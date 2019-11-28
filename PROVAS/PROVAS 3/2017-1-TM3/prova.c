#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int numEspacos(char *str){
    if(str[0] == '\0'){
        return 0;
    }
    if(str[0] == ' '){
        return 1 + numEspacos(str + 1);
    }
    return 0 + numEspacos(str + 1);
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
    char str[100] = "oi tudobem";
    printf("%d", numEspacos(str));
    return 0;
}
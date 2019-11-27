#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

char* split(char **s, int n, int pos){
    char *part1 = (char*)malloc((1+pos)*sizeof(char));
    char *part2 = (char*)malloc((1+n-pos)*sizeof(char));
    
    int i;
    for(i = 0; i < n; i++){
        if(i < pos){
            part1[i] = (*s)[i];
        } else {
            part2[i - pos] = (*s)[i];
        }
    }

    part1[pos] = '\0';
    part2[n-pos] = '\0';
    free(*s);
    *s = part1;
    return part2;
}

int main(){

    return 0;
}
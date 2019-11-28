#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

int divide(int n, int k){
    if(k == 1){
        return n;
    }
    if(n == 0){
        return 0;
    }
    if(n - k < 0){
        return 0;
    }
    return 1 + divide(n-k, k);
}

int menor(int v[], int n){
    if(n == 1){
        return v[0];
    }
    if(v[n-1] < v[0]){
        v[0] = v[n-1];
    }
    menor(v, n-1);

}

int main(){
    int v[7] = {9, -1, 4, 2, -2, 0, 4};
    printf("%d", menor(v, 7));

    return 0;
}
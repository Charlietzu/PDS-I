#include <stdio.h>
#include <stdlib.h>

int divide(int n, int k){
    if(n < k){
        return 0;
    }
    return 1 + divide(n - k, k);
}

int menor(int v[], int n){
    if(n <= 1){
        return v[0];
    }
    int x = menor(v, n-1);
    if(x < v[n-1]){
        return x;
    }
    return v[n-1];
    
}

int main(){
    
    return 0;
}
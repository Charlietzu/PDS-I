#include <stdio.h>

int fibonacci(int n){
  int fib[n];
  int i = 0;
  for(i = n; i >= 0; i--){
    fib[i] += fib[i];
  }

}

int main(){

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
long long int fact_rec(int n){
  if(n == 0 || n == 1){
    return 1;
  }
  else{
    return(n*fact_rec(n-1));
  }
}
long long int fact_iter(int n){
  long long int x=1;

  for (size_t i = n; i > 1; i--) {
    x = x*i;
  }
  return x;
}
int main() {
  int n;
  scanf("%d", &n);
  if(n<0){
    printf("factorial of negative numbers not possible\n");
    exit(0);
  }
  printf("%lld\n", fact_rec(n));
  printf("%lld\n", fact_iter(n));
  return 0;
}

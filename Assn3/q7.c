#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80
int chrtoint(char c){  //converts char c to integer
  int i = (int)c -48;
  return i;
}
char* padzeroes(char* a, int n) {
  char *new, zeroes[n+1];
  new = (char*)malloc((n+strlen(a)+1)*sizeof(char));
  int i;
  for (i = 0; i < n; i++) {
    zeroes[i] = '0';
  }
  zeroes[i] = '\0';
  strncat(new, a, strlen(a));
  strncat(new, zeroes, n);
  return new;
}
char *strrev(char *str, int len){  //reverses a string
  char *str_r;
  str_r = (char *)malloc((len+1)*sizeof(char));
  for (int i = 0, j=len-1; i < len && j>=0; i++, j--) {
    str_r[i] = str[j];
  }
  str_r[len] = '\0';
  return str_r;
}
char* add(char* a, char* b) {
  char* sum;
  int l1 = strlen(a);
  int l2 = strlen(b);
  int l, carry=0;
  char* c;
  if (l1>=l2) {
    l = l1;
    b = padzeroes(b, l1-l2);
  } else {
    l = l2;
    a = padzeroes(a, l2-l1);
  }
  sum = (char *)malloc((l+2)*sizeof(char));
  for (int i = 0; i < l; i++) {
    sum[i] = (carry+chrtoint(a[i])+chrtoint(b[i]))%10 + 48;
    carry = (carry+chrtoint(a[i])+chrtoint(b[i]))/10;
  }
  sum[l] = carry + 48;
  sum[l+1] = '\0';
  c = strrev(sum, l+1);
  while (*c == '0' ) {
    c++;
  }return c;
}
char* complement(char* a){
  int l=strlen(a), i;
  char* new = (char*)malloc((l+1)*sizeof(char));
  for (i = 0; i < l; i++) {
    new[i] = '9' - a[i]+48;
  }
  new[0] = (chrtoint(new[0]) + 1)%10 +48;
  int carry = (chrtoint(new[0]) + 1)/10;
  new[1] = new[1]+carry;
  new[i] = '\0';
  return new;
}
char* difference(char* a, char* b){
  char* sub;
  char* c;
  char* d;
  int l1 = strlen(a);
  int l2 = strlen(b), i;
  int carry=0;
  int comp;
  sub = (char*)malloc((l1+2)*sizeof(char));
  if (l1 > l2) {
    comp = 1;
    d = complement(b);
    c = padzeroes(d, l1-l2);
  } else if (l1 < l2) {
    comp = 2;
    c = complement(b);
    a = padzeroes(a, l1-l2);
  }else{
    if (strcmp(a, b) > 0) {
      comp = 1;
      c = complement(b);
    } else if(strcmp(a, b) < 0){
      comp = 2;
      c = complement(b);
    }else{
      sub[0] = '0';
      sub[1] = '\0';
      return sub;
    }
  }
  for (i = 0; i < l1 - 1; i++) {
    sub[i] = (carry+chrtoint(a[i])+chrtoint(c[i]))%10 + 48;
    carry = (carry+chrtoint(a[i])+chrtoint(c[i]))/10;
  }sub[i] = (chrtoint(a[i])+chrtoint(c[i]))%10+48;
  i++;
  switch (comp) {
    case 1: sub[i] = '\0'; return strrev(sub, l1); break;
    case 2: d = strrev(sub, l1);
      while (*d == '0' ) {
        d++;
      }
      return d;
  }
}
int main(int argc, char const *argv[]) {
  char in1[MAX], in2[MAX];
  printf("a=");
  scanf("%[^\n]s", in1);
  printf("b=");
  scanf(" %[^\n]s", in2);
  char* a = strrev(in1, strlen(in1));
  char* b = strrev(in2, strlen(in2));
  printf("a+b:%s\n", add(a, b));
  printf("a-b:%s\n", difference(a, b));
  return 0;
}

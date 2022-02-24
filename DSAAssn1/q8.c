#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int chrtoint(char c){  //converts char c to integer
  int i = (int)c -48;
  return i;
}
char *strrev(char *str, int len){  //reverses a string
  char *str_r;
  str_r = (char *)malloc((len+1)*sizeof(char));
  for (int i = 0, j=len-1; i < len, j>=0; i++, j--) {
    str_r[i] = str[j];
  }
  str_r[len] = '\0';
  return str_r;
}
char *add(char *s1, char *s2){  //adds two large character array of numbers
  char *sum;
  int len = strlen(s1), carry = 0;
  sum = (char *)malloc((len+2)*sizeof(char));
  for (int i = 0; i < len; i++) {
    sum[i] = (carry+chrtoint(s1[i])+chrtoint(s2[i]))%10 + 48;
    carry = (carry+chrtoint(s1[i])+chrtoint(s2[i]))/10;
  }
  sum[len] = carry + 48;
  sum[len+1] = '\0';
  return strrev(sum, len+1);
}
void break_and_modulo(char *str, int a) {  //finds the modulus when divited by a 4digit prime
  int len = strlen(str), res=0;
  char str1[len/2], str2[len/2], *sum;
  strncpy(str1, str, len/2);
  strncpy(str2, str+(len/2), len/2);
  sum = add(strrev(str1, len/2), strrev(str2, len/2));
  printf("The sum of the 2 halves:%s\n", sum);
  for (size_t i = 0; i < strlen(sum); i++) {
     res = (res * 10 + chrtoint(sum[i])) % a;
  }
  printf("The remainder dividing with %d comes to:%d\n", a, res);
}
int main(int argc, char const *argv[]) {
  char *name = "DEBARGHYAMAITRA";
  int len = strlen(name);
  char *encoded;
  encoded = (char *)malloc((2*len+1)*sizeof(char));
  int i=0, temp;
  char t[4];
  for (size_t j = 0; j < len; j++) {
    i=0;
    temp = (int)name[j];
    while (temp != 0) {
      t[1-i] = temp%10 +48;
      temp = temp/10;
      i++;
    }
    t[2] = '\0';
    strncat(encoded, t, 3);
  }
  printf("The name is:%s\n", name);
  printf("The encoded name becomes:%s\n", encoded);
  break_and_modulo(encoded, 7919);
  return 0;
}

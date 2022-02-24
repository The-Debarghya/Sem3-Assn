#include <stdio.h>
#include <stdlib.h>
#include <time.h>
FILE *fp;
void getRandomStr(){
    int i;
    char s1[11];
    for (i = 0; i < 10; i++){
        char c = (rand() % 26) + 'A';
        s1[i] = c;
    }
    s1[10] = '\0';
    fprintf(fp, "%s\n", s1);
}
int main(int argc, char const *argv[]) {
  fp = fopen("Rand_Strs.txt", "w+");
  srand(time(NULL));
  for (size_t i = 0; i < 100000; i++) {
    getRandomStr();
  }
  fclose(fp);
  return 0;
}

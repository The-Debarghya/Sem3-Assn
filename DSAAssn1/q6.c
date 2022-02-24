#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp1, *fp2;
void sort() {
  fp1 = fopen("unsortednames.txt", "r");
  if(fp1 == NULL){
      printf("Error in opening file \n");
      exit(0);
  }
  char names[100][80], temp[80];
  char c;
  int i = 0;
  c = getc(fp1);
  while(c != EOF){
      ungetc(c, fp1);
      fgets(names[i], 80, fp1);
      i++;
      c = getc(fp1);
  }
  fclose(fp1);
  for(int j=0;j<=i;j++){
      for(int k=j+1;k<=i;k++){
          if(strcmp(names[j],names[k])>0){
              strncpy(temp,names[j], 80);
              strncpy(names[j],names[k], 80);
              strncpy(names[k],temp, 80);
          }
      }
  }
  fp2 = fopen("sortednames.txt", "w+");
  for(int j=0; j<=i; j++){
      fprintf(fp2, "%s", names[j]);
  }
  fclose(fp2);
}
int main(){
    sort();
    FILE *fp;
    char names[100][80], c, *p, bigname[80], smallname[80];
    int i=0;
    fp = fopen("sortednames.txt", "r");
    if(fp1 == NULL){
        printf("Error in opening file \n");
        exit(0);
    }
    c = getc(fp1);
    while(c != EOF){
        ungetc(c, fp1);
        fgets(names[i], 80, fp1);
        if ((p=strchr(names[i], '\n')) != NULL) *p = '\0';
        i++;
        c = getc(fp1);
    }
    fclose(fp);
    strncpy(bigname, names[0], 80);
    strncpy(smallname, names[0], 80);
    for (size_t j = 1; j < i; j++) {
      if (strlen(names[j])>strlen(bigname)) {
        strncpy(bigname, names[j], 80);
      }
      if (strlen(names[j])<strlen(smallname)) {
        strncpy(smallname, names[j], 80);;
      }
    }
    printf("longest name:%s, length:%ld \nsmallest name:%s, length:%ld\n", bigname, strlen(bigname), smallname, strlen(smallname));
    return 0;
}

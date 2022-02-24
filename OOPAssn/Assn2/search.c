#include "defn.h"

extern int search(int roll) {  //to search for record of a given roll
  FILE *fp;
  struct records st;
  int ct = 0;
  fp = fopen("Student_Records.bin", "rb");
  if (fp == NULL) {  //check if file exists/can be opened or not
    return 0;
  }
  while(fread(&st, sizeof(struct records), 1, fp)){
    if (st.roll == roll) {                        //read each block and check if it matches the roll
      ct++;
      return ct;  //returns the position of the roll
    }
    ct++;
  }
  fclose(fp);
  return 0;  //if roll not found returns 0
}

extern void search_display(int roll) {
  FILE *fp;
  struct records st;
  fp = fopen("Student_Records.bin", "rb");
  if (fp == NULL) {  //check if file exists/can be opened or not
    printf("Couldn't open file\n");
  }
  while(fread(&st, sizeof(struct records), 1, fp)){
    if (st.roll == roll) {                        //read each block and check if it matches the roll
       printf("\nName:%s, Marks in 5 subjects:%d, %d, %d, %d, %d\n", st.name, st.marks.subj1, st.marks.subj2, st.marks.subj3, st.marks.subj4, st.marks.subj5);
       return;
    }
  }
  fclose(fp);
  printf("Roll not found!!\n");  //if roll not found returns 0
}

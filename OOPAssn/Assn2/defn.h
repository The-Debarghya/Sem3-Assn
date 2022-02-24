#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef CHAR_BUFF
#define CHAR_BUFF 80

typedef struct{   //struct containing marks of 5 subjects
	int subj1;
	int subj2;
	int subj3;
	int subj4;
	int subj5;
} subj;
struct records {  //struct containing name roll and marks
  int roll;
  char name[CHAR_BUFF];
  subj marks;
};
int search(int);
void logical_delete(int);
void physical_delete();
void edit_name(int);
void edit_marks(int);
void search_display(int);
#endif

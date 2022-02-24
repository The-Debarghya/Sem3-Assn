/*Write a program to store student information in a file and to do the following operations:
Information includes roll, name, and score in five subjects.
User may like to add record (ensure roll number is unique),
Display all records showing roll, name and total score.
User may search for the record against a roll.
User may edit the details a record.
User may delete record. Deletion may be logical (by some means indicate it is an invalid record and to be avoided in processing)
and physical (file will not have the record).*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
int search_roll(int roll) {  //to search for record of a given roll
  FILE *fp;
  struct records st;
  fp = fopen("Student_Records.bin", "rb");
  if (fp == NULL) {  //check if file exists/can be opened or not
    return 0;
  }
  while(fread(&st, sizeof(struct records), 1, fp)){
    if (st.roll == roll) {                        //read each block and check if it matches the roll
      printf("\nName:%s, Marks in 5 subjects:%d, %d, %d, %d, %d\n", st.name, st.marks.subj1, st.marks.subj2, st.marks.subj3, st.marks.subj4, st.marks.subj5);
      return 1;  //prints the roll and returns 1
    }
  }
  fclose(fp);
  return 0;  //if roll not found returns 0
}
void add_rec() {  //insert a new record
  struct records student;
	char *p;
  printf("Enter roll number: ");
  scanf("%d", &student.roll);
  if(search_roll(student.roll)){  //check if entered roll is already present or not
    printf("Roll is present is present, You can edit instead!!\n");
    return;                       //if present return to main
  }
  printf("Enter name:");
	while ((getchar()) != '\n');
	fgets(student.name, CHAR_BUFF, stdin);
	if ((p=strchr(student.name, '\n')) != NULL) *p = '\0';
  printf("Enter marks in 5 subjects: ");
  scanf("%d %d %d %d %d", &student.marks.subj1, &student.marks.subj2,&student.marks.subj3,&student.marks.subj4,&student.marks.subj5);
  FILE *fp;
  fp = fopen("Student_Records.bin", "ab");
  if (fp == NULL) {
    printf("error in opening file\n");
    exit(EXIT_FAILURE);
  }
  fwrite(&student, sizeof(struct records), 1, fp);
  printf("\nFile updated Successfully!!\n");
  fclose(fp);
}
void display_all() {  //displays all saved records
  struct records st;
  FILE *fp;
  int total;
  fp = fopen("Student_Records.bin", "rb");
  if (fp == NULL) {
    printf("\nError in opening file/ the file doesn't exist!!\n");
    return;
  }
  while(fread(&st, sizeof(struct records), 1, fp)){

    if(st.roll>0){   //checks if a saved record is a valid entry or not
      total = st.marks.subj1+st.marks.subj2+st.marks.subj3+st.marks.subj4+st.marks.subj5;
      printf("\nRoll:%d, Name:%s, Total Marks in 5 Subjects:%d\n", st.roll, st.name, total);
    }
    else{
      continue;
    }
  }
  fclose(fp);
}
void edit_name(int roll) {  //edits the name of a specified roll
  FILE *fp;
  struct records st, temp;
  temp.roll = roll;
	char *p;
  fp = fopen("Student_Records.bin", "r+");
  if (fp == NULL) {
    return;
  }

  while(fread(&st, sizeof(struct records), 1, fp)){
    if (st.roll == roll) {
      fseek(fp, -sizeof(struct records), 1);  //if roll found put the file pointer to the beginning of the particular record
      printf("Enter new name:");
			while ((getchar()) != '\n');
			fgets(temp.name, CHAR_BUFF, stdin);
			if ((p=strchr(temp.name, '\n')) != NULL) *p = '\0';
			temp.marks = st.marks;
      fwrite(&temp, sizeof(struct records), 1, fp);  //replace with new record
      fclose(fp);
      printf("\nData for roll %d updated Successfully!!\n", roll);
      return;
    }
  }
  printf("\nRoll not found!!\n");
  return;
}
void edit_marks(int roll) {  //edits the marks of a specified roll
  FILE *fp;
  struct records st, temp;
  temp.roll = roll;
  fp = fopen("Student_Records.bin", "r+");
  if (fp == NULL) {
    return;
  }
  while(fread(&st, sizeof(struct records), 1, fp)){
    if (st.roll == roll) {
      fseek(fp, -sizeof(struct records), 1); //if roll found put the file pointer to the beginning of the particular record
      printf("Enter marks of 5 subjects:");
      scanf("%d %d %d %d %d", &temp.marks.subj1, &temp.marks.subj2,&temp.marks.subj3,&temp.marks.subj4,&temp.marks.subj5);
			strncpy(temp.name, st.name, CHAR_BUFF);
      fwrite(&temp, sizeof(struct records), 1, fp);
      fclose(fp);
      printf("\nData for roll %d updated Successfully!!\n", roll);
      return;
    }
  }
  printf("\nRoll not found\n");
  return;
}
void logical_delete(int roll) {  //logically delete a record by making the roll negative
  FILE *fp;
  struct records st;
  fp = fopen("Student_Records.bin", "r+");
  if (fp == NULL) {
    return;
  }
  while(fread(&st, sizeof(struct records), 1, fp)){
    if (st.roll == roll) {
      fseek(fp, -sizeof(struct records), 1);  //if roll found put the file pointer to the beginning of the particular record
      st.roll = -roll;                        //make the roll negative to make the record invalid
      fwrite(&st.roll, sizeof(int), 1, fp);
      fclose(fp);
      printf("\nData deleted for roll %d!!\n", roll);
      return;
    }
  }
  printf("\nRoll not found!!\n");
  return;
}
void physical_delete() {   //actually deletes the invalid records
  FILE *fp1, *fp2;
  struct records st;
  fp1 = fopen("Student_Records.bin", "rb");
  fp2 = fopen("temp.bin", "wb");   //a temporary file to store the valid records
  if (fp1 == NULL || fp2 == NULL) {
    printf("\nerror in opening file\n");
    exit(EXIT_FAILURE);
  }
  fseek(fp1, 0L, 0);
  while(fread(&st, sizeof(struct records), 1, fp1)) {
    if (st.roll > 0) {
      fwrite(&st, sizeof(struct records), 1, fp2);
    } else {
      continue;
    }
  }
  fclose(fp1);
  fclose(fp2);
  system("cp temp.bin Student_Records.bin");    //system call to overwrite the contents of Student_Records with temp
  system("rm -f temp.bin");    //then remove the temp file
}
int main() {
  int choice, r;
  printf("\n1.Add a record \n2.Display all the records from file\n3.Search a record by Roll\n4.Edit name of a record for a roll\n5.Edit marks for a roll\n6.Delete a record\n7.Exit\n");

  do {
    printf("Enter a choice:");
    scanf("%d", &choice);
    switch (choice) {   //menu to perform action as required
      case 1: add_rec(); break;
      case 2: display_all(); break;
      case 3:
        printf("Enter roll to search:");
        scanf("%d", &r);
        int t = search_roll(r);  //check the return value of search_roll()
        if(!t){                  //if 0 then roll is not present
          printf("\nRoll not found!!\n");
        }
        break;
      case 4:
        printf("Enter roll of person to edit:");
        scanf("%d", &r);
        edit_name(r);
        break;
			case 5:
				printf("Enter roll of person to edit:");
				scanf("%d", &r);
				edit_marks(r);
				break;
      case 6:
        printf("Enter roll to delete:");
        scanf("%d", &r);
        logical_delete(r);        //perform logical delete always when program is active
        break;
      case 7: physical_delete();   //before closing delete all invalid records
        exit(0);
        break;
			default: printf("\n1.Add a record \n2.Display all the records from file\n3.Search a record by Roll\n4.Edit name of a record for a roll\n5.Edit marks for a roll\n6.Delete a record\n7.Exit\n");
    }
  } while(1);
  return 0;
}

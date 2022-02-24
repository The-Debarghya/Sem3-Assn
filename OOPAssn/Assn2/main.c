/*Write a program to store student information in a file and to do the following operations:
Information includes roll, name, and score in five subjects.
User may like to add record (ensure roll number is unique),
Display all records showing roll, name and total score.
User may search for the record against a roll.
User may edit the details a record.
User may delete record. Deletion may be logical (by some means indicate it is an invalid record and to be avoided in processing)
and physical (file will not have the record).*/

#include "defn.h"


void add_rec() {  //insert a new record
  struct records student;
	char *p;
  printf("Enter roll number: ");
  scanf("%d", &student.roll);
  if(search(student.roll)){  //check if entered roll is already present or not
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
        search_display(r);  //check the return value of search_roll()
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

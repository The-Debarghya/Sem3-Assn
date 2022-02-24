#include "defn.h"
extern void edit_name(int roll) {  //edits the name of a specified roll
  FILE *fp;
  struct records st;
  st.roll = roll;
	char *p;
	int n;
  fp = fopen("Student_Records.bin", "r+");
  if (fp == NULL) {
    return;
  }
	n = search(roll);
	if (n) {
		fseek(fp, (n-1)*sizeof(struct records), 0);
		fread(&st, sizeof(struct records), 1, fp);
		printf("Enter new name:");
		while ((getchar()) != '\n');
		fgets(st.name, CHAR_BUFF, stdin);
		if ((p=strchr(st.name, '\n')) != NULL) *p = '\0';
    fseek(fp, -sizeof(struct records), 1);
		fwrite(&st, sizeof(struct records), 1, fp);  //replace with new record
		fclose(fp);
		printf("\nData for roll %d updated Successfully!!\n", roll);
		return;
	} else {
		printf("\nRoll not found!!\n");
	  return;
	}
}
extern void edit_marks(int roll) {  //edits the marks of a specified roll
  FILE *fp;
  struct records st;
	int n;
  fp = fopen("Student_Records.bin", "r+");
  if (fp == NULL) {
    return;
  }
  n = search(roll);
	if (n) {
		fseek(fp, (n-1)*sizeof(struct records), 0); //if roll found put the file pointer to the beginning of the particular record
		fread(&st, sizeof(struct records), 1, fp);
		printf("Enter marks of 5 subjects:");
		scanf("%d %d %d %d %d", &st.marks.subj1, &st.marks.subj2,&st.marks.subj3,&st.marks.subj4,&st.marks.subj5);
    fseek(fp, -sizeof(struct records), 1);
    fwrite(&st, sizeof(struct records), 1, fp);
		fclose(fp);
		printf("\nData for roll %d updated Successfully!!\n", roll);
		return;
	} else {
		printf("\nRoll not found\n");
	  return;
	}
}

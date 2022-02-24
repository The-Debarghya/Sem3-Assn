#include "defn.h"

extern void logical_delete(int roll) {  //logically delete a record by making the roll negative
  FILE *fp;
  struct records st;
  fp = fopen("Student_Records.bin", "r+");
  if (fp == NULL) {
    return;
  }
	int n = search(roll);
	if (n) {
		fseek(fp, (n-1)*sizeof(struct records), 0);  //if roll found put the file pointer to the beginning of the particular record
		fread(&st.roll, sizeof(int), 1, fp);
		st.roll = -roll;                        //make the roll negative to make the record invalid
    fseek(fp, -sizeof(int), 1);
    fwrite(&st.roll, sizeof(int), 1, fp);
		fclose(fp);
		printf("\nData deleted for roll %d!!\n", roll);
		return;
	} else {
		printf("\nRoll not found!!\n");
	  return;
	}
}
extern void physical_delete() {   //actually deletes the invalid records
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

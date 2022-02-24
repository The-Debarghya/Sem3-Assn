/*this header provides basic functions to add, search for and list members*/
#ifndef MEMBER_H  //header guard
#define MEMBER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 41
typedef struct{
  int id;
  char name[SIZE];
  char email[SIZE];
  int issues;  //a constant that identifies if a member is a student or faculty
  int issued;  //keeps track of number of issues made by a member
} member;
int search_member(int id) {  //looks for a particular member
  FILE *fp;
  member st;
  int ct = 0;
  fp = fopen("members.dat", "rb");
  if (fp == NULL) {
    return 0;
  }
  while(fread(&st, sizeof(member), 1, fp)){
    if (st.id == id) {
      ct++;
      return ct;
    }
    ct++;
  }
  fclose(fp);
  return 0;
}
void register_member() {  //add a new member in the file
  member m;
  char *p;
  int c;
  printf("Enter member ID: ");
  scanf("%d", &m.id);
  if(search_member(m.id)){
    printf("Member ID is present, You can edit instead!!\n");
    return;
  }
  printf("Enter name:");
	while ((getchar()) != '\n');
	fgets(m.name, SIZE, stdin);
	if ((p=strchr(m.name, '\n')) != NULL) *p = '\0';
  printf("Enter email:");
	while ((getchar()) != '\n');
	fgets(m.email, SIZE, stdin);
	if ((p=strchr(m.email, '\n')) != NULL) *p = '\0';
  m.issued = 0;
  printf("1.Faculty 2.Student?");
  scanf(" %d", &c);
  if (c == 1) {
    m.issues = 10;
  } else {
    m.issues = 2;
  }
  FILE *fp;
  fp = fopen("members.dat", "ab");
  if (fp == NULL) {
    printf("error in opening file\n");
    exit(EXIT_FAILURE);
  }
  fwrite(&m, sizeof(member), 1, fp);
  printf("\nMember registered Successfully!!\n");
  fclose(fp);
}
void display_all() {  //displays all saved records
  member st;
  FILE *fp;
  fp = fopen("members.dat", "rb");
  if (fp == NULL) {
    printf("\nError in opening file/ the file doesn't exist!!\n");
    return;
  }
  while(fread(&st, sizeof(member), 1, fp)){
    if(st.id>0){
      printf("\nMember ID:%d, Name:%s, Email:%s, ", st.id, st.name, st.email);
      if (st.issues == 2) {
        printf("Designation: Student\n");
      } else {
        printf("Designation: Faculty\n");
      }
    }
    else{
      continue;
    }
  }
  fclose(fp);
}
int make_issue(int id) {   //after validating the issue it updates the number of issues of a member
  int ct = search_member(id);
  FILE *fp;
  member m;
  if (ct) {
    fp = fopen("members.dat", "r+");
    fseek(fp, (ct-1)*sizeof(member), 0);
    fread(&m, sizeof(member), 1, fp);
    if (m.issues == 2) {
      if (m.issued <= 1 && m.issued >= 0) {
        m.issued = m.issued+1;
        fseek(fp, -sizeof(member), 1);
        fwrite(&m, sizeof(member), 1, fp);
        fclose(fp);
        return 1;
      } else {
        printf("A student can't issue more than 2 books!\n");
        fclose(fp);
        return 0;
      }
    }else{
      if (m.issued <= 9 && m.issued >= 0) {
        m.issued = m.issued+1;
        fseek(fp, -sizeof(member), 1);
        fwrite(&m, sizeof(member), 1, fp);
        fclose(fp);
        return 1;
      } else {
        printf("A faculty member can't issue more than 10 books!\n");
        fclose(fp);
        return 0;
      }
    }
  } else {
    printf("The member with that ID not found!\n");
    return 0;
  }
}
int revoke_issue(int id) {  //updates number of issues by a member after validating a proper book reurn
  int ct = search_member(id);
  FILE *fp;
  member m;
  if (ct) {
    fp = fopen("members.dat", "r+");
    fseek(fp, (ct-1)*sizeof(member), 0);
    fread(&m, sizeof(member), 1, fp);
      if (m.issued >= 1) {
        m.issued = m.issued-1;
        fseek(fp, -sizeof(member), 1);
        fwrite(&m, sizeof(member), 1, fp);
        return 1;
      }
      else {
        return 0;
      }
  } else {
    printf("The member with that ID not found!\n");
    return 0;
  }
  fclose(fp);
}
#endif

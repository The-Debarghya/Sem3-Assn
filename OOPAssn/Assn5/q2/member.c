#include "member.h"
int main() {
  int choice, ct, i;
  FILE *fp;
  member st;
  do { 
    printf("1.Register a new member\n2.Search for a member\n3.Display all members\n4.Exit\n");
    printf("Enter a choice:");
    scanf(" %d", &choice);
    switch (choice) {
      case 1: register_member(); break; //new member
      case 2: printf("Enter the member ID to search:");  //search for a member
        scanf(" %d", &i);
        ct = search_member(i);
        if (ct) {
          fp = fopen("members.dat", "rb");
          if (fp == NULL) {
            printf("Some error occurred!\n");
          }
          fseek(fp, (ct-1)*sizeof(member), 0);
          fread(&st, sizeof(member), 1, fp);
          printf("\nMember ID:%d, Name:%s, Email:%s, ", st.id, st.name, st.email);
          if (st.issues == 2) {
            printf("Designation: Student\n");
          } else {
            printf("Designation: Faculty\n");
          }
        } else {
          printf("Member with that ID not found\n");
        }
        break;
      case 3: display_all(); break;  //list all registered members
      case 4: exit(0);
    }
  } while(1);
  return 0;
}

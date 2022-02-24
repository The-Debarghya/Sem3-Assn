/*In a library, for each book book-id, serial number (denotes copy number of a book), 
 * title, author, publisher and price are stored. Book-id and serial number together will be unique 
 * identifier for a book. Members are either student or faculty. Each member has unique member-id. 
 * Name, e-mail address are also to be stored. For any transaction (book issue or return),
 * members are supposed to place transactions slip. User will submit member-id, book-id, 
 * and serial number (only for book return). While processing a transaction, check the validity of the member. 
 * While issuing, availability of a copy of the book is to be checked. While returning a book, 
 * it is to be checked whether this copy was issued to the member or not. A student member can have 2 books issued 
 * at a point of time. For faculty members it is 10. Transaction information is to be stored 
 * like date of transaction, member-id, book-id, serial number, returned or not. 
 * An entry is made when book is issued and updated when the book is returned.
Design the classes and implement.*/

#include "book.h"
#include "member.h"
#define BUFF 12
struct transaction{ 
  int mem_id;
  int b_id;
  int slno;
  bool retrn;  //keeps track of books that aren't returned
  char date[BUFF];
  struct transaction *next;
}*head;
void issue_book() {  //issues a book checking all the edge cases
  struct transaction* new = (struct transaction*)malloc(sizeof(struct transaction));
  int m;
  char *p;
  FILE *fp;
  book b;
  printf("Enter member ID:");
  scanf(" %d", &m);
  int ct = search_member(m);
  if (!ct) {  //check for member
    printf("Member with that ID not found, please re-enter\n");
    scanf(" %d", &m);
  }
  new->mem_id = m;
  printf("Enter Book ID:");
  scanf(" %d", &new->b_id);
  printf("Enter Book serial no.:");
  scanf(" %d", &new->slno);
  ct = search_book(new->b_id, new->slno);
  if (!ct) {  //check for book
    printf("Book with that details not found\n");
    return;
  }
  printf("Enter date of transaction(dd/mm/yyyy):");
	while ((getchar()) != '\n');
	fgets(new->date, BUFF, stdin);
	if ((p=strchr(new->date, '\n')) != NULL) *p = '\0';
  fp = fopen("books.dat", "r+");
  fseek(fp, (ct-1)*sizeof(book), 0);
  fread(&b, sizeof(book), 1, fp);
  if (!b.avail) {  //check if book is available
    printf("The book you requested is not available at the moment\n");
    return;
  }
  if (!make_issue(new->mem_id)) {
    return;
  }
  b.avail = false;  //make the book unavailable
  new->retrn = false;
  fseek(fp, -sizeof(book), 1);
  fwrite(&b, sizeof(book), 1, fp);
  printf("The book with ID:%d, serial:%d, is issued to member with ID:%d\n", new->b_id, new->slno, new->mem_id);
  new->next = NULL;
  if (head == NULL) {
    head = new;
  } else {
    new->next = head;
    head = new;
  }
  fclose(fp);
}
void return_book(int m, int b, int s) {  //returning a book that has been issued
  struct transaction* tmp1 = head;
  struct transaction* tmp2 = head;
  int flag=0, ct;
  book bk;
  FILE *fp;
  while (tmp1 != NULL) {
    if (tmp1->mem_id == m && tmp1->b_id == b && tmp1->slno == s) { //check for valid return
      flag=1;
      if (!revoke_issue(tmp1->mem_id)) {
        return;
      }
      fp = fopen("books.dat", "r+");
      ct = search_book(b, s);
      if (ct) {
        fseek(fp, (ct-1)*sizeof(book), 0);
        fread(&bk, sizeof(book), 1, fp);
        bk.avail = true; //make the book available
        tmp1->retrn = true;
        fseek(fp, -sizeof(book), 1);
        fwrite(&bk, sizeof(book), 1, fp);
        if(tmp1 == tmp2){
            head = head->next;
            free(tmp1);
        }
        else{
            tmp2->next = tmp1->next;
            free(tmp1);
        }
        fclose(fp);
        printf("The book has been successfully returned\n");
        break;
      }
    }
    tmp2 = tmp1;
    tmp1 = tmp1->next;
  }
  if (!flag) {
    printf("Member with ID:%d, didn't issue book with ID:%d, serial:%d\n", m, b, s);
  }
}
int main(int argc, char const *argv[]) {
  head = NULL;
  int choice, m, b, sl, ct;
  FILE *fp;
  member st;
  do {
    printf("1.Issue a book\n2.Return a book\n3.Search for books with same ID\n4.Search for a member\n5.Exit\n");
    printf("Enter a choice:");
    scanf(" %d", &choice);
    switch (choice) {
      case 1: issue_book(); break;  //issue a book by checking all factors
      case 2: printf("Enter the book ID:");
        scanf(" %d", &b);
        printf("Enter the book serial no.:");
        scanf(" %d", &sl);
        printf("Enter the member ID:");
        scanf(" %d", &m);
        return_book(m, b, sl);//return a book only if its valid 
        break;
      case 3: printf("Enter the book ID to search:");//search for book(s)
        scanf(" %d", &b);
        printf("\n");
        search_bookid(b);
        break;
      case 4: printf("Enter the member ID to search:");//search for a member
        scanf(" %d", &m);
        ct = search_member(m);
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
      case 5: exit(0);
    }
  } while(1);
  return 0;
}

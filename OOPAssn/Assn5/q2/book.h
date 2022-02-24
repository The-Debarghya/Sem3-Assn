/*This header file contains basic functions that adds, edits existing and lists all books in library*/
#ifndef BOOK_H  //header guard
#define BOOK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 41
typedef struct{ //book 
  int id;
  int slno;
  int price;
  char title[SIZE];
  char author[SIZE];
  char publ[SIZE];
  bool avail;
} book;
void search_bookid(int id) {  //lists all books with same id
  FILE *fp;
  book b;
  int flag=0;
  fp = fopen("books.dat", "rb");
  if (fp == NULL) {
    return;
  }
  while(fread(&b, sizeof(book), 1, fp)){
    if (b.id == id) {
      flag=1;
      printf("Book ID:%d, Serial number:%d, Title:%s, Author:%s", b.id, b.slno, b.title, b.author);
      if (b.avail) {
        printf(", Available\n");
      } else {
        printf(", Not Available\n");
      }
    }
  }
  fclose(fp);
  if (!flag) {
    printf("Book with that ID not found\n");
  }
}
int search_book(int id, int sl) { //searches for a particular book
  FILE *fp;
  book b;
  int ct = 0;
  fp = fopen("books.dat", "rb");
  if (fp == NULL) {
    return 0;
  }
  while(fread(&b, sizeof(book), 1, fp)){
    if (b.id == id && b.slno == sl) {
      ct++;
      return ct;
    }
    ct++;
  }
  fclose(fp);
  return 0;
}
void register_book() {  //adds a new book to the file
  book m;
  char *p;
  printf("Enter book ID: ");
  scanf("%d", &m.id);
  printf("Enter book Serial No.: ");
  scanf("%d", &m.slno);
  printf("Enter title:");
	while ((getchar()) != '\n');
	fgets(m.title, SIZE, stdin);
	if ((p=strchr(m.title, '\n')) != NULL) *p = '\0';
  printf("Enter author name:");
	while ((getchar()) != '\n');
	fgets(m.author, SIZE, stdin);
	if ((p=strchr(m.author, '\n')) != NULL) *p = '\0';
  printf("Enter publisher:");
  while ((getchar()) != '\n');
  fgets(m.publ, SIZE, stdin);
	if ((p=strchr(m.publ, '\n')) != NULL) *p = '\0';
  printf("Enter the price:");
  scanf(" %d", &m.price);
  m.avail=true;
  FILE *fp;
  fp = fopen("books.dat", "ab");
  if (fp == NULL) {
    printf("error in opening file\n");
    exit(EXIT_FAILURE);
  }
  fwrite(&m, sizeof(book), 1, fp);
  printf("\nBook registered Successfully!!\n");
  fclose(fp);
}
void display_books() {  //displays all saved records
  book b;
  FILE *fp;
  fp = fopen("books.dat", "rb");
  if (fp == NULL) {
    printf("\nError in opening file/ the file doesn't exist!!\n");
    return;
  }
  while(fread(&b, sizeof(book), 1, fp)){
    printf("Book ID:%d, Serial number:%d, Title:%s, Author:%s, Publisher:%s, price:Rs.%d ", b.id, b.slno, b.title, b.author, b.publ, b.price);
    if (b.avail) {
      printf(",Available\n");
    } else {
      printf(",Not Available\n");
    }
  }
  fclose(fp);
}
void add_copy(int id) {  //adds a new copy of a given book
  FILE *fp;
  book b;
  int flag=0;
  fp = fopen("books.dat", "r+");
  while (fread(&b, sizeof(book), 1, fp)) {
    if (b.id == id) {
      flag=1;
      break;
    }
  }
  if (!flag) {
    printf("Book with that ID not found.\n");
    fclose(fp);
    return;
  }
  fseek(fp, 0L, 2);
  printf("Enter new serial no.:");
  scanf(" %d", &b.slno);
  fwrite(&b, sizeof(book), 1, fp);
  fclose(fp);
  printf("New copy of book with ID:%d added\n", b.id);
}
void edit_bookdetails(int id, int slno) {  //edit details of a particular entry
  int ct=search_book(id, slno);
  FILE *fp;
  book b;
  char* p;
  if (ct) {
    fp = fopen("books.dat", "r+");
    fseek(fp, (ct-1)*sizeof(book), 0);
    printf("Enter new details:\n");
    printf("ID:");
    scanf("%d", &b.id);
    printf("serial:");
    scanf(" %d", &b.slno);
    printf("Title:");
    while ((getchar()) != '\n');
    fgets(b.title, SIZE, stdin);
  	if ((p=strchr(b.title, '\n')) != NULL) *p = '\0';
    printf("Author:");
    while ((getchar()) != '\n');
    fgets(b.author, SIZE, stdin);
    if ((p=strchr(b.author, '\n')) != NULL) *p = '\0';
    printf("Publisher:");
    while ((getchar()) != '\n');
    fgets(b.publ, SIZE, stdin);
    if ((p=strchr(b.publ, '\n')) != NULL) *p = '\0';
    printf("price:");
    scanf(" %d", &b.price);
    b.avail = true;
    fwrite(&b, sizeof(book), 1, fp);
    fclose(fp);
    printf("Details successfully edited\n");
  } else {
    printf("Book with that details not found\n");
  }
}
#endif

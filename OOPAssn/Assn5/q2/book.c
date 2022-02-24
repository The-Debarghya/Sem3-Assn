#include "book.h"
int main() {
  int choice, ct, i, sl;
  FILE *fp; 
  book st;
  do {
    printf("1.Register a new book\n2.Search for books with ID\n3.Search for a particular book\n4.Display all books\n5.Add a copy of a book\n6.Edit details of a book\n7.Exit\n");
    printf("Enter a choice:");
    scanf(" %d", &choice);
    switch (choice) {
      case 1: register_book(); break;  //add new book
      case 2: printf("Enter the book ID to search:");
        scanf(" %d", &i);
        printf("\n");
        search_bookid(i);  //list books with same id
        break;
      case 3: printf("Enter the book ID to search:");
        scanf(" %d", &i);
        printf("Enter the book serial number to search:");
        scanf(" %d", &sl);
        ct = search_book(i, sl);  //look for a book
        if (ct) {
          fp = fopen("books.dat", "rb");
          if (fp == NULL) {
            printf("Some error occurred!\n");
          }
          fseek(fp, (ct-1)*sizeof(book), 0);
          fread(&st, sizeof(book), 1, fp);
          printf("\nBook Title:%s, Author:%s, Publisher:%s, ", st.title, st.author, st.publ);
          if (st.avail) {
            printf("Book Available\n");
          } else {
            printf("Book not Available\n");
          }
        } else {
          printf("Book with that ID and serial not found\n");
        }
        break;
      case 4: display_books(); break;  //display all books
      case 5: printf("Enter the book ID to add:");
        scanf(" %d", &i);
        printf("\n");
        add_copy(i);  //create a copy of a book
        break;
      case 6: printf("Enter the book ID to edit:");
        scanf(" %d", &i);
        printf("Enter the book serial number to edit:");
        scanf(" %d", &sl);
        edit_bookdetails(i, sl);  //edit details of a book
        break;
      case 7: exit(0);
    }
  } while(1);
  return 0;
}

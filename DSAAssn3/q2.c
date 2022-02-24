#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
} ;

struct node* head1, *head2, *tail;
void print_list(struct node* h) {
  struct node* temp = h;
  while (temp != NULL) {
    printf("%d ", temp->data); 
    temp = temp->next;
  }
  printf("\n");
}

void insert_node_rev(int i) {
  struct node* new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = i;
  new->next = NULL;
  if (head1 == NULL) {
    head1 = new;
  } else {
    new->next = head1;
    head1 = new;
  }
}
void  Build_list_reverse() {
  FILE *fp;
  fp = fopen("list.txt", "r");
  if(fp == NULL){
    printf("An error occured\n");
    exit(0);
  }
  int i;
  head1 = NULL;
  while (fscanf (fp, "%d", &i) == 1){
      insert_node_rev(i);
  }
  fclose(fp);
}
void insert_node(int i) {
  struct node* new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = i;
  new->next = NULL;
  if (head2 == NULL) {
    head2 = new;
    tail = new;
  }
  else{
    tail->next = new;
    tail = tail->next;
  }
}
void Build_list() {
  FILE *fp;
  fp = fopen("list.txt", "r");
  if(fp == NULL){
    printf("An error occured\n");
    exit(0);
  }
  int i;
  head2 = NULL;
  while (fscanf (fp, "%d", &i) == 1){
      insert_node(i);
  }
  fclose(fp);
}
int main(int argc, char const *argv[]) {
  printf("The list in actual order:\n");
  Build_list();
  print_list(head2);
  printf("The list in reverse order:\n");
  Build_list_reverse();
  print_list(head1);
  return 0;
}

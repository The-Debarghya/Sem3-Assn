#ifndef POLY_H
#define POLY_H
#include <stdlib.h>
#include <stdio.h>

typedef struct{
  int exp;
  double coeff;
} term;
struct polynomial {
  term x;
  struct polynomial *next;
};
int termsof(struct polynomial **h){ //counts number of terms
  int count=0;
  struct polynomial *temp = *h;
  while(temp!=NULL){
      count++;
      temp = temp->next;  //traverse the list
  }
  return count;
}
void addterm(int ex, double co, struct polynomial **hp) {
  struct polynomial *p;
  p = (struct polynomial *)malloc(sizeof(struct polynomial));
  p->x.exp = ex;
  p->x.coeff = co;
  p->next = NULL;
  if(*hp==NULL){ //if the list is empty then head will be null
      *hp = p; //now head points to 1st member
  }
  else{
      p->next = *hp;  //else next pointer points to previous member
      *hp = p;
  }
}
void read_poly(struct polynomial **h) {
  int n, e;
  double c;
  printf("No of terms:");
  scanf(" %d", &n);
  struct polynomial *p;
  p = (struct polynomial *)malloc(n*sizeof(struct polynomial));
  printf("Enter the polynomial in ascending order of indices:");
  for (int i = 0; i < n; i++) {
    printf("Index of term %d:", i+1);
    scanf(" %d", &e);
    p[i].x.exp = e;
    printf("Coefficient of term %d:", i+1);
    scanf(" %lf", &c);
    p[i].x.coeff = c;
    p[i].next = NULL;
    if(*h==NULL){ //if the list is empty then head will be null
        *h = &p[i]; //now head points to 1st member
    }
    else{
        p[i].next = *h;  //else next pointer points to previous member
        *h = &p[i];
    }
  }
}
void removeDuplicates(struct polynomial* start){
    struct polynomial *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->x.exp == ptr2->next->x.exp) {
                ptr1->x.coeff = ptr1->x.coeff + ptr2->next->x.coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
void display_poly(struct polynomial **h) {
  if(h == NULL){
    printf("List is empty\n");
    return;
  }
  struct polynomial *temp = *h;
  while(temp!=NULL){
      printf("(%.2lfx^%d)+", temp->x.coeff, temp->x.exp);
      temp = temp->next;  //traverse the list
  }printf("\b "); printf("\n");
}
void add_poly(struct polynomial **h1, struct polynomial **h2) {
  struct polynomial *temp1 = *h1;
  struct polynomial *temp2 = *h2;
  struct polynomial *h = NULL;
  while (temp1 != NULL) {
    addterm(temp1->x.exp, temp1->x.coeff, &h);
    temp1 = temp1->next;
  }
  while (temp2 != NULL) {
    addterm(temp2->x.exp, temp2->x.coeff, &h);
    temp2 = temp2->next;
  }
  removeDuplicates(h);
  display_poly(&h);
}
void subtract_poly(struct polynomial **h1, struct polynomial **h2) {
  struct polynomial *temp1 = *h1;
  struct polynomial *temp2 = *h2;
  struct polynomial *h = NULL;
  while (temp1 != NULL) {
    addterm(temp1->x.exp, temp1->x.coeff, &h);
    temp1 = temp1->next;
  }
  while (temp2 != NULL) {
    addterm(temp2->x.exp, -temp2->x.coeff, &h);
    temp2 = temp2->next;
  }
  removeDuplicates(h);
  display_poly(&h);
}
void multiply_const(struct polynomial **h, double c) {
  struct polynomial *temp = *h;
  double newcoeff;
  while (temp != NULL) {
    newcoeff = temp->x.coeff*c;
    temp->x.coeff = newcoeff;
    temp = temp->next;
  }
  display_poly(h);
}
void multiply_poly(struct polynomial **h1, struct polynomial **h2) {
  int e;
  double c;
  struct polynomial *h=NULL;
  struct polynomial *temp1 = *h1;
  struct polynomial *temp2 = *h2;
  while (temp1 != NULL) {
    temp2 = *h2;
    while (temp2 != NULL) {
      e = temp1->x.exp+temp2->x.exp;
      c = (temp1->x.coeff)*(temp2->x.coeff);
      addterm(e, c, &h);
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }removeDuplicates(h);
  display_poly(&h);
}
void get_degree(struct polynomial *h) {
  struct polynomial *temp = h;
  int l = temp->x.exp;
  while (temp != NULL) {
    if(l < temp->x.exp){
      l = temp->x.exp;
    }
    temp = temp->next;
  }
  printf("%d\n", l);
}
#endif

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* next;
}*head;
struct node* init_l(struct node *cur){
    return NULL;
}
bool empty_l(struct node *head){
    if(head != NULL)
        return false;
    else 
        return true;
}
void print_list(struct node *head){
    if(empty_l(head))
        printf("The list is empty.\n");
    else{
        struct node *temp = head;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
bool attend_l(struct node *cur){
    if(cur->next == NULL)
        return true;
    else
        return false;
}
void insert_front(struct node *target,struct node *head0){
    target->next = head0;
    head = target;
    print_list(head);
}
void insert_after(struct node *target,struct node *prev){
    if(head == NULL)
        head = target;
    else{
        struct node *next,*start = head;
        while(start != prev){
            start = start->next;
        }
        next = prev->next;
        start->next = target;
        target->next = next;
    }
    print_list(head);
}
void delete_front(struct node *head){
    struct node *del = head;
    head = del->next;
    free(del);
    print_list(head);
}
void delete_after(struct node *prev){
    struct node *next1,*next2;
    next1 = prev->next;
    next2 = next1->next;
    prev->next = next2;
    free(next1);
    print_list(head);
}

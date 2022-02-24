#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
  int data;
  struct node* next;
};
void insert_node_beg(struct node** head, int a) {
  struct node* new;
  new = (struct node*)malloc(sizeof(struct node));
  new->data = a;
  new->next = NULL;
  if (*head == NULL ) { 
    *head = new;
  } else {
    new->next = *head;
    *head = new;
  }
}
void print_list(struct node* head) {
  struct node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
int list_size(struct node* h) {
  if (h == NULL) {
    return 0;
  } else {
    struct node* t = head;
    count = 0;
    while (t != NULL) {
      count++;
      t = t->next;
    }
    return count;
  }
}
void print_revlist(struct node* h) {
  struct node* tmp = h;
  int n = list_size(h);
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = tmp->data;
    tmp = tmp->next;
  }
  for (int i = n-1; i >= 0; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
bool check_equal(struct node* h1, struct node* h2) {
  if (list_size(h1) != list_size(h2)) {
    return false;
  } else {
    struct node* tmp1 = h1;
    struct node* tmp2 = h2;
    while (tmp1 != NULL && tmp2 != NULL) {
      if (tmp1->data != tmp2->data) {
        return false;
      }
      tmp1 = tmp1->next;
      tmp2 = tmp2->next;
    }
    return true;
  }
}
void append_at_end(struct node* h1, struct node* h2) {
  struct node* tmp = h1;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = h2;
  printf("The joined list:\n");
  print_list(h1);
}
void delete_node(struct node** h, int index) {
  struct node* tmp = *h; int i=0;
  struct node* tmp1 = *h;
  if (index == 0) {
    *h = tmp->next;
    free(tmp);
  } else {
    while (tmp != NULL) {
      if (i == index) {
        tmp1->next = tmp->next;
        free(tmp);
      }
      i++;
      tmp1 = tmp;
      tmp = tmp->next;
    }
  }
}
bool isSortedDesc(struct node *head){
    if (head == NULL){
        return true;
    }
    for (struct node *t=head; t->next != NULL; t=t->next){
       if (t->data <= t->next->data){
            return false;
       }
    }
    return true;
}
bool isSortedAsc(struct node *head){
    if (head == NULL){
        return true;
    }
    for (struct node *t=head; t->next != NULL; t=t->next){
       if (t->data >= t->next->data){
            return false;
       }
    }
    return true;
}
struct node* SortedMerge(struct node* a, struct node* b){
  struct node* result = NULL;
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
  if (a->data <= b->data){
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else{
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}
void swap(struct node *a, struct node *b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void sort(struct node *start){
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
    if (start == NULL)
        return;
    do{
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr){
            if (ptr1->data > ptr1->next->data){
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }while (swapped);
}
static void reverse(struct node** head_ref){
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void delete_list(struct node* h) {
  struct node *tmp = h;
  struct node *each;
  while (tmp != NULL) {
    each = tmp;
    tmp = tmp->next;
    free(each);
  }
}
void last_to_first(struct node* h) {
  struct node* tmp = h;
  while (tmp->next->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next->next = h;
  h = tmp->next;
  tmp->next = NULL;
}
struct node* del_and_ret(struct node** h, int key) {
  struct node* temp1, temp2;
  temp1 = *h;
  temp2 = *h;
  if (key == temp1->data) {
    *h = temp1->next;
    return temp1;
  } else {
    while (temp1 != NULL) {
      if (key == temp1->data) {
        temp2->next = temp1->next;
        return temp1;
      }
      i++;
      temp2 = temp1;
      temp1 = temp1->next;
      }
    }
  }
  return NULL;
}
void removeDuplicates(struct node* start){ //unordered
    struct node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
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

void remove_duplicates(struct node* head){  //ordered
    struct node* current = head;
    struct node* next_next;
    if (current == NULL)
       return;
    while (current->next != NULL) {
       if (current->data == current->next->data) {
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;
       }
       else {
          current = current->next;
       }
    }
}
void rotate(struct node** head_ref, int k){ //rotate by k places
    if (k == 0)
        return;
    struct node* current = *head_ref;
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;
    struct node* kthnode = current;
    while (current->next != NULL)
        current = current->next;
    current->next = *head_ref;
    *head_ref = kthnode->next;
    kthnode->next = NULL;
}
void delete_alternate(struct node *head){
    if (head == NULL)
        return;
    struct node *prev = head;
    struct node *node = head->next;
    while (prev != NULL && node != NULL) {
        prev->next = node->next;
        free(node);
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}
void insert_at_end(struct node** head_ref, int data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head_ref;
    new_node->data  = data;
    new_node->next = NULL;
    if (*head_ref == NULL)    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
struct node* addBefore(struct node* given_ptr, int val){
    if (head == given_ptr) {
        struct node* n = (struct node*) malloc(sizeof(struct node));
        n->next = head;
        head = n;
        return n;
    }
    else {
        Node *p, *n = head;
        for (n, p; n != given_ptr; p = n, n = n->next)
            ;
        struct node* m = (struct node*) malloc(sizeof(struct node));
        m->next = p->next;
        p->next = m;
        return m;
    }
}
bool search(struct Node* head, int x){
    struct Node* current = head;  // Initialize current
    while (current != NULL)    {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}

/*Maintain a list to store roll, name and score of students. As and when required student record may be
added or deleted. Also, the list has to be displayed. Design suitable functions for different operations.*/


#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define CHAR_BUFF 100  //defining a buffer for name size

struct Student{  //struct containing name roll and score of students
    int roll;
    char name[CHAR_BUFF];
    int scores;
    struct Student *next;
}* head;
void insert(int roll, char* name, int scores){  //for inserting members to the list
    struct Student *student = (struct Student *) malloc(sizeof(struct Student)); //allocate memory for a member
    student->roll = roll;
    strncpy(student->name, name, CHAR_BUFF);  //assign the input values to the list
    student->scores = scores;
    student->next = NULL;  //make the reference pointer for next element to null
    if(head==NULL){ //if the list is empty then head will be null
        head = student; //now head points to 1st member
    }
    else{
        student->next = head;  //else next pointer points to previous member
        head = student;
    }
}
void Delete(int roll){  //delete a member
    struct Student *temp1 = head;
    struct Student *temp2 = head;
    while(temp1!=NULL){ //the last member points to none

        if(temp1->roll==roll){  //if the roll matches any member roll
            printf("Record with roll number %d Found !!!\n", roll);
            if(temp1==temp2){  //checks whether its the first element
                head = head->next;  //head will point to next member
                free(temp1);
            }
            else{
                temp2->next = temp1->next;    //next of previous member of target now points to next member of target
                free(temp1);
            }
            printf("Record Successfully Deleted !!!\n");
            return; //exit the function
        }
        temp2 = temp1;
        temp1 = temp1->next;  //traverse the list
    }
    printf("Student with roll number %d is not found !!!\n", roll);  //print message if roll not found
}
void display(){  //print the saved info
    if(head == NULL){
      printf("List is empty\n");
      return;
    }
    struct Student *temp = head;
    printf("Roll\t\tName\t\tScore\n");
    while(temp!=NULL){
        printf("%d\t\t%s\t\t%d\n", temp->roll, temp->name, temp->scores);
        temp = temp->next;  //traverse the list
    }
}
int main(){  //driver code
    head = NULL;  //initialize head to null
    int choice;
    char name[CHAR_BUFF];
    int roll;
    int scores;
    printf("0 Exit\n1 to insert student details\n2 to delete student details\n3 to display all student details\n");
    do{
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice){  //choice between insertion, deletion and display of records
            case 1:
                printf("Enter name:");
                scanf("%80s", name);
                printf("Enter roll number: ");
                scanf("%d", &roll);
                printf("Enter score: ");
                scanf("%d", &scores);
                insert(roll, name, scores);
                break;
            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                Delete(roll);
                break;
            case 3:
                display();
                break;
        }
    } while (choice != 0);
    return 0;
}

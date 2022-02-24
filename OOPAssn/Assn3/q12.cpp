/*Design a STUDENT class to store roll, name, course, admission date and marks in 5 subjects.
Provide methods corresponding to admission (marks are not available then), receiving marks and preparing mark sheet.
Support must be there to show the number of students who have taken admission.*/

#include <iostream>
class STUDENT{              //student class
    std::string roll;
    std::string name;
    std::string course;
    time_t now = time(0);
    char* dt = ctime(&now);   // convert now to string form
    int marks[5]; //marks for 5 subjects
public:
    void set_roll(std::string r){  //function to set roll
        roll = r;
    }
    void set_name(std::string n){  //function to set name
        name = n;
    }
    void set_course(std::string c){  //function to set course
        course = c;
    }
    void set_marks(int m[]){  //function to set marks
        for(int i=0;i<5;i++){
            marks[i] = m[i];
        }
    }
    std::string get_roll(){   //function to return roll
        return roll;
    }
    std::string get_name(){  //function to return name
        return name;
    }
    std::string get_course(){  //function to return course
        return course;
    }
    int *get_marks(){  //function to return marks
        return marks;
    }
    void display_details(){  //function display all the details of student except marks
        std::cout<<"************************************************************************"<<"\n";
        std::cout<<"\t\t\tMARKSHEET"<<"\n";
        std::cout<<"************************************************************************"<<"\n";
        std::cout<<"Name: "<<name<<"\n";
        std::cout<<"Roll: "<<roll<<"\n";
        std::cout<<"Course: "<<course<<"\n";
        std::cout<<"Admission Date: "<<dt<<"\n";
        std::cout<<"************************************************************************"<<"\n";
    }
};
char grade_calc(int m){     //function to calculate grade corresponding to each marks user enters
    if(m >= 91 && m <= 100)
        return 'S';
    else if(m >= 81 && m <= 90)
        return 'A';
    else if(m >= 71 && m <= 80)
        return 'B';
    else if(m >= 61 && m <= 70)
        return 'C';
    else if(m >= 51 && m <= 60)
        return 'D';
    else if(m >= 41 && m <= 50)
        return 'E';
    else
        return 'F';
}
int main(){
    STUDENT *studentlist[20];  //defining array of objects of class STUDENT
    int choice,flag, flag1, i=0, j, total =0; //i and j are the index variables
    double cgpa;
    std::string roll1,name1,course1,admission_date1;
    int marks1[5];
    std::string subjects[5] = {"subj1","subj2","subj3","subj4","subj5"};
    do{ //loop which continues until user input choice number 4 to exit
        std::cout<<"1. Input student details and marks\n";
        std::cout<<"2. Display marksheet\n";
        std::cout<<"3. Display total number of students\n";
        std::cout<<"4. Exit!\n\n";
        std::cout<<"Enter a choice: ";
        std::cin>>choice;
        switch(choice){
        case 1:
            studentlist[i] = new STUDENT;
            std::cout<<"\nEnter roll: "; std::cin>>roll1;
            for(j=0;j<=i;j++){ //loop to check if given roll already exists
              flag1=0;
              if(studentlist[j]->get_roll() == roll1){
                  std::cout<<"This roll already exists. Enter a different roll: ";
                  std::cin>>roll1;
                  break;
              }else continue;
            }
            studentlist[i]->set_roll(roll1);
            std::cout<<"Enter name: "; std::cin >> name1;
            studentlist[i]->set_name(name1);
            std::cout<<"Enter course(arts/commerce/science): "; std::cin>>course1;
            flag1=0;
            while(!flag1){
                flag1 =1;
                if(course1 == "arts" || course1 == "commerce" || course1 == "science"){
                    studentlist[i]->set_course(course1);
                    flag1 =1;
                }
                else {
                    std::cout<<"Not a valid course! Enter course again: "; std::cin>>course1;
                    studentlist[i]->set_course(course1);
                    flag1=0;
                }
            }
            for(j=0;j<5;j++){
                std::cout<<"Enter marks of "<<subjects[j]<<" : ";
                std::cin>>marks1[j];
                flag1=0;
                while(!flag1){
                    flag1 =1;
                    if(marks1[j]> 100 || marks1[j]<0){
                        flag1=0;
                        std::cout<<"Invalid marks. Enter marks of "<<subjects[j]<<" again: ";
                        std::cin>>marks1[j];
                    }
                }
            }
            studentlist[i]->set_marks(marks1);
            i++;  //i is incremented as user enters details of new student
            break;
        case 2:
            std::cout<<"\nEnter roll of student: "; std::cin>>roll1;
            flag = 0 ;
            for(j=0;j<=i;j++){
                if(studentlist[j]->get_roll() == roll1){
                    flag = 1; // flag variable is changed to 1 if roll is found
                    studentlist[j]->display_details();
                    std::cout<<"Subject \tMarks\t\t Grade\n";
                    for(int k=0;k<5;k++){
                        total += *(studentlist[j]->get_marks()+k);
                        std::cout<<subjects[k]<<" \t\t "<<*(studentlist[j]->get_marks()+k)<<"\t\t   "<<grade_calc(*(studentlist[j]->get_marks()+k))<<"\n";
                    }
                }if(flag == 1){
                    std::cout<<"************************************************************************"<<"\n";
                    cgpa = (double)total / 50;  //stores the value of cgpa
                    std::cout<<"\tGPA : "<<cgpa<<"\n";
                    total = 0;
                    std::cout<<"************************************************************************"<<"\n";
                    break;
                  }
            }
            if(!flag)
                std::cout<<"\nRoll number not found!\n";
            break;
        case 3:
            std::cout<<"\nTotal number of students admitted : "<< i << "\n";
            break;
        case 4:
            for (int k = 0; k < i; k++) {
              delete studentlist[k];
            }
            exit(0);
        default:
            std::cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}

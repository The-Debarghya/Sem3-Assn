/*For each student roll, name and phone number are to be maintained. 
 *For each subject store subject code, name. A student may choose number of subjects 
 * from a list of subjects. A subject may be chosen by number of students. 
 * Given a roll number system must able to display the subjects chosen by the student 
 * and also be able to display the students corresponding to a subject code. 
 * Design the classes and implement the system.*/

#include <iostream>
using namespace std;
class Subjects {
  int code;
  string subjname;
public:
  friend class Student;
  Subjects(){
    code = 0;
    subjname = "\0";
  }
};
class Student {
  int roll; 
  string name;
  long long int phone;
  Subjects sub[3];
public:
  Student(int r=0, string n="\0", long long int p=0){ //constructor
    roll = r;
    name = n;
    phone = p;
  }
  void choose_subj() {  //function to choose the subjects for a particular member
    cout << "Please choose 3 subjects among the subjects given below:" << '\n';
    cout << "1.Maths\n2.Physics\n3.Chemistry\n4.Biology\n5.Statistics\n6.Computer Sc." << '\n';
    string x[6] = {"Maths", "Physics", "Chemistry", "Biology", "Statistics", "Computer Sc."};
    int c;
    for (int i = 0; i < 3; i++) {
      cin >> c;
      sub[i].subjname = x[c-1];
      sub[i].code = c;
    }
    std::cout << "Your roll is:"<< roll << '\n';
    cout << "You chose:" << '\n';
    for (int i = 0; i < 3; i++) {
      cout << "Subject:" << sub[i].subjname << " Code:"<< sub[i].code <<'\n';
    }
  }
  int ret_roll() {
    return roll;
  }
  string ret_name(){
    return name;
  }
  bool code_if_present(int c){  //checks if a subject code is present or not
    if (c>=6) {
      return false;
    } else {
      for (int i = 0; i < 3; i++) {
        if (c == sub[i].code) {
          return true;
        }
      }
      return false;
    }
  }
  void display_subj() {  //displays all the subjects taken by a particular student
    std::cout << "Roll:" << roll << '\n';
    std::cout << "Name:" << name<< '\n';
    std::cout << "Phone number:" << phone << '\n';
    std::cout << "The student took the following subjects:\n";
    for (int i = 0; i < 3; i++) {
      std::cout << "Subject:" << sub[i].subjname << " Code:"<< sub[i].code <<'\n';
    }
  }
};
int main() {
  Student *st[20];
  int c = 0, flag=0;
  int choice, r;
  long long int ph;
  string name1;
  do {
    std::cout << "1.Enter new student details\n2.Display subjects taken by a student\n3.Display students who have taken a particular subject\n4.Exit" << '\n';
    std::cout << "Give your choice:";
    std::cin >> choice;
    switch (choice) {
      case 1:
        std::cout << "Enter name:" ;
        std::cin >> name1;
        std::cout << "Enter phone number:";
        std::cin >> ph;
        st[c] = new Student(c+1, name1, ph);
        st[c]->choose_subj();
        c++;
        break;
      case 2:
        std::cout << "Enter the roll of the student for searching:";
        std::cin >> r;
        for (int j = 0; j < c; j++) {
          if (r == st[j]->ret_roll()) {
            st[j]->display_subj();
            flag = 1;
            break;
          }
        }
        if (!flag) {
          std::cout << "Roll not found!" << '\n';
          flag = 0;
        }
        break;
      case 3:
        std::cout << "Enter the code of the subject:";
        std::cin >> c;
        std::cout << "Students who took the subject with code:" << c << " are:\n";
        for (int j = 0; j <= c; j++) {
          if (st[j]->code_if_present(c)) {
            std::cout << st[j]->ret_name() << '\n';
            flag = 1;
          }
        }
        if (!flag) {
          std::cout << "Code not found!" << '\n';
          flag = 0;
        }
        break;
      case 4: exit(0);
    }
  } while(1);
  return 0;
}

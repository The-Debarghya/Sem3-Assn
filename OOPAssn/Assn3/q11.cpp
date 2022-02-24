/*Create an APPLICANT class with application id (auto generated as last id +1), name and score.
Support must be there to receive applicant data, show applicant details and to find out number of applicants.*/

#include <iostream>
class APPLICANT {  //applicant class
  int applid;
  std::string name;
  int score;
public:
  APPLICANT (){    //constructor to create empty class
    applid = 0;
    name = '\0';
    score = 0;
  }
  int get_id(){    //returns applicant id
    return applid;
  }
  void get_details(int);
  void show_details(void);
};
void APPLICANT::get_details(int n) {   //Takes the input of invoking object
  std::cout << "Enter name:";
  std::cin >> name;
  std::cout << "Enter score:";
  std::cin >> score;
  applid = n;
}
void APPLICANT::show_details() {      //shows the details of invoking object
  std::cout << "\n \nDetails of the student with ID-" << applid<<", Name:"<<name<<", Score:"<<score << '\n';
}

int main() {
  int choice, i=0, n, flag=0;
  APPLICANT *list[20];   //array of objects
  do {
    std::cout << "*************************************************************************" << '\n';
    std::cout << "1.Enter New Student Details\n2.Show Details of a Student\n3.Give Total Number of Entries\n4.Exit" << '\n';
    std::cout << "Enter a choice:";
    std::cin >> choice;
    switch (choice) {
      case 1:
        list[i] = new APPLICANT;
        list[i]->get_details(i+1);
        i = i+1;
        std::cout << "Details saved successfully!" << '\n';
        break;
      case 2:
        std::cout << "Enter the applicant ID of the student:";
        std::cin >> n;
        for (int j = 0; j < i; j++) {
          if (list[j]->get_id() == n) {
            list[j]->show_details();
            flag = 1;
          }
        }
        if (!flag) {
          std::cout << "ID not present!" << '\n';
        }
        break;
      case 3:
        std::cout << "Total number of applicants:" << i <<'\n';
        break;
      case 4:
        exit(0); break;
      default:
        std::cout << "1.Enter New Student Details\n2.Show Details of a Student\n3.Give Total Number of Entries\n4.Exit" << '\n';
    }
  } while(1);
  return 0;
}

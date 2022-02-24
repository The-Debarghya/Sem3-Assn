/*Define a structure student with roll and score as attributes and with two member functions
to take input and to show the data. Use the member functions to take data for a structure variable
and to show. Write global function i) to modify score and ii) to show the data again.*/

#include <iostream>
struct student {    //structure student
  int roll;
  std::string name;
  int score;
  void get_data(void);
  void show_data(void);
};
void student::get_data() {     //member function to get data of invoking object
  std::cout << "Enter roll:";
  std::cin >> this->roll;
  std::cout << "Enter name:";
  std::cin >> this->name;
  std::cout << "Enter score:" ;
  std::cin >> this->score;
}
void student::show_data() {      //member function to print data of invoking object
  std::cout << "Roll:" << this->roll <<", Name:"<<this->name<<", Score:"<< this->score << "\n";
}
void modify_score(student *s, int sc) {  //modify the score of the referred struct
  s->score = sc;
  std::cout << "Score modified!!" << '\n';
}
void show_data(student s) {        //global function to print data of specified struct
  std::cout << "Roll:" << s.roll <<", Name:"<<s.name<<", Score:"<< s.score << "\n";
}
int main() {
  student st;
  int choice, score;
  std::cout << "What do you want? \n1.Enter new details\n2.Show all entered details\n3.Modify score\n4.Exit" << '\n';
  do {
    std::cin >> choice;
    switch (choice) {
      case 1:
        st.get_data(); break;
      case 2:
        st.show_data(); break;
      case 3:
        std::cout << "Enter new score:" ;
        std::cin >> score;
        modify_score(&st, score);
        show_data(st); break;
      case 4:
        exit(EXIT_SUCCESS); break;
      default:
        std::cout << "What do you want? \n1.Enter new details\n2.Show all entered details\n3.Exit" << '\n';
    }
  } while(1);
  return 0;
}

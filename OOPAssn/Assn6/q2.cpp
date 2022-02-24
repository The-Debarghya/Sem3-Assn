/*Consider a class Student with roll, name and score as attributes. 
 *Support to take and display data is also there.  One wants to works with array of Student objects. 
 * May collect data for array elements, display those. In case index goes out of bounds, 
 * exception is to be raised with suitable message.*/

#include <iostream>
#include <exception>
#define SIZE 5  
using namespace std;
class Student{
private:
  int roll;
  std::string name;
  int score;

public:
  Student(int r=0, string n="\0", int s=0){ //constructor
    roll = r;
    name = n;
    score = s;
  }
  int get_roll(){ return roll;}
  std::string get_name(){ return name;}
  int get_score(){ return score;}
  void display_data() {  //display data 
    std::cout << "Roll No.:"<< roll<<", Name:"<<name<<", score:"<<score<< '\n';
  }
};
int search_roll(Student **st, int n, int r) {  //global function to search for a roll
  for (int i = 0; i < n; i++) {
    if (st[i]->get_roll() == r) {
      std::cout << "Roll found!!" << '\n';
      st[i]->display_data();
      return 1;
    }
  }
  std::cout << "Roll not found!!" << '\n';
  return 0;
}
void display_all(Student **st, int n) {  //prints the whole list
  if (n == 0) {
    std::cout << "No students registered yet!" << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    st[i]->display_data();
  }
}
int main() {
  Student* st[SIZE];
  int choice, i=0, r, s;
  std::string n;
  do {
    std::cout << "1.Register a student\n2.Search for a roll\n3.Display all students\n4.Exit" << '\n';
    std::cout << "Enter a choice:";
    std::cin >> choice;
    switch (choice) {
      case 1:
        try{  //try to add a student
          std::cout << "Enter new roll:";
          std::cin >> r;
          if (search_roll(st, i, r)) {
            throw "Roll is present!!";  //1st exception if roll is present
          }
          std::cout << "Enter name:";
          std::cin >> n;
          std::cout << "Enter score:";
          std::cin >> s;
          if (i >= SIZE) {
            throw i;  //second exception if number of students have exceeded array bounds(in this case its 5)
          }
          st[i] = new Student(r, n, s);
          i++;
        }catch(const char* c){  //handles the error and display error message
          std::cout <<"Error:"<< c << '\n';
        }catch(int a){
          std::cout <<"Error: Number of students exceeded limits" << '\n';
        }
        break;
      case 2: std::cout << "Enter the roll to search:"; //search for a roll
        std::cin >> r;
        search_roll(st, i, r);
        break;
      case 3: display_all(st, i); break;
      case 4: exit(0);
    }
  } while(1);
  return 0;
}

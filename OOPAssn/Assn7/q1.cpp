/*Create an array of student objects (containing roll, name and score) 
 *whose size may vary dynamically once objects are added or removed, 
 * randomly elements may be accessed, one can find number of objects in the list, 
 * one can find the student with highest score, find the students with a substring in their name 
 * and also without a substring in the name. Take the help of suitable STL classes.*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class STUDENT{
    int roll;
    string name;
    int score;
public:
    STUDENT(int r = 0, string word = "", int s = 0){ //default constructor
        roll = r; name = word; score = s;
    }
    void getData() {//method to get the student related information
        cout << "Enter name of the student :- ";
        cin >> name;
        cout << "Enter Roll Number of the student :- ";
        cin >> roll;
        cout << "Enter the score of the student :- ";
        cin >> score;
    }
    void showData() { //method to display the stduent data
        cout << "Name of the student :- " << name << "\n";
        cout << "Roll Number :- " << roll << "\n";
        cout << "Score of the student :- " << score << "\n";
    }
    int retScore() { //method to return the score
        return score;
    }
    string getName() { //method to get the student name
        return name;
    }
    bool operator ==(STUDENT& s1) const{  //checks equality
        return (s1.name == name && roll == s1.roll && score == s1.score);
    }
    int retRoll(){
        return roll;
    }
};
class compByScore { //utility class to compare by scores
    public:
        bool operator () (STUDENT& s1, STUDENT& s2) {
            return (s1.retScore() < s2.retScore());
        }
};
class checkByScore{  //utility class to display particular details
  int score;

public:
  checkByScore(int s=0){
    score = s;
  }
  void operator () (STUDENT& s1) const {
    if (s1.retScore() == score){
      s1.showData();
      cout << "--------------------------\n";
    }
  }
};
class checkSubstring{  //utility class to check substrings
private:
  std::string n;

public:
  checkSubstring(string str = "\0"){
    n = str;
  }
  void operator () (STUDENT& s1) const{  //operator overload to check substring in names
    string name = s1.getName();
    for(int i = 0; i <= (int)name.size(); i++) {
      for(int j = i + 1; j <= (int)name.size(); j++) {
        if(name.substr(i, j) == n){
          s1.showData();
          cout << "\n";
          return;
        }
      }
    }
  }
};
class checkByRoll{ //utility class to compare roll
  int roll;

public:
  checkByRoll(int r=0){
    roll = r;
  }
  void operator () (STUDENT& s1) const {
    if (s1.retRoll() == roll){
      s1.showData();
      cout << "--------------------------\n";
    }
  }
};
class Batch{
    vector<STUDENT> v;
public:
    void operate() {
      while(1) { //menu driven program to implement all the functionalities
        int ch;
        cout << "1. Add Student\n2. Display Number of students\n3. Show student with highest score\n4. Find student with substring\n5. Find student with roll\n6. List all students\n7. Remove a student\n8. Exit\n";
        cout << "Enter choice :- ";
        cin >> ch;
        STUDENT s; string subString;
        switch(ch) {
          case 1: s.getData(); //add data
            v.push_back(s);
            cout << "Student Data entry sucessful !";
            break;
          case 2: cout << "Number students :- " << v.size() << "\n";
            break;
          case 3: {  //highest score
            vector<STUDENT>::iterator itr = max_element(v.begin(), v.end(), compByScore());
            int sc = v[itr - v.begin()].retScore();
            for_each(v.begin(), v.end(), checkByScore(sc));
            break;
          }
          case 4: {  //check substring
            cout << "Enter the substring :- ";
            cin >> subString;
            for_each(v.begin(), v.end(), checkSubstring(subString));
            break;
          }
          case 5: { //search by roll
            int r, flag=0;
            std::cout << "Enter the roll to search for:" ;
            std::cin >> r;
            std::vector<STUDENT>::iterator itr;
            for (itr = v.begin(); itr != v.end(); ++itr) {
              if (v[itr-v.begin()].retRoll() == r) {
                v[itr-v.begin()].showData();
                cout << "--------------------------\n";
                flag = 1;
                break;
              }
            }
            if(!flag){
              std::cout << "Roll not found!" << '\n';
            }
            break;
          }
          case 6: {  //show all students
            std::vector<STUDENT>::iterator itr;
            for (itr = v.begin(); itr != v.end(); ++itr) {
              v[itr-v.begin()].showData();
              cout << "--------------------------\n";
            }
            break;
          }
          case 7: {  //remove data
            int r, flag=0;
            std::cout << "Enter the roll to delete:" ;
            std::cin >> r;
            std::vector<STUDENT>::iterator itr;
            for (itr = v.begin(); itr != v.end(); ++itr) {
              if (v[itr-v.begin()].retRoll() == r) {
                v.erase(itr);
                cout << "The data for Roll:"<<r<<" has been deleted!\n";
                flag = 1;
                break;
              }
            }
            if(!flag){
              std::cout << "Roll not found!" << '\n';
            }
            break;
          }
          case 8: exit(0);
            break;
        }
        cout << "\n";
      }
    }
};
//driver function to use the above functionalities
int main() {
    Batch obj;
    obj.operate();
    return 0;
}

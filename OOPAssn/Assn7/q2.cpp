/*Create an array of student objects where along with the support mentioned in Q.1, 
 *one can remove an object with specific roll, sort the collection in the descending order 
 * and show the same; two student collections can also be combined. 
 * Take the help of suitable STL class.*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//designing the class student
class STUDENT{
    int roll;
    std::string name;
    int score;
public:
    STUDENT(int r = 0, string n = "", int s = 0){ //default constructor
        roll = r; name = n; score = s;
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
    bool operator == (STUDENT& s1) const { //overloading the equality operator
        return (roll == s1.roll);
    }
    bool operator < (STUDENT& s) { //overloading comparison operator
        return (roll < s.roll);
    }
    int retRoll(){
        return roll;
    }
};
//comparator class to check the roll matches with a given roll or not
class checkRoll {
    int roll;
public:
    checkRoll(int r = 0) {
      roll = r;
    }
    bool operator () (STUDENT& s1) const {
      return (s1.retRoll() == roll);
    }
};

//deisgning the comprator to support sorting on the basis of field
class sortFunc {
    int ch;
public:
    sortFunc(int c) {
        ch = c;
    }
    bool operator () (STUDENT& s1, STUDENT& s2) {
        if(ch == 1)
            return (s1.retRoll() < s2.retRoll());  //sort ascending according to roll
        else
            return (s1.retScore() > s2.retScore()); //sort descending according to score
    }
};
//designing the batch class 2 to implment the given functionalities
class Batch{
    vector<STUDENT> v1;
    vector<STUDENT> v2;
public:
    void operate () {
      while(1) {
        int ch;
        cout << "1. add a student\n2. remove a student by roll\n3. sort the set of students\n4. combine collection\n5. exit\n";
        cout << "Enter choice :- " ;
        cin >> ch;
        STUDENT s1; int r;
        switch(ch) {
          case 1: { //to insert into the container of students
            s1.getData();
            v1.push_back(s1);
            cout << "Student inserted sucessfully !";
            break;
          }
          case 2: { //to delete a student with a particular roll number
            cout << "Enter the roll of the student :- ";
            cin >> r;
            vector<STUDENT>::iterator itr = find_if(v1.begin(), v1.end(), checkRoll(r));
            if(itr == v1.end())
              cout << "Student record not found !";
            else {
              v1.erase(itr);
              cout << "Student removed successfully !";
            }
            break;
          }
          case 3: { //soring in descending manner on the basis of field mentioned
            int ch;
            cout << "Sort on basis of: {1. roll / 2. score}:- ";
            cin >> ch;
            if(ch == 1 || ch == 2){
              sort(v1.begin(), v1.end(), sortFunc(ch));
              for(STUDENT ele : v1) {
                  ele.showData();
                  cout << "--------------------------\n";
              }
            }
            else //invalid choice
              cout << "Invalid choice \n";
            break;
          }
          case 4: { //merge two list of students
            int n; //take input into the second list
            cout << "Enter the number of members in the second list :- ";
            cin >> n;
            STUDENT s;
            for(int i = 0; i < n; i++) {
              s.getData();
              v2.push_back(s);
            }
            vector<STUDENT> v3; //declaring extra containers so that it doesn't affect the original containers
            v3 = v1;
            copy(v2.begin(), v2.end(), back_inserter(v3));
            for(STUDENT ele : v3){ //display after removing the common terms
              ele.showData();
              cout << "--------------------------\n";
            }
            break;
          }
          case 5: exit(0);
      }
      cout << "\n";
    }
  }
};
//driver code to utilise the above things
int main() {
    Batch obj;
    obj.operate();
    return 0;
}

/*Maintain a container of students where they are kept in the 
 *descending order of their scores. Take the help of suitable STL class.*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
//designing the class student
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
    bool operator == (STUDENT& s1) const {  //checks equality of two object instances
        return (s1.name == name && roll == s1.roll && score == s1.score);
    }
    int retRoll(){
        return roll;
    }
};
//designing the utility class required to compare by score
class compByScore {
    public:
        bool operator () (STUDENT& s1, STUDENT& s2) {
            return (s1.retScore() < s2.retScore());
        }
};
class Batch{
    priority_queue<STUDENT, vector<STUDENT>, compByScore> pq;
public:
    void operate() {
         while(1) { //menu driven program to implement all the functionalities
            int ch;
            cout << "1. Add Student\n2. Display students\n3. Exit\n";
            cout << "Enter choice :- ";
            cin >> ch;
            STUDENT s;
            switch(ch) {
                case 1: s.getData(); //new data
                  pq.push(s);
                  cout << "Student entered sucessfully !\n";
                  break;
                case 2:{  //display the list
                  vector<STUDENT> v;
                  while(!pq.empty()) {
                    s = pq.top();
                    s.showData();
                    cout << "------------------------------\n";
                    pq.pop();
                    v.push_back(s);
                  }
                  for(STUDENT s1 : v)
                    pq.push(s1);
                  break;
                }
                case 3: exit(0);
            }
            cout << "\n";
        }
    }
};

int main() {
    Batch obj;
    obj.operate();
    return 0;
}

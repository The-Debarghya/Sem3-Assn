/*Store the roll and score of the students in a map in the sorted order of roll. 
 *One should be able to retrieve the score for a given roll. 
 * Take the help of suitable STL class.*/

#include<iostream>
#include<map>
using namespace std;

class Batch {
    map<int, int> m; //map to implement the given functionality
public:
    void operate () {
        while (1) {
            cout << "1. add student data\n2. show score against a roll\n3. exit\n";
            cout << "Enter choice :- ";
            int ch, roll, score;
            cin >> ch;
            switch (ch) {
            case 1: {
                cout << "Enter student roll :- ";
                cin >> roll;
                cout << "Enter score of the student :- ";
                cin >> score;
                //insertion check needs to be performed
                pair<map<int, int>::iterator, bool> p = m.insert(map<int, int>::value_type(roll, score));
                if (p.second)
                    cout << "Insertion successful !\n";
                else
                    cout << "Insertion unsuccessful :(\n";
                break;
            }
            case 2: { //to check the presence of a roll number
                cout << "Enter roll number :- ";
                cin >> roll;
                if (m.find(roll) != m.end()) { // check if roll exists or not
                    cout << "score of the student :- " << m[roll] << "\n";
                }
                else
                    cout << "Invalid roll number !\n";
                break;
            } // else we can exit out
            case 3 : exit(0);
            }
            cout << "\n";
        }
    }
};
//driver function to implement the functionality
int main() {
    Batch obj;
    obj.operate();
    return 0;
}

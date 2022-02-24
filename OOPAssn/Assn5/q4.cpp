/*Each cricketer has name, date of birth and matches played. 
 * Cricketer may be a bowler or batsman. For a bowler, number of wickets taken, 
 * average economy is stored. For a batsman, total runs scored, average score is stored. 
 * A double wicket pair is formed taking a bowler and a batsman. 
 * An all-rounder is both a bowler and batsman. Support must be there to show the details of a cricketer, 
 * bowler, batsmen, all-rounder and the pair.
Design the classes and implement.*/

#include <iostream>

using namespace std;
class cricketer{  //cricketer base class
protected:
  string name;
  string dob;
  int matches;

public:
  string get_name(){
    return name;
  }
  string get_date(){
    return dob;
  }
  int get_match(){
    return matches;
  }
  virtual void show_details() {  //prints the basic details
    std::cout << "Name:" <<name<<", Date of birth:"<<dob<<", Matches played:"<<matches;
  }
  virtual string get_action() = 0;  //pure virtual function that determines the derived class type
};
class batter: public virtual cricketer{  //batsman derived class
protected:
  int total;
  double avg;
public:
  batter(string n="\0", string d="\0", int m=0, int t=0){ //constructor
    name = n;
    dob = d;
    matches = m;
    total = t;
    avg = (float)t/(float)m;
  }
  int get_total(){
    return total;
  }
  double get_avg(){
    return avg;
  }
  void show_details() {  //shows the details of a batsman
    std::cout << "Name:" <<name<<", Date of birth:"<<dob<<", Matches played:"<<matches<<", Total runs:"<<total<<", Average:"<<avg<< '\n';
  }
  string get_action(){  //identifies the class
    return "batter";
  }
};
class bowler: public virtual cricketer{  //bowler derived class
protected:
  int wkts;
  double econ;
public:
  bowler(string n="\0", string d="\0", int m=0, int w=0, double e=0.0){  //constructor
    name = n;
    dob = d;
    matches = m;
    wkts = w;
    econ = e;
  }
  int get_wkts(){
    return wkts;
  }
  double get_econ(){
    return econ;
  }
  void show_details() {  //show bowler details
    std::cout << "Name:" <<name<<", Date of birth:"<<dob<<", Matches played:"<<matches<<", Total wickets:"<<wkts<<", Economy:"<<econ<< '\n';
  }
  string get_action(){  //identifies the class
    return "bowler";
  }
};
class allrounder: public batter, public bowler{  //allrounder derived class from bowler and batter classes

public:
  allrounder(string n="\0", string d="\0", int m=0, int w=0, double e=0.0, int t=0){  //constructor
    name = n;
    dob = d;
    matches = m;
    wkts = w;
    econ = e;
    total = t;
    avg = (float)t/(float)m;
  }
  void show_details() {  //show details
    std::cout << "Name:" <<name<<", Date of birth:"<<dob<<", Matches played:"<<matches<<", Total runs:"<<total<<", Average:"<<avg<<", Total wickets:"<<wkts<<", Economy:"<<econ<< '\n';
  }
  string get_action(){  //identifies the class
    return "allrounder";
  }
};
void find_pair(cricketer *arr[], int n){  //global function that determines all possible double wicket pairs
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
          if (i != j && ((arr[i]->get_action() == "batter" && arr[j]->get_action() == "bowler")|| (arr[i]->get_action() == "bowler" && arr[j]->get_action() == "batter")||(arr[i]->get_action() == "batter" && arr[j]->get_action() == "allrounder")||(arr[i]->get_action() == "allrounder" && arr[j]->get_action() == "batter")
           || (arr[i]->get_action() == "bowler" && arr[j]->get_action() == "allrounder")||(arr[i]->get_action() == "allrounder" && arr[j]->get_action() == "bowler")||(arr[i]->get_action() == "allrounder" && arr[j]->get_action() == "allrounder")) ){
              cout << "Pair Found: (" << arr[i]->get_name() <<", " << arr[j]->get_name() << ")";
              std::cout << '\n';
          }
        }
    }
}
int main() {
  int choice, flag=0, ct=0, m, w, t;
  string n, d;
  double e;
  cricketer *list[22];
  do {
    std::cout << "1.Enter a cricketer details\n2.Check a cricketer stats by name\n3.List all players\n4.List all batsmen\n5.List all bowlers\n6.List all allrounders\n7.Double wicket pair list\n8.Exit" << '\n';
    std::cout << "Enter a choice:";
    std::cin >> choice;
    switch (choice) {
      case 1: //new player register
        std::cout << "Enter name:";
        std::cin >> n;
        std::cout << "Enter date of birth:(dd/mm/yyyy)";
        std::cin >> d;
        std::cout << "No. of matches played:";
        std::cin >> m;
        std::cout << "1.Batsman\n2.Bowler\n3.Allrounder" << '\n';
        std::cout << "Enter a choice:";
        std::cin >> flag;
        if (flag == 1) {
          std::cout << "Enter total runs scored:";
          std::cin >> t;
          list[ct] = new batter(n, d, m, t);
          ct++;
          flag = 0;
        } else if (flag == 2) {
          std::cout << "Enter total wickets taken:";
          std::cin >> w;
          std::cout << "Enter the average economy:";
          std::cin >> e;
          list[ct] = new bowler(n, d, m, w, e);
          ct++;
          flag = 0;
        }
        else if (flag == 3) {
          std::cout << "Enter total wickets taken:";
          std::cin >> w;
          std::cout << "Enter the average economy:";
          std::cin >> e;
          std::cout << "Enter total runs scored:";
          std::cin >> t;
          list[ct] = new allrounder(n, d, m, w, e, t);
          ct++;
          flag = 0;
        }
        break;
      case 2:  //search for a player
        std::cout << "Enter the name you want to search:";
        std::cin >> n;
        for (int i = 0; i < ct; i++) {
          if (list[i]->get_name() == n) {
            std::cout << "The info about the "<< list[i]->get_action()<< " is given below:" << '\n';
            list[i]->show_details();
            flag = 1;
            break;
          }
        }
        if (!flag) {
          std::cout << "The name you've entered is not present." << '\n';
          flag = 0;
        }
        break;
      case 3:  //list all players
        std::cout << "The following cricketers have been enlisted:" << '\n';
        for (int i = 0; i < ct; i++) {
          list[i]->cricketer::show_details();
          std::cout << '\n';
        }
        break;
      case 4:  //list all batter
        std::cout << "The following batsmen have been enlisted:" << '\n';
        for (int i = 0; i < ct; i++) {
          if (list[i]->get_action() == "batter") {
            list[i]->show_details();
          }
        }
        break;
      case 5:  //list all bowlers
        std::cout << "The following bowlers have been enlisted:" << '\n';
        for (int i = 0; i < ct; i++) {
          if (list[i]->get_action() == "bowler") {
            list[i]->show_details();
          }
        }
        break;
      case 6:  //list all allrounders
        std::cout << "The following allrounders have been enlisted:" << '\n';
        for (int i = 0; i < ct; i++) {
          if (list[i]->get_action() == "allrounder") {
            list[i]->show_details();
          }
        }
        break;
      case 7: find_pair(list, ct); break; //list all double wicket pairs
      case 8: exit(0);
    }
  } while(1);
  return 0;
}

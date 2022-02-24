/*Employee has unique emp-id, name, designation and basic pay. 
 * An employee is either a permanent one or contractual. 
 * For permanent employee salary is computed as basic pay+ hra (30% of basic pay) + da (80% of basic pay). 
 * For contractual employee it is basic pay + allowance (it is different for different contractual employee). 
 * An employee pointer may point to either of the two categories and accordingly the salary has to be created.
Design the classes and implement*/

#include <iostream>
using namespace std;

class Employee {  //employee base class
protected:
  double basic_pay;
  int emp_id;
  string name;
  string design;
public:
  virtual double ret_pay(){  
    return basic_pay;  //returns basic salary
  }
  int ret_id(){
    return emp_id;
  }
  string ret_name(){
    return name;
  }
  string ret_desn(){
    return design;
  }
};
class permanent: public Employee{  //permanent employee derived class
  double salary;
public:
  permanent(double b=0, int e=0, string n="\0", string d="\0"){  //constructor
    basic_pay = b;
    emp_id = e;
    name = n;
    design = d;
    salary = basic_pay + 0.3*basic_pay + 0.8*basic_pay;  //salary calculation for permanent employee
  }
  double ret_pay(){
    return salary;
  }
};
class contact: public Employee{  //contactual employee derived class
  double salary;
  double allowance;
public:
  contact(double a, double b=0, int e=0, string n="\0", string d="\0"){  //constructor
    basic_pay = b;
    emp_id = e;
    name = n;
    design = d;
    allowance = a;
    salary = basic_pay + a;  //salary calculation for contactual employee
  }
  double ret_pay(){
    return salary;
  }
};
int main() {
  Employee *emp[20];
  int choice, flag=0, id1, ct=0, ct1=0;
  string name1, design1;
  double b, a;
  do {
    std::cout << "1.Enter new employee details\n2.Show details by emp-id\n3.Total number of employees\n4.Exit" << '\n';
    std::cout << "Enter a choice:";
    std::cin >> choice;
    switch (choice) {
      case 1: //new employee details
        std::cout << "Enter emp-id:";
        std::cin >> id1;
        for (int j = 0; j <= ct; j++) {
          if (emp[j]->ret_id() == id1) {
            std::cout << "ID is already present, please enter a different:";
            std::cin >> id1;
            break;
          }
        }
        std::cout << "Enter employee name:";
        std::cin >> name1;
        std::cout << "Enter designation of the employee:";
        std::cin >> design1;
        std::cout << "Basic salary:" ;
        std::cin >> b;
        std::cout << "Type of employee?(1.Permanent, 2.Contactual):";
        std::cin >> flag;
        if (flag == 1) {
          emp[ct] = new permanent(b, id1, name1, design1);
          ct1++;
        } else {
          std::cout << "Enter the allowance:";
          std::cin >> a;
          emp[ct] = new contact(a, b, id1, name1, design1);
        }
        ct++;
        break;
      case 2:  //search for an employee
        flag = 0;
        std::cout << "Enter emp-id:";
        std::cin >> id1;
        for (int j = 0; j <= ct; j++) {
          if (emp[j]->ret_id() == id1) {
            if (emp[j]->ret_pay() == (emp[j]->Employee::ret_pay())*2.1) {
              std::cout << "Permanent Employee::" << '\n';
            } else {
              std::cout << "Contactual Employee::" << '\n';
            }
            std::cout << "Employee Name:"<<emp[j]->ret_name() << ", Emp-ID:"<<emp[j]->ret_id()<< ", Designation:"<< emp[j]->ret_desn()<<", Basic Pay:"<<emp[j]->Employee::ret_pay()<<", Total salary:"<< emp[j]->ret_pay()<< '\n';
            flag = 1;
            break;
          }
        }
        if (!flag) {
          std::cout << "Employee with emp-ID not found!" << '\n';
        }
        break;
      case 3: std::cout << "Total number of employees are:" << ct << ", Permanent:"<< ct1 <<", Contactual:"<< ct-ct1<<"\n"; break; //count number of registered employees
      case 4: exit(0);
    }
  } while(1);
  return 0;
}

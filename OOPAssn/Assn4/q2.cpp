/*Design a COMPLEX class, which will behave like normal integer with respect to 
    • addition, 
    • subtraction, 
    • accepting the value and 
    • Displaying the value.*/

#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

class COMPLEX{ //complex class
    double real;
    double imaginary;
public:
    COMPLEX(){
        real = 0;
        imaginary = 0;
    }
    COMPLEX operator+(COMPLEX x) {  //overloaded operator to perform addition
        COMPLEX y;
        y.real = real + x.real;
        y.imaginary = imaginary + x.imaginary;
        return y;
    }
    COMPLEX operator-(COMPLEX x) {  //overloaded operator to perform subtraction
        COMPLEX y;
        y.real = real - x.real;
        y.imaginary = imaginary - x.imaginary;
        return y;
    }
    void setData(string cmplx){  //takes a complex number input using regular expressions
      const std::string& str = cmplx;
      double rl; double imag;
      std::regex rgx("^(?=[iI.\\d+-])([+-]?(?:\\d+(?:\\.\\d*)?|\\.\\d+)(?:[eE][+-]?\\d+)?(?![iI.\\d]))?([+-]?(?:(?:\\d+(?:\\.\\d*)?|\\.\\d+)(?:[eE][+-]?\\d+)?)?)?[iI]$");
      std::smatch match;
      if (std::regex_match(str.begin(), str.end(), match, rgx)){ //match with proper regular expressions
            rl = std::atof(match[1].str().c_str());
            imag = std::atof(match[2].str().c_str());
            if (match[1].matched){
                real = rl;
                imaginary = imag;
            }
            else cout << "Unmatched regular expression\n";
      }
      else cout << "Unmatched regular expression\n";
    }
    void getData(){  //prints the complex number
        if(imaginary>0){
            if(real==0)
                cout<<"+"<<imaginary << "i";
            else
                cout<<real<<"+"<<imaginary << "i";
        }
        else if(imaginary<0){
            if(real==0)
                cout<<"-"<<imaginary*(-1)<<"i";
            else
                cout<<real<<"-"<<imaginary*(-1)<<"i";
        }
        else if(imaginary ==0){
            cout<<real;
        }
        cout << "\n Real part:" << real <<", Imaginary part:"<<imaginary;
    }
};
int main(){
    COMPLEX a, b, c;
    string cmplx; 
    int choice;
    do {
      cout << "1.Input and display a complex number" << '\n';
      cout << "2.Addition of two complex numbers" << '\n';
      cout << "3.Subtraction of two complex numbers" << '\n';
      cout << "4.Exit" << '\n';
      cout << "Enter a choice:";
      cin >> choice;
      switch (choice) {
        case 1:
          cout << "Enter the complex number:";
          cin >> cmplx;
          a.setData(cmplx);
          cout << "You have entered the complex number:";
          a.getData();
          cout << "\n";
          break;
        case 2:
          cout << "Enter first complex number:";
          cin >> cmplx;
          a.setData(cmplx);
          cout << "Enter second complex number:";
          cin >> cmplx;
          b.setData(cmplx);
          c = a+b;
          cout << "\nAddition of the complex numbers:";
          c.getData();
          cout << "\n";
          break;
        case 3:
          cout << "Enter first complex number:";
          cin >> cmplx;
          a.setData(cmplx);
          cout << "Enter second complex number:";
          cin >> cmplx;
          b.setData(cmplx);
          c = b-a;
          cout << "\nDifference between second and first complex numbers:";
          c.getData();
          cout << "\n";
          break;
        case 4:
          exit(0);
      }
    } while(1);
    return 0;
}

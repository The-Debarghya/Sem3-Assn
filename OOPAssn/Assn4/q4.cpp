/*Design a STRING class, which will have the initialization facility similar to array class. Provide support for 
    • Assigning one object for another, 
    • Two string can be concatenated using + operator, 
    • Two strings can be compared using the relational operators.*/
#include <iostream>
using namespace std;

class STRING{
    string str;
public:
    STRING(){ 
        str = '\0';
    }
    STRING(const STRING &s){  //constructor to initialize with a const STRING object
        str = s.str;
    }
    STRING(string s){  //constructor to initialize with a string
        str = s;
    }
    void readString(){  //function to input string from the user
        getline(cin, str);
    }
    string getString(){  //function to return string
        return str;
    }
    void operator=(const string s){  //operator overloading for assignment with const string
        str = s;
    }
    void operator=(STRING s){  //operator overloading for assignment with STRING object
        str = s.str;
    }
    friend STRING operator+(STRING s1, STRING s2){  //operator overloading for concatenation of two STRING objects
        STRING s;
        s.str = s1.str +" " + s2.str;
        return s;
    }
    friend int operator<(STRING s1, STRING s2){  //operator overloading for comparing of two STRING objects if lesser
        if((s1.str).compare(s2.str)<0)
            return 1;
        else return 0;
    }
    friend int operator>(STRING s1, STRING s2){  //operator overloading for comparing of two STRING objects if greater
        if((s1.str).compare(s2.str)>0)
            return 1;
        else return 0;
    }
    friend int operator==(STRING s1, STRING s2){  //operator overloading for comparing of two STRING objects if equal
        if((s1.str).compare(s2.str)==0)
            return 1;
        else return 0;
    }
};
int main() {
  STRING a;
  STRING b;
  a = "Debarghya";
  b = "Maitra";
  STRING c, d;
  c = a+b;
  std::cout << "Concatenated string:"<<c.getString() << '\n';
  std::cout << "Enter a new string:";
  d.readString();
  if (d > c) {
    std::cout << "your string is larger, alphabetically" << '\n';
  } else if (d < c) {
    std::cout << "your string is smaller, alphabetically" << '\n';
  } else if(d == c){
    std::cout << "your string is same as last one" << '\n';
  }
  STRING e = d;
  std::cout << "Your string copied into another string:" << e.getString() << '\n';
  return 0;
}

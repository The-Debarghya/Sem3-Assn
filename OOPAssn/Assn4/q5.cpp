/*Modify the STRING class so that assigning/initializing a string by another 
 *will not copy it physically but will keep a reference count, which will be incremented. 
 * Reference value 0 means the space can be released.*/

#include <iostream>

using namespace std;
class STRING {
  string str;
  int *c;
public:

  STRING (){
    c = new int; 
    c = NULL;
    str = '\0';
  }
  STRING(const STRING &s){  //copy constructor
    str = s.str;
    c = s.c;
    if (c != NULL) {
      *c = *c+1;
    }
  }
  STRING(string s){  //constructor to initialize with a string
      str = s;
      *c = *c+1;
  }
  void operator=(const string s){  //operator overloading for assignment with const string
    str = s;
    if (c != NULL) {
      *c = *c+1;
    }
  }
  void operator=(STRING s){  //operator overloading for assignment with STRING object
      str = s.str;
  }
  ~STRING(){  //destructor
    if (c != NULL) {
      *c = *c - 1;
      if (*c == 0) {
        delete c;
      }
    }
  }
  void readString(){  //function to input string from the user
    getline(cin, str);
  }
  string getString(){  //function to return string
    return str;
  }
  friend STRING operator+(STRING s1, STRING s2){  //operator overloading for concatenation of two STRING objects
    STRING s;
    s.str = s1.str + " "+s2.str;
    return s;
  }
  friend bool operator<(STRING s1, STRING s2){  //operator overloading for comparing of two STRING objects if lesser
    if((s1.str).compare(s2.str)<0)
      return true;
    else return false;
  }
  friend bool operator>(STRING s1, STRING s2){  //operator overloading for comparing of two STRING objects if greater
    if((s1.str).compare(s2.str)>0)
      return true;
    else return false;
  }
  friend bool operator==(STRING s1, STRING s2){  //operator overloading for comparing of two STRING objects if equal
    if((s1.str).compare(s2.str)==0)
      return true;
    else return false;
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
  STRING *p1, *p2;
  p1 = new STRING;
  *p1 = a;
  p2 = new STRING(*p1);
  std::cout << "Using pointer to STRING class:" << '\n';
  std::cout << p1->getString() << '\n';
  delete p1;
  std::cout << "After deleting the previous instance:" << '\n';
  std::cout << p2->getString() << '\n';
  return 0;
}

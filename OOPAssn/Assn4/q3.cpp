 /*Design an ARRAY class with the following features:
    a. Array object may be declared for a specific size and a value for initializing all the elements. If this it is to be assumed as a 0.
    b. An array object may be declared and initialized with another object.
    c. An array object may be declared and initialized with another array (not the object, standard array as in C language).

Let a and b are two objects:
    i. a+b will add corresponding elements.
    ii. a=b will do the assignment.
    iii. a[I] will return the ith element of the object.
    iv. a*5 or 5*a will multiply the element with 5.*/
 
#include <iostream>

using namespace std;
class ARRAY{  
  int size;
  double *a;
  int *pct;  //keeps track of number of copied pointers of an object
public:
  ARRAY(int s=0){  //constructor
    size = s;
    if(s == 0){
      a = NULL;
      pct = NULL;
    }
    else{
      a = new double[size];
      pct = new int;
      *pct = 1;
      for (int i = 0; i < size; i++) {
        a[i] = 0;
      }
    }
  }
  ARRAY(const ARRAY &arr){  //copy constructor
    size = arr.size;
    a = arr.a;
    pct = arr.pct;
    if (pct != NULL) {
      *pct = *pct+1;
    }
  }
  ~ARRAY(){  //destructor
    if (pct != NULL) {
      *pct = *pct - 1;
      if (*pct == 0) {
        delete pct;
        delete []a;
      }
    }
  }
  void print() {   //prints the whole array
    for(int i =0; i<size; i++){
      cout<<a[i]<<"  ";
    }
    cout<<"\n";
  }
  int get_size(){
    return size;
  }
  ARRAY operator+(ARRAY b){  //operator overload to add elements of two arrays
    ARRAY x(size);
    for(int i=0; i<size; i++){
      x.a[i] = a[i] + b[i];
    }
    return x;
  }
  friend ARRAY operator*(double x, ARRAY p){  //friend function to perform same job for 5*a and a*5
    return p*x;
  }
  ARRAY operator*(double x){  //operator overload to multiply a constant with the array
    ARRAY u(size);
    for (int i = 0; i < size; i++) {
      u.a[i] = x*a[i];
    }
    return u;
  }
  void operator=(ARRAY p) {  //operator overload to copy corresponding elements from one object to another
    int size1 = p.get_size();
    if(size1 > size) size1 = size;
    for(int i=0; i<size1; i++){
      a[i] = p.a[i];
    }
  }
  void operator=(double p[]) {  //operator overload to copy corresponding elements from one object to another array
    for (int i = 0; i < size; i++) {
      a[i] = p[i];
    }
  }
  double& operator[](int p){  //operator overload to get random access of each element
    if (p < size) {
      return a[p];
    }else{
      cout<<"Segfault!!\n";
      exit(0);
    }
  }
};
int main() {
  ARRAY a(10), b(10), c(10);
  double arr[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
  double ar[10] = {4.5, 5.6, 7.8, 7.6, 4.3, 3.2, 2.1, 2.9, 9.8};
  a = arr;
  std::cout << "ARRAY a:" << '\n';
  a.print();
  b = a;
  std::cout << "ARRAY b:" << '\n';
  b.print();
  c = ar;
  std::cout << "ARRAY c:" << '\n';
  c.print();
  std::cout << "ARRAY a+c=" << '\n';
  b = a+c;
  b.print();
  b = 5*a;
  std::cout << "ARRAY 5*a=" << '\n';
  b.print();
  c = a*5;
  std::cout << "ARRAY a*5=" << '\n';
  c.print();
  std::cout << "Accessing elements of ARRAY a randomly:" << '\n';
  for (int i = 0; i < 10; i++) {
    std::cout << a[i] << "  ";
  }std::cout << '\n';
  ARRAY *p1, *p2;
  p1 = new ARRAY(10);
  p2 = new ARRAY(*p1);  //uses copy constructor
  *p1 = ar;
  std::cout << "Using pointer to ARRAY class:" << '\n';
  p1->print();
  delete p1;
  std::cout << "After deleting the previous instance:" << '\n';
  p2->print();
  std::cout << "Enter 10 elements:" << '\n';
  ARRAY d(10);
  for (size_t i = 0; i < 10; i++) {
    std::cin >> d[i];
  }
  d.print();
  return 0;
}

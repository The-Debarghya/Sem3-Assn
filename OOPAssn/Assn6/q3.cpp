/*Implement a class template for 1D array. Elements may be any basic data type. 
 *Provision to find maximum element, sum of the elements must be there.*/

#include <iostream>
#include <algorithm>
using namespace std;
template <class T> //template declaration
class Array {
protected:
    int size; 
    T* DynArray;
public:
    Array(size_t s): size(s) { //constructor
        DynArray = new T[size];
        for (int i = 0; i<size; i++) {
            cout << "Element " << i+1 << ": ";
            cin >> DynArray[i];
        }
    }
    void sum_of_elements() {  //sum of elements
      T sum=0;
      for (int i = 0; i < size; i++) {
        sum = sum+DynArray[i];
      }
      std::cout << "The sum of elements is:" <<sum<< '\n';
    }
    void Sort(){ //Sort Array
        sort(DynArray, DynArray+size);
        for (int i=0; i<size; i++) {
            cout << DynArray[i] << " ";
        }
        std::cout << '\n';
    }
    ~Array() { //destructor
        delete []DynArray;
    }
};
int main() {
    int size;
    cout << "Enter size of Array: ";
    cin >> size;
    Array<int> intArray = Array<int>(size); //for int type
    std::cout << "The integer array in ascending order: ";
    intArray.Sort();
    intArray.sum_of_elements();
    Array<float> floatArray = Array<float>(size); //for float type
    std::cout << "The float array in ascending order: ";
    floatArray.Sort();
    floatArray.sum_of_elements();
}

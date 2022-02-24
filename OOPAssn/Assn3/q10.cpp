/*Create a STACK class with operation for initialization, push and pop.
Support for checking underflow and overflow condition are also to be provided.*/

#include<iostream>
#define STACK_SIZE 5
class STACK{      //stack class
        int num[STACK_SIZE];
        int top;
    public:
        STACK() {        // constructor to construct an empty stack
          top = -1;
        }
        int push(int);
        int pop();
        bool is_empty();
        bool is_full();
        void display_items();
};
bool STACK::is_empty(){  //check if the stack is empty
    if(top == -1)
        return true;
    else
        return false;
}
bool STACK::is_full(){    //check if the stack is full
    if(top==(STACK_SIZE-1))
        return true;
    else
        return false;
}
int STACK::push(int n){     //push new element to stack
    if(is_full()){          //check stack is full or not
        return 0;
    }
    top = top+1;
    num[top] = n;
    return n;
}
int STACK::pop(){   //to store and print which number is deleted
    int temp;
    if(is_empty())     //check for empty stack
        return 0;
    temp = num[top];
    top  = top-1;
    return temp;
}
void STACK::display_items(){    //to display the stack elements
    int i;
    std::cout<<"STACK is: ";
    for(i = top; i >= 0; i--)
        std::cout<<num[i]<<" ";
    std::cout<<"\n";
}
int main(){
    STACK stk; //declare object
    int choice, n,temp;
    do{
        std::cout<<"\n";
        std::cout<<"0 - Exit.\n1 - Push Item.\n2 - Pop Item.\n3 - Display Items (Print STACK)."<<"\n";
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        switch(choice){
            case 0: exit(0); break;
            case 1:
                std::cout<<"Enter item to insert: ";
                std::cin>>n;
                temp = stk.push(n);
                if(!temp)
                    std::cout<<"STACK is FULL."<<"\n";
                else
                    std::cout<<temp<<" inserted."<<"\n";
            break;
            case 2:
                temp = stk.pop();
                if(!temp)
                    std::cout<<"STACK IS EMPTY."<<"\n";
                else
                    std::cout<<temp<<" is removed (popped)."<<"\n";
            break;
            case 3:
                if (stk.is_empty()) {
                  std::cout << "STACK IS EMPTY" << "\n";
                } else {
                  stk.display_items();
                }
            break;
            default:
                std::cout<<"0 - Exit.\n1 - Push Item.\n2 - Pop Item.\n3 - Display Items (Print STACK)."<<"\n";
        }
    }while(1);
    return 0;
}

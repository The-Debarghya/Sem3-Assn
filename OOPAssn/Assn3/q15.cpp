/*Design a BALANCE class with account number, balance and date of last update.
Consider a TRANSACTION class with account number, date of transaction, amount and transaction type
(W for withdrawal and D for deposit). If it is a withdrawal check whether the amount is available or not.
Transaction object will make necessary update in the BALANCE class.*/

#include <iostream>
class BALANCE{
    int acc_no;
    float bal;
public:
    std::string date;
    BALANCE(){  //constructor which initializes the variables to 0
        acc_no = 0;
        bal = 0.0;
        date = '\0';
    }
    int getacc_no(){  //function to return account number
        return acc_no;
    }
    float get_bal(){  //function to return balance
        return bal;
    }
    std::string get_date(){  //function to return date
        return date;
    }
    void set_bal(float b){  //function to set date
        bal = b;
    }
    void open_new(){  //function to open a new account
        acc_no = rand()%10000;
        std::cout << "*********************************************************************" << '\n';
        std::cout<<"New account with account number "<<acc_no<<" opened."<<"\n";
        std::cout << "*********************************************************************" << '\n';
    }
    void update_date(std::string d){  //function to set updated date
        date = d;
    }
};
class TRANSACTION: public BALANCE{    //inheriting attributes of class BALANCE
    float amount;
public:
    float withdraw(){   //function for withdraw
      time_t now = time(0);
      date = ctime(&now);
      std::cout<<"How much money you want to withdraw? : ";
      std::cin>>amount;
      return amount;
    }
    float deposit(){   //function for deposit
        time_t now = time(0);
        date = ctime(&now);
        std::cout<<"How much money you want to deposit? : ";
        std::cin>>amount;
        return amount;
    }
};
int main(){
    TRANSACTION t;  //object of class TRANSACTION
    BALANCE *b[20];   //array of objects of class BALANCE
    int i =0, choice, flag;
    int acno;
    float amount1 =0;
    do{
        std::cout<<"1. New Account Opening\n";
        std::cout<<"2. Deposit money\n";
        std::cout<<"3. Withdraw money\n";
        std::cout<<"4. View available balance & last date of update\n";
        std::cout<<"5. Exit!\n\n";
        std::cout<<"Enter a choice number: ";
        std::cin>>choice;
        switch(choice){
          case 1:  //new account opening
            b[i] = new BALANCE;
            std::cout<<"While opening ";
            amount1 = t.deposit();
            b[i]->set_bal(amount1);
            b[i]->update_date(t.get_date());
            b[i]->open_new();
            i++;
            break;
          case 2:  //deposit
            if(i==0){
              std::cout << "*********************************************************************" << '\n';
              std::cout<<"No accounts in the bank! Open an account.\n";
              std::cout << "*********************************************************************" << '\n';
            }
            else{
              std::cout<<"Enter the account number : "; std::cin>>acno;
              for(int j=0;j<i;j++){
                if(b[j]->getacc_no() == acno){
                    flag = 1;
                    amount1 = t.deposit();
                    std::cout << "*********************************************************************" << '\n';
                    std::cout<<"Rs. "<<amount1<<" has been deposited.\n";
                    amount1 = (b[j]->get_bal()) + amount1;
                    std::cout << "CURRENT BALANCE:Rs. " << amount1 << '\n';
                    std::cout << "*********************************************************************" << '\n';
                    b[j]->set_bal(amount1);
                    b[j]->update_date(t.get_date());
                    break;
                }
                else flag =0;
              }
            if(flag ==0) {
              std::cout << "*********************************************************************" << '\n';
              std::cout<<"Account not found.\n";
              std::cout << "*********************************************************************" << '\n';
            }
          }
            break;
        case 3:  //withdraw
            if(i==0) {
              std::cout << "*********************************************************************" << '\n';
              std::cout<<"No accounts in the bank! Open an account.\n";
              std::cout << "*********************************************************************" << '\n';
            }
            else{
              std::cout<<"Enter the account number : "; std::cin>>acno;
              for(int j=0;j<i;j++){
                if(b[j]->getacc_no()==acno){
                    flag = 1;
                    amount1 = t.withdraw();
                    if(b[j]->get_bal()==0 || b[j]->get_bal() < amount1){
                        std::cout << "*********************************************************************" << '\n';
                        std::cout<<"No sufficient balance in the account! You cannot withdraw money.\n";
                        std::cout << "CURRENT BALANCE:Rs. " << b[j]->get_bal()<< '\n';
                        std::cout << "*********************************************************************" << '\n';
                    }
                    else {
                        std::cout << "*********************************************************************" << '\n';
                        std::cout<<"Rs. "<<amount1<<" has been withdrawn.\n";
                        amount1 = (b[j]->get_bal()) - amount1;
                        std::cout << "CURRENT BALANCE:Rs. " << amount1<< '\n';
                        std::cout << "*********************************************************************" << '\n';
                        b[j]->set_bal(amount1);
                        b[j]->update_date(t.get_date());
                    }
                    break;
                }
                else flag = 0;
             }
            if(flag ==0 ) {
              std::cout << "*********************************************************************" << '\n';
              std::cout<<"Account not found.\n";
              std::cout << "*********************************************************************" << '\n';
            }
            }
            break;
        case 4:  //display balance and last update date
            if(i==0) std::cout<<"No accounts in the bank! Open an account.\n";
            else{
                std::cout<<"Enter the account number : "; std::cin>>acno;
                for(int j=0;j<i;j++){
                    if(b[j]->getacc_no()==acno){
                        flag = 1;
                        std::cout << "*********************************************************************" << '\n';
                        std::cout<<"\nACCOUNT BALANCE: Rs. "<<b[j]->get_bal()<<"\n";
                        std::cout<<"LAST DATE OF UPDATE: "<<b[j]->get_date()<<"\n";
                        std::cout << "*********************************************************************" << '\n';
                        break;
                    }
                    else flag = 0;
                }
                if(flag ==0 ) std::cout<<"Account not found.\n";
            }
            break;
        case 5:  //exit
            exit(0);
        default:
            std::cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}

/*Design  the class(es) for the following scenario:
An item list contains item code, name, rate, and quantity for several items.
Whenever a new item is added in the list uniqueness of item code is to be checked.
Time to time rate of the items may change.
Whenever an item is issued or received existence of the item is checked and quantity is updated.
In case of issue, availability of quantity is also to be checked.
User may also like to know price/quantity available for an item.*/

#include <iostream>
class ITEM{
    std::string code;
    std::string name;
    int rate;
    int quantity;
public:
    ITEM(){               //constructor which sets the rate and quantity to integer value 0
        rate = 0;
        quantity = 0;
    }
    void setCode(std::string c){ //function to set code
        code = c;
    }
    void setName(std::string n){ //function to set name
        name = n;
    }
    void setRate(int r){    //function to set rate
        rate = r;
    }
    void setQuantity(int q){  //function to set quantity
        quantity = q;
    }
    std::string getCode(){ //function to return code
        return code;
    }
    std::string getName(){  //function to return name
        return name;
    }
    int getRate(){  //function to return rate
        return rate;
    }
    int getQuantity(){  //function to return quantity
        return quantity;
    }
};
int main(){
    ITEM *itemlist[20]; //arrays of object pointers of class ITEM
    int i=0, j;
    std::string code1, name1;
    int rate1, quantity1;
    int choice, flag;
    do{
        std::cout<<"1. Add an item\n";
        std::cout<<"2. Change rate of item\n";
        std::cout<<"3. Add quantity of existing item(Receive by shopkeeper)\n";
        std::cout<<"4. Remove quantity of existing item(Issue to customer)\n";
        std::cout<<"5. Enquire price and quantity of an item\n";
        std::cout<<"6. Exit!\n\n";
        std::cout<<"Enter a choice number: ";
        std::cin>>choice;
        switch(choice){
        case 1:
            itemlist[i] = new ITEM;
            std::cout<<"Enter code of the item: ";
            std::cin>>code1;
            for(j=0;j<=i;j++){
                if(itemlist[j]->getCode()==code1){  //check if code exists
                  std::cout<<"Item code already exist. Please re-enter a different code!\n";
                  std::cout<<"Enter code of the item: ";
                  std::cin>>code1;
                  break;
                }else continue;
            }
            itemlist[i]->setCode(code1);
            std::cout<<"Enter name of the item: ";
            std::cin>>name1;
            itemlist[i]->setName(name1);
            std::cout<<"Enter rate of the item: ";
            std::cin>>rate1;
            itemlist[i]->setRate(rate1);
            std::cout<<"Enter quantity of the item: ";
            std::cin>>quantity1;
            itemlist[i]->setQuantity(quantity1);
            i++; //increase number of item by one
            std::cout<<"Item added to list successfully! \n";
            break;
        case 2:
            flag =0;
            std::cout<<"Enter code of the item: ";
            std::cin>>code1;
            for(j=0;j<i;j++){
                if(itemlist[j]->getCode()==code1){
                    std::cout<<"\nEnter new rate of the item: ";
                    std::cin>>rate1;
                    itemlist[j]->setRate(rate1);
                    std::cout<<"Rate changed successfully!\n";
                    flag = 1;
                    break;
                }
            }
            if(!flag)   //check for valid code
                std::cout<<"Item not found.\n";
            break;
        case 3:
            flag =0;
            std::cout<<"Enter code of the item: ";
            std::cin>>code1;
            for(j=0;j<i;j++){
                if(itemlist[j]->getCode()==code1){
                    if(itemlist[j]->getQuantity()==0){
                        std::cout<<"\nNo available quantity for this item! Enter quantity you want to add to available quantity: ";
                        std::cin>>quantity1;
                        itemlist[j]->setQuantity(quantity1);
                        std::cout<<"Quantity of the item added successfully.\n";
                    }
                    else{
                        std::cout<<"\nEnter quantity you want to add to available quantity: ";
                        std::cin>>quantity1;
                        quantity1 += (itemlist[j]->getQuantity());
                        itemlist[j]->setQuantity(quantity1);
                        std::cout<<"Quantity of the item added successfully.\n";
                    }
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                std::cout<<"Item not found.\n";
            break;
        case 4:
            flag =0;
            std::cout<<"Enter code of the item: ";
            std::cin>>code1;
            for(j=0;j<i;j++){
                if(itemlist[j]->getCode()==code1){
                    flag = 1;
                    if(itemlist[j]->getQuantity()==0){
                        std::cout<<"\nNo available quantity for this item! You cannot issue this item.\n";
                    }
                    else{
                        std::cout<<"\nThis item is available for issue.\n";
                        std::cout<<"Enter quantity you want to remove from available quantity: ";
                        std::cin>>quantity1;
                        quantity1 = (itemlist[j]->getQuantity()) - quantity1;
                        if(quantity1<0) std::cout<<"Sorry! Only "<<itemlist[j]->getQuantity()<<" quantity available. You cannot issue this item.\n";
                        else {
                            itemlist[j]->setQuantity(quantity1);
                            std::cout<<"Quantity of the item removed successfully.\n";
                        }
                    }
                    break;
                }
            }
            if(!flag)
                std::cout<<"Item not found.\n";
            break;
        case 5:
            flag =0;
            std::cout<<"Enter code of the item: ";
            std::cin>>code1;
            for(j=0;j<i;j++){
                if(itemlist[j]->getCode()==code1){
                    flag = 1;
                    std::cout<<"\nName of existing item: "<<itemlist[j]->getName()<<"\n";
                    std::cout<<"Rate of existing item: Rs. "<<itemlist[j]->getRate()<<"\n";
                    std::cout<<"Quantity of existing item: "<<itemlist[j]->getQuantity()<<"\n";
                    break;
                }
            }
            if(!flag)
                std::cout<<"Item not found.\n";
            break;
        case 6:
          for (int k = 0; k <i; k++) {
            delete itemlist[k];
          }
            exit(0);
        default:
            std::cout<<"\nPlease enter a valid choice.\n";
            break;
        }
    }while(1);
    return 0;
}

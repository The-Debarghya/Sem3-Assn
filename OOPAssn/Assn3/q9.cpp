/*Design a class TIME which stores hour, minute and second.The class should have the methods to support the following:
User may give the time value in 24-hour format.
User may give the time value in AM/PM format
Display the time in 24-hour format.
Display the time in AM/PM format.
User may like to add minute with a time value.*/
#include <iostream>
class TIME{
    int hour; //private members of class TIME
    int minute;
    int second;
    std::string time;
public:  //public members of class TIME
    TIME(){  //constructor which sets the values of hour, minute, second to 0
        hour = 0;
        minute = 0;
        second = 0;    
    }
    void Set_Time(){ //member function that takes the time input
        std::cout<<"Enter time in am/pm format or 24-hour format : ";
        std::cin>> time;
        hour = ((time[0]-48)*10)+(time[1]-48);
        minute = ((time[3]-48)*10)+(time[4]-48);
        second = ((time[6]-48)*10)+(time[7]-48);
        if(hour<24 && minute<60 && second<60 && time[2]==':' && time[5]==':')
                std::cout<<"\n";
        else
            std::cout<<"\nPlease input a valid time!\n";
    }
    void am_pm_format(){ //member func that prints the given time in am/pm format
        if(time[2]==':' && time[5]==':' && minute < 60 && second <60){
            std::cout<<"The time in am/pm format is ";
            if(hour==0){     //check for 00:00:00
                std::cout<<(hour+12)%24<<":"<<minute<<":"<<second<<"am"<<"\n";
            }
            else if(hour<=12){
                if(time[8] == 'a' || time[8] == 'A'){  //check for am/pm
                    std::cout<<(hour)%24<<":"<<minute<<":"<<second<<"am"<<"\n";
                }
                else if(time[8] == 'p' || time[8] == 'P'){  //check for am/pm
                    std::cout<<(hour)%24<<":"<<minute<<":"<<second<<"pm"<<"\n";
                }
                else if(hour == 12)  //check for 12:00:00
                    std::cout<<(hour)%24<<":"<<minute<<":"<<second<<"pm"<<"\n";
                else  //in 24hr format <12 implies am
                    std::cout<<(hour)%24<<":"<<minute<<":"<<second<<"am"<<"\n";
            }
            else if(hour>12){
                std::cout<<(hour-12)%24<<":"<<minute<<":"<<second<<"pm"<<"\n";
            }
        }
        else{ std::cout<<"You have entered time in incorrect format.\n";
        }
    }
    void hours_format(){ //member function to print the time in 24 hour format
        if(time[2]==':' && time[5]==':' && minute < 60 && second <60){  //check if the time is valid
            std::cout<<"The time in 24-hour format is ";
            if(time[8] == 'a' || time[8] == 'A'){  //check for am
                if(hour == 12) {   //check for 00:00:00 if time is in am
                    std::cout<<(hour-12)%24<<":"<<minute<<":"<<second<<"\n";
                  }
                else{
                    std::cout<<(hour)%24<<":"<<minute<<":"<<second<<"\n";
                  }
            }
            else if(time[8] == 'p' || time[8] == 'P'){  //check for pm
                if(hour == 12)
                    std::cout<<(hour)%24<<":"<<minute<<":"<<second<<"\n";
                else
                    std::cout<<(hour+12)%24<<":"<<minute<<":"<<second<<"\n";
            }
            else{
                std::cout<<(hour)%24<<":"<<minute<<":"<<second<<"\n";
            }
        }
        else{ std::cout<<"You have entered time in incorrect format.\n"; }
    }
    void Add_Minutes(){ //member function to add minutes to time value
        int min;
        std::cout<<"Enter minutes you want to add to time : ";
        std::cin >> min;
        if(min>=0){
            minute = minute + min;
            if(minute>=60){   //checks if minutes have crossed 60
                hour = hour +(minute / 60);
                if(hour>23) hour = hour%24;
                minute = minute % 60;
                if(time[8]=='a'){
                    if(hour>11) time[8]='p';
                }
                else if(time[8]=='p'){
                    if(hour>11) time[8]='a';
                }
            }
        }
        else {std::cout<<"Sorry! You cannot add -ve minutes to time\n";}
    }
};
int main(){
    TIME t; //define a class object
    int choice;
    do{ //loop which continues until user input choice number 5 to exit
        std::cout<<"\n---------------------------------------------------------\n";
        std::cout<<"1. Input a time in am/pm or 24-hour format\n2. Display time in am/pm format\n3. Display time in 24-hour format\n4. Add minutes to time\n5. Exit!\n\n";
        std::cout<<"Enter a choice number: ";
        std::cin>>choice;
        switch(choice){
        case 1:
            t.Set_Time(); //calling Set_Time function of class TIME
            break;
        case 2:
            t.am_pm_format();  //calling am_pm_format function of class TIME
            break;
        case 3:
            t.hours_format();  //calling hours_format function of class TIME
            break;
        case 4:
            t.Add_Minutes();  //calling Add_Minutes function of class TIME
            break;
        case 5:
            exit(0);
        default:
            std::cout<<"1. Input a time in am/pm or 24-hour format\n2. Display time in am/pm format\n3. Display time in 24-hour format\n4. Add minutes to time\n5. Exit!\n\n";
            break;
        }
    }while(1);
    return 0;
}

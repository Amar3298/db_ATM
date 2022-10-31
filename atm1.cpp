#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class atm1{
    private:
        long int account_no;
        string name;
        int pin;
        double balance;
        string mobile_no;
    public:
        void setData(long int account_no_p,string name_p,int pin_p,double balance_p,string mobile_no_p){
            account_no = account_no_p;
            name = name_p;
            pin = pin_p;
            balance = balance_p;
            mobile_no = mobile_no_p;
        }
        long int getAccountNo(){
            return account_no;
        }
        string getName(){
            return name;
        }
        int getPin(){
            return pin;
        }
        double getBalance(){
            return balance;
        }
        string getMobileNo(){
            return mobile_no;
        }
        void setMobile(string mob_prev,string mob_new){
            if(mob_prev==mobile_no){
                mobile_no = mob_new;
                cout<<endl<<"Successfully Updated Mobile No ";
                _getch();
            }
            else{
                cout<<endl<<"Incorrect!!! Old Mobile No ";
                _getch();
            }
        }

        void cashWithDraw(int amount_a){
            if(amount_a>0 && amount_a<balance){
                balance -= amount_a;
                cout<<endl<<"Please Collect your cash ";
                cout<<endl<<"Available Balance is: "<<balance;
                _getch();
            }
            else{
                cout<<endl<<"Invalid Input or Insufficient Balance";
                _getch();
            }
        }
};
int main(){
    int choice=0,enterPIN;
    long int enterAccountNo;
    system("cls");
    atm1 db1;
    db1.setData(5,"Dragon Ball",2001,50000,"7588057848");
    while(true){
        system("cls");
        cout<<"\n****Welcome to ATM****"<<endl;
        cout<<endl<<"Enter Your Account No: ";
        cin>>enterAccountNo;
        cout<<endl<<"Enter PIN: ";
        cin>>enterPIN;

        if((enterAccountNo==db1.getAccountNo()) && (enterPIN==db1.getPin())){
            while(true){
                int amount = 0;
                string oldMobileNo,newMobileNo;
                system("cls");
                cout<<"\n****Welcome to ATM****"<<endl;
                cout<<"\nSelect Options ";
                cout<<"\n1. Check Balance ";
                cout<<"\n2. Cash WithDraw ";
                cout<<"\n3. Show User Details ";
                cout<<"\n4. Update Mobile no. ";
                cout<<"\n5. Exit "<<endl;
                cin>>choice;

                switch(choice){
                    case 1:
                        cout<<"\nYour Bank balance is :"<<db1.getBalance();
                        _getch();
                        break;
                    case 2:
                        cout<<"\nEnter the amount :";
                        cin>>amount;
                        db1.cashWithDraw(amount);
                        break;
                    case 3:
                        cout<<"\n****User Details are :- ";
                        cout<<"\n-> Account no "<<db1.getAccountNo();
                        cout<<"\n-> Name       "<<db1.getName();
                        cout<<"\n-> Balance    "<<db1.getBalance();
                        cout<<"\n-> Mobile No. "<<db1.getMobileNo();
                        _getch();
                        break;  
                    case 4:
                        cout<<"\nEnter Old Mobile No.";
                        cin>>oldMobileNo;
                        cout<<"\nEnter New Mobile No.";
                        cin>>newMobileNo;

                        db1.setMobile(oldMobileNo,newMobileNo);
                        // _getch();
                        break;
                    case 5:
                        exit(0);
                    default:
                        cout<<"Enter Valid Data!!!";
                }
            }
        }
    }
     return 0;
}
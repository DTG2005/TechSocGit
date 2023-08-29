/*
This program only allows for 10 accounts to exist on runtime.
*/
#include <limits>
#include <iostream>
#include <string>

using namespace std;


//Specifying array that will sequentially PIN credentials of the users
int PIN[10];

//With that out, we can store the balance and other credentials in the other fields
float Bal[10];
int currUID = 0;
string Name[10];
string Address[10];

class Account{

public:
    float getbal(){
        return Balance;
    }
    void Deposit(){
        int moni;
        cout<<"Enter the amount you wish to deposit"<<endl;
        cin>>moni;
        Balance +=moni;
        cout<<"Money deposited! You now have "<<Balance<<"in your account."<<endl;
    };
    void Withdraw(){
        int WithAmt;
        cout<<"Enter the amount you wish to withdraw"<<endl;
        cin>>WithAmt;
        Balance -=WithAmt;
        cout<<"Money withdrawn! You now have "<<Balance<<"in your account."<<endl;
    }
    void View(){
        cout<<"Your Name is "<<Name<<endl;
        cout<<"Your Address is "<<Addr<<endl;
        cout<<"Your Balance is "<<Balance<<endl;

    }
    void Send(int uid){
        int amt;    
        cout<<"Enter amount you wish to send to the given UID";
        cin>>amt;
        Bal[uid] += amt;
        Balance -=amt;
        cout<<"\nTransaction successful!"<<endl; 
    }
    Account(string name, string addr, float openingBal){
        Name = name;
        Addr = addr;
        Balance = openingBal;
    }
    string Name;

private:
    int UID;
    string Addr;
    float Balance;
    int PIN;
};

int main(){

    while (true){
        string response;
        int pin;

        cout<<"WELCOME TO THE BANK SYSTEM. LOGIN OR REGISTER TO CONTINUE!\n1. Login\n2. Register.\nx. Exit"<<endl;
        cin>>response;
        if (response == "x"){
            break;
        } else if (response == "2")
        {
            string nam, Addr;
            int starBal, pIN;

            cout<<"Please enter your name: ";
            cin >> nam;
            cout<<"Please enter the starting balanace that you wish to start off with: ";
            cin>> starBal;
            cout<<"Please enter the Address: ";
            cin >> Addr;
            cout<<"Now, the most important part: Please enter a unique PIN number to lock your account!"<<endl;
            cin >> pIN;

            Name[currUID]= nam;
            Bal[currUID] = starBal;
            Address[currUID]=Addr;
            PIN[currUID]= pIN;

            cout<<"YOU ARE NOW REGISTERED! Your UID is "<< currUID<<"! LOGIN TO SEE THE NEXT PAGE!"<<endl;
            currUID++;
        } else if (response == "1")
        {
            int UID, pin;
            cout<<"Enter your UID!"<<endl;
            cin>>UID;
            cout<<"Enter your PIN!!"<<endl;
            cin>>pin;
            if (pin == PIN[UID])
            {
                Account Acc1(Name[UID], Address[UID], Bal[UID]);
                while (true){
                    string ch;
                    cout<<"Welcome, "<<Acc1.Name<<"!!! Choose an option to continue:-\n1. Deposit\n2. Withdraw\n3. View Balance\n4. Send\nx. Log Out"<<endl;
                    cin>>ch;
                    if (ch=="x" ||ch=="X"){
                        Bal[UID]=Acc1.getbal();
                        break;
                    }else if (ch == "1")
                    {
                        Acc1.Deposit();
                    } else if (ch == "2")
                    {
                        Acc1.Withdraw();
                    } else if (ch == "3")
                    {
                        Acc1.View();
                    } else if (ch == "4")
                    {
                        int uid;
                        cout<<"Enter UID you wish to send money to: "<<endl;
                        cin>>uid;
                        Acc1.Send(uid);
                    }
            }
            }
            else
            {
                /* code */
            }
        }
        
    }
}


#include <iostream>

using namespace std;

//A simple straightforward Add function
float Add(){
    float a, b;
    cout<<"Enter first number: "<<endl;
    cin >>a;
    cout<<"Enter second number:"<<endl;
    cin>>b;
    return a+b;
}

//similarly straightforward subtract function
float Subt(){
    float a, b;
    cout<<"Enter first number: "<<endl;
    cin >>a;
    cout<<"Enter second number:"<<endl;
    cin>>b;
    return a-b;
}

//similarly straightforward multiply function
float Mult(){
    float a, b;
    cout<<"Enter first number: "<<endl;
    cin >>a;
    cout<<"Enter second number:"<<endl;
    cin>>b;
    return a*b;
}

//Divide function requires some debugging of a little complex order since it is a problem if someone tries to divide by 0
float Div(){
    float a, b = 0;
    cout<<"Enter first number"<<endl;
    cin>>a;
    cout<<"Enter second number"<<endl;
    cin>>b;
    while (b==0){
        cout<<"Wrong entry detected: cannot divide by 0!!!"<<endl;
        cout<<"Enter second number"<<endl;
        cin>>b;
    } 
    return a/b;
}

//I executed exponentiation by using loops, the hard way
//However, as it is very much the hard way, it only supports integers
float Exp(){
    float a;
    int b;
    cout<<"Enter base: ";
    cin>>a;
    cout<<"\nEnter power (Only enter integer values!):"<<endl;
    cin>>b;
    float exp =1;
    int i = 0;
    while (i<b){
        exp *=a;
        i++;
    }
    return exp;
}

//Alright so using Taylor Series, I find out sin
float Sin(){
    float inp;
    cout<<"Enter the input in radians (only use -pi to pi): "<<endl;
    cin>>inp;
    //sin = x - x^3/3 + x^5/5 -x^7/7
    float exp=1;
    int i = 0;
    while (i<3){
        exp=exp*inp;
        i++;
    }
    float out;
    out = inp-(exp/3);
    i = 0;
    exp = 1;
    while (i<5){
        exp=exp*inp;
        i++;
    }
    out = out + (exp/5);
    i = 0;
    exp = 1;
    while (i<7){
        exp = exp*inp;
        i++;
    }
    out= out - (exp/7);
    return out;
}
//Sin can be used to derive other functions using trigonometric identities. For cos, however, a similar Taylor expansion can be used too.
float Cos(){
    float inp;
    cout<<"Enter the input in radians (only use -pi to pi): "<<endl;
    cin>>inp;
    //cos = x^2/2 - x^4/4 + x^6/6 -x^8/8
    float exp=1;
    int i = 0;
    while (i<2){
        exp=exp*inp;
        i++;
    }
    float out;
    out = (exp/2);
    i = 0;
    exp = 1;
    while (i<4){
        exp=exp*inp;
        i++;
    }
    out = out - (exp/4);
    i = 0;
    exp = 1;
    while (i<6){
        exp = exp*inp;
        i++;
    }
    out= out + (exp/6);
    i = 0;
    exp = 1;
    while (i<8){
        exp = exp*inp;
        i++;
    }
    out= out + (exp/8);
    return 1-out;
}
//tan can be calculated by dividing sin and cos, reciprocals can be obtained by using division in conjunction with trigo outputs

int main(){
    //calculator prompt
    while(true){
        string resp;
        cout <<"CHOOSE ANY ONE OF THE FOLLOWING OPERATIONS:-\n1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n5. EXPONENTIATION\n6. Sin\n7. Cos\nx. EXIT"<< endl;
        cin >> resp;
        if (resp == "x"){
            break;
        }else if (resp == "1")
        {
            auto ans = Add();
            cout<<"\nAnd the answer is:"<<ans<<endl;
        } else if (resp == "2")
        {
            auto ans = Subt();
            cout<<"\nAnd the answer is:"<<ans<<endl;
        } else if (resp == "3")
        {
            auto ans = Mult();
            cout<<"\nAnd the answer is:"<<ans<<endl;
        } else if (resp == "4")
        {
            auto ans = Div();
            cout<<"\nAnd the answer is:"<<ans<<endl;
        } else if (resp == "5")
        {
            auto ans = Exp();
            cout<<"\nAnd the answer is:"<<ans<<endl;
        } else if (resp == "6")
        {
            auto ans = Sin();
            cout<<"\nAnd the answer is:"<<ans<<endl;
        } else if (resp == "7")
        {
            auto ans = Cos();
            cout<<"\nAnd the answer is:"<<ans<<endl;
        }
        
    }
    return 0;
}
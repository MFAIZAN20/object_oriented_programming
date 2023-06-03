#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class accountType
{
	string name;
	int balance;
public:
/*Setting the Balance & Name*/
void setname(string per_name)
{
    name=per_name;
}
void setbalance(int amount)
{
    balance=amount;	
}

/*Creating Account*/
void create_account(string user,int credit){
    setname(user);
    setbalance(credit);
}
/*Getting Values Through Accessors And Mutators */
int getbalance(){
    return balance;
}
string getname(){
    return name;
}
/*Function For show Balance */
void show_balance(){
    
    cout<<"Your Name is"<<getname()<<endl;
    cout<<"Your Name is"<<getbalance()<<endl;
}
/* Functions For Deposit & Withdraw */
void withdraw(int amt){
    int temp,total_amt;
    temp=getbalance();
    if (temp >= amt)
    {
        total_amt=temp-amt;
        setbalance(total_amt);
        cout<<"Your Current Balance Is : "<<total_amt<<endl;
    }
    else{
        cout<<"Your Current Balance Is Very Low"<<endl;
    }
}
void deposit(int amount){
    int temp,total_amount;
    

    temp=getbalance();
    
    total_amount=temp+amount;
    setbalance(total_amount);
    
    cout<<"Your Balance Is updated Successfully\nYour Current Balance is : "<<total_amount<<endl;
}
};
int main(){
    accountType account_obj;
    int option,balance,with_amt;
    string name;

        cout<<"Please Enter Your Name: "<<endl;
        getline(cin,name);

        cout<<"Your Your Current Credit : "<<endl;
        cin>>balance;

    account_obj.create_account(name,balance);

while (option != 4)
    {
        cout<<"\t\t\t Welcom To The Your Account \n1. Display Balance \n2. Deposit Balance \n3. Withdraw Balance\n4. Exit From Program"<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
        account_obj.show_balance();
            break;
        case 2:
        int amount;
            cout<<"Please Enter The Amount You Want To Withdraw"<<endl;	
            cin>>with_amt;
        account_obj.deposit(amount);
            break;
        case 3:
            cout<<"Please Enter The Amount You Want To Withdraw"<<endl;	
            cin>>with_amt;
            account_obj.withdraw(with_amt);
            break;
        }
    }
    return 0;
}

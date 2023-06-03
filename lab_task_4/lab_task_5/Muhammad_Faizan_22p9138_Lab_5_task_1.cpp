#include "header.h"
using namespace std;

class storeType
{
	string uniqueId;
	string Pnsme;
    double price;
    int quantity
public:
    storeType(uniqueId_c=0,pname_c=0,price_c=0,quantity_c=0;)
    {
        uniqueID=uniqueId_c;
        Pname=pname_c; 
        price=price_c;
        quantity=quantity_c;
    }
void setname(string per_name)
{
    name=per_name;
}
void setbalance(int amount)
{
    return balance=amount;	
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
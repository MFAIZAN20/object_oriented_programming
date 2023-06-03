#include <iostream>
#include <string>
using namespace std;
int check_password(string pass);
int special_checked(string spe_text);
int main(){
string password;
    cout<<"Please Enter Your Password"<<endl;
    getline(cin,password);
}
void check_password(string pass){
    int z;

    if (pass.length() >=8)
    {
       cout<<"Please Enter Your Password Again"<<endl;
       z=special_checked(pass); 
        if (z==0)
        {
            cout<<"Your Password Special Letter"<<endl;
        }
        else
        {
            cout<<"Your Password Does not Contain Any Special Letter"<<endl;
        }
        
    }
    else
    {
        cout<<"You Entered The Wrong Password";
    }
    
}
int special_checked(string special_checked){
    char x; 
    int flag=0;
    int a=special_checked.length();
    for (int i=0; i<a; i++)
    {
        if(special=='%'||special=='!'||special=='*'||special=='^'||special=='&')
        {
        return flag;
        }
        else{
            cout<<"Your Password Does not Contain Any Special Letter"<<endl;
        return flag;
        }
    }
}

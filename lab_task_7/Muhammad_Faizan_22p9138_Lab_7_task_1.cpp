#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class DOBType{
    int Day;
    int Month;
    int Year;
    public:

    DOBType(int day=1,int month=1,int year=2020){
        setbirth(day,month,year);
    }

    void setbirth(int d,int m, int y){
    /* For Day */
        if (d > 0 && d <32)
        {
            Day=d;
        }
        else
        {
            cout<<"Invalid Value Of The Day"<<endl;
            Day=1;
        }
    /* For Month */
        if (m > 0 && m <13)
        {
            Month=m;
        }
        else
        {
            cout<<"Invalid Value For The Month"<<endl;
            Month=1;
        }
    /* For Year*/
        if (y > 1960 && y <2015)
        {
            Year=y;
        }
        else
        {
            cout<<"Invalid Value For The Year"<<endl;
            Year=2002;
        }
    }
    /* Getter Function */
    int getday(){
        return Day;
    }
    int getmonth(){
        return Month;
    }
    int getyear(){
        return Year;
    }
};
class contactType{
    string name;
    string phone_num;
    string em_add; 
    DOBType birth;
    public:  
    contactType(string pname="faizan",string pnum="0123456",string mail = "abc@gmail.com", int a=1,int b=3,int c=2003):birth(a,b,c){
        setinfo(pname,pnum,mail,a,b,c);
    }
    /*One Stter Function For Name,Phone Number & Mail */
    void setinfo(string cname,string cpnum,string cmail,int a,int b,int c)
    {
        if (cname.empty())
        {
            cname="faizan";
            name=cname;
        }
        else
        {
            name.assign(cname);
        }

        if (cpnum.empty())
        {
            cpnum="0123456";
            phone_num=cpnum;
        }
        else
        {
            phone_num.assign(cpnum);
        }

        if (cmail.empty())
        {
        cmail="abc@gmail.com";
        em_add=cmail; 
        }
        else
        {
        em_add.assign(cmail);
        }

        /* Birth Function IS Just Call Here*/
        birth.setbirth(a,b,c);
    }

    /* Getter Functions */

    string getname(){
        return name;
    }
    string getphone(){
        return phone_num;
    }
    string getemail(){
        return em_add;
    }

    void print_all_contacts(contactType* obj ,int lsize,int no_month) {
        int check;
        cout<<"Welcome To The Contact Show Menu";
        
        for (int i = 0; i < lsize; i++)
        {
            check= obj[i].birth.getmonth();
            if (no_month == check)
            {
                cout<<"The Birth Day is : "<<obj[i].birth.getday()<<"/"<<obj[i].birth.getmonth()<<"/"<<obj[i].birth.getyear()<<endl;
                cout<<"The Name Is : "<<obj[i].getname()<<endl;
                cout<<"The Phone Number Is : "<<obj[i].getphone()<<endl;
                cout<<"The Email Address Is : "<<obj[i].getemail()<<endl;
            }
            else {
                cout<<"No Contact Lsit Is Founded"<<endl;
            }
         }
     }
};
class contact_bookType
{
   int  size;
    contactType* contactlist;
public:
    /* Constructor */
    contact_bookType(int s=0)
    {  
        setsize(s); //Setting The Size Through Setter
        contactlist=new contactType[size];
    }
    /* Setting The Contact Lsit Size */
    void setsize(int s){
        cout<<"Welcome To The Size Setting Of Contact List"<<endl;
        cout<<"Please Enter The Size  Of Contact List"<<endl;
        cin>>s;

        if (s >= 0)
        {
            size = s;
        }
        else
        {
            size=0;
        }
        cout<<"The Size Is Successfully Gererated "<<endl;
    }
    
    /* Returning The Size OF Contact List Throught Getter */
    int getlistsize(){
        return size;
    }
    /* Setting All COntact Infromation */
    
    void setalldata(){
    
    /* Declare The Variables */
        int x,a,b,c; 
        string fname,fphone,fmail;
        
        x = getlistsize();      //List Size

        /* Insertion Of Data Through For Loop */
        for (int i = 0; i < x; i++)
        {
            /*Taking The Personal Information From The User*/
            cout<<"Please Enter Your Name For "<<i+1<< ":"<<endl;
            cin>>fname;

            cout<<"Please Enter Your Phone Number "<<i+1<< ":"<<endl;
            cin>>fphone;

            cout<<"Please Enter Your Emaiil Address "<<i+1<< ":"<<endl;
            cin>>fmail;

            /*Taking date OF Birth Form The User*/
            
            cout<<"Please Enter The Birth Day Of The Person" <<i+1<< ":"<<endl;
            cin>>a;
            cin>>b;
            cin>>c;

            contactlist[i].setinfo(fname,fphone,fmail,a,b,c);
        }
    }
    void display(int month_no){
        int listsize = getlistsize();
        contactlist->print_all_contacts(contactlist,listsize,month_no);
    }
    ~contact_bookType(){
        delete[] contactlist;
    }
};

int main(){
    int month,option=0;;
    contact_bookType booklist;
    booklist.setalldata();
    
    cout<<"Welcome To The Contact Book List.\n\t 1.To Print Specific Contact By Month.\n\t 2.To Exit From The Program"<<endl;
    while (option != 2)
    {
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Please Enter The Month Number"<<endl;
            cin>>month;
            booklist.display(month);
            break;
        }
    }
    return 0;
}
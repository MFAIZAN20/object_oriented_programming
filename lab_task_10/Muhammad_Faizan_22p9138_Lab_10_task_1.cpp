#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class animal
{
    protected:
    string name;
    string color;
    bool hasAntlers;
    void virtual display() = 0;
    
    animal(string nam = "null",string col = "null",bool antlers = false)
    {
        setname(nam);
        setcolor(color);
        setantlers(antlers);
    }

    ~animal(){
        cout<<"Disructor Is Called"<<endl;
    }

    /* Setter For The Parent Class */

    void setname(string a_nam){
        if (!a_nam.empty())
        {
            name = a_nam;
        }
        else
        {
            name = "not_animal";
        }

    }
    
    void setcolor(string a_col){
        if (!a_col.empty())
        {
            color = a_col;
        }
        else
        {
            color = "NoColor";
        }
    }

    void setantlers(int antl){
        if (antl == 1)
        {
            hasAntlers = true;
        }
        else if ( antl == 0)
        {
            hasAntlers = false;
        }
        else 
        {
            cout<<"Invalid Valued entered"<<endl;
        }
    }

    /* Getters For The Child Class */

    string getname(){
        return name;
    }
    
    string getcolor(){
        return color;
    }

    bool getantlers(){
        return hasAntlers;
    }
};

class deer : private animal
{
    string stripe_pattern;
public:
    deer(string pattern = "Null", string a_name = "Null", string a_color = "Null",bool a_antler = false):animal(a_name,a_color,a_antler)
    {
        setstripe_pattern(pattern);
    }

    /* Setter For Child Class */
    void setstripe_pattern(string stripe){
        if (!stripe.empty())
        {
            stripe_pattern = stripe;
        }
        else
        {
            stripe_pattern = "black";
        }
    }

    /* Getter For Child Class */

    string getstripe_pattern(){
        return  stripe_pattern;
    }

    void set_All_data(){
        char option;
        bool an_antler;
        string an_name,an_color, an_pattern;
        cout<<"Please Enter The Name OF Your Animal :"<<endl;
        getline(cin,an_name);
        setname(an_name);
        
        cout<<"Please Enter The Color OF Your Animal :"<<endl;
        cin>>an_color;
        setcolor(an_color);

        cout<<"Does The Deer Has Antlers  Of Your Animal ?\n Choose 1 For Ture & 0 For False. :"<<endl;
        cin>>an_antler;
        setantlers(an_antler);

        cout<<" Does The Deer Has Pattern On Its Body ?: \n Y & n For Yes & N or n For No Patter"<<endl;
        cin>>option;
        

        if (option == 'Y' || option == 'y')
        {
        cout<<"Please Enter The Patter On The Deer:"<<endl;
        cin>>an_pattern;
        setstripe_pattern(an_pattern);
        }
        else if (option == 'N' || option == 'n')
        {
            cout<<"You Selected No pattern Deer"<<endl;
        }
        else 
        {
            cout<<"Invalid Operation Occured"<<endl;
        }

        }

        void display(){
        string n,c,s;
        cout<<"Name Of Your animal is :"<<getname()<<endl;
        cout<<"The Color Of Your Animal Is:"<<getcolor()<<endl;
        if (getantlers() == true)
        {
        cout<<"The Deer Has The Anterls"<<endl;
        }
        else if(getantlers () == false)
        {
            cout<<"The Deer Has No The Anterls"<<endl;
        }
        else
        {
            cout<<"Invalid Vavlued Entered For The Animal "<<endl;
        }
        
        cout<<"The Pattern on Animal is "<<getstripe_pattern()<<endl;
        }

        ~deer(){
            cout<<"Destructor Is Called For Child Class"<<endl;
        }

};
int main(){
    deer ani_deer ("dn","adf","dfd",false);
    ani_deer.set_All_data();
    ani_deer.display();
    return 0;
    }
    
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class animal
{   
    protected:
    string name;
    string color;

    public:
    void virtual display() = 0;
    animal(string nam = "Aniaml",string col = "Brown")
    {
        setname(nam);
        setcolor(color);
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

    /* Getters For The Child Class */

    string getname(){
        return name;
    }
    
    string getcolor(){
        return color;
    }

    
};

class deer : public animal
{
    bool hasAntlers;
    
public:
    /* constructor For The Deer Class */
    deer(string a_name = "Deer", string a_color = "Dark Brown",bool a_antler = true)
    {
        setname(a_name);
        setcolor(a_color);
        setantlers(a_antler);
    }

    /* Setter For Child Class */
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

    /* Getter Function */
    bool getantlers()
    {
        return hasAntlers;
    }

   void set_All_data()
    {
        char option;
        bool an_antler;
        string an_name,an_color, an_pattern;
        cin.ignore();
        cout<<"Please Enter The Name OF Your Animal :"<<endl;
        getline(cin,an_name);
        setname(an_name);
        
        cout<<"Please Enter The Color OF Your Animal :"<<endl;
        cin>>an_color;
        setcolor(an_color);

        cout<<"Does The Deer Has Antlers  Of Your Animal ?\n Choose 1 For Ture & 0 For False. :"<<endl;
        cin>>an_antler;
        setantlers(an_antler);
    }

    void display()
    {
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
    }
    ~deer()
    {
        cout<<"Destructor Is Called For Child Deer Class"<<endl;
    }
};

class zebra :public animal
{
    string stripe_pattern;

    public:

    zebra(string z_name = "zebra", string z_color = "Whilte And Blask", string stripe = "black & white")
    {
        setname(z_name);
        setcolor(z_color);    
        setstripe_pattern(stripe);
    }

    void setstripe_pattern(string stripe)
    {
        if (!stripe.empty())
        {
            stripe_pattern = stripe;
        }
        else
        {
            stripe_pattern = "Black";
        }
    }

    /* Getter For Child Class */

    string getstripe_pattern()
    {
        return stripe_pattern;
    }

    /* Display Function For The Zebra Child Class */

    void display()
    {
        cout<<"Name Of Your animal is :"<<getname()<<endl;
        cout<<"The Color Of Your Animal Is:"<<getcolor()<<endl;
        cout<<"The Pattern On Zebra is : "<<getstripe_pattern()<<endl;
    }
    ~zebra()
    {
        cout<<"The Destructor For The Zebra Class Is Called"<<endl;
    }

    /* Set or Change The Data For The Zebra Class */

    void change_data()
    {
        char option;
        string az_name,az_color, az_pattern;
        cin.ignore();
        cout<<"Please Enter The Name OF Your Zebra :"<<endl;
        getline(cin,az_name);
        setname(az_name);
        
        cout<<"Please Enter The Color OF Your Zebra :"<<endl;
        cin>>az_color;
        setcolor(az_color);

        cout<<" Does The Deer Has Pattern On Its Body ?: \n Choose Y or y For Having Pattern & Choose For N or n For No Patter"<<endl;
        cin>>option;
        

        if (option == 'Y' || option == 'y')
        {
        cout<<"Please Enter The Patter On The Deer:"<<endl;
        getline(cin,az_pattern);
        setstripe_pattern(az_pattern);
        }
        else if (option == 'N' || option == 'n')
        {
            cout<<"You Selected No pattern Deer"<<endl;
            az_pattern = " Null ";
            setstripe_pattern(az_pattern);
        }
        else 
        {
            cout<<"Invalid Operation Occured"<<endl;
        }
    }

};
    /* Display Main Function */
void displayAll(animal* ani_obj[])
{
    ani_obj[0]->display();
    ani_obj[1]->display();
}
int main()
{
    int size = 2;
    deer obj_deer;
    zebra obj_zebra;

    animal* obj_animal[size];

    obj_animal[0] = new deer();
    obj_animal[1] =new zebra;

    int option;
    while (option != 7)
    {
        cout<<"Please Choose One OF The Option\n\t 1. To Diplay The Deer Information \n\t 2. To Display The Zebra information \n\t 3. To Display All \n\t 4. To Change The Deer Data \n\t 5. To Change Zebra Data \n\t 6. To Chnage Both Deer & Zebra Data \n\t 7. To Exit From Program"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            obj_deer.display();
            break;
        case 2:
            obj_zebra.display();
            break;
        case 3:
            displayAll(obj_animal);
            break;
        case 4:
            obj_deer.set_All_data();
        break;
        case 5:
            obj_zebra.change_data();
        break;
        case 6:
            obj_deer.set_All_data();
            obj_zebra.change_data();
        break;
        case 7:
            cout<<"Your Are Exited From The Program "<<endl;
        break;
        }
    }
    return 0;
}
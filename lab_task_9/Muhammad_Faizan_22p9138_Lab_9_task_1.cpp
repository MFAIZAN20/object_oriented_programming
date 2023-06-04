#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class animal
{
    public:
    
    string an_name;
    int an_age;

    animal(string name,int age)
    {
        /* Checks For Name */
        if (!name.empty())
        {
            an_name = name;
        }
        else
        {
            an_name = "Bird";
        }
    
        if (age >= 0)
        {
            an_age = age;
        }
        else
        {
            an_age = 0;
        }
    }
    void speak(){};

};

class birds : private animal
{
    double wing_lenght;
public:
    birds(string namee,int agee, double lenght):animal(namee,agee)
    {
        if (agee >= 0)
        {
            wing_lenght = agee;
        }
        else
        {
            agee = 0.0;
        }
    }

    void speak(){

        cout<<"The Name Of The Bird Is :"<<an_name<<endl;
        cout<<"The Age OF The Bird Is : "<<an_age<<endl;
        cout<<"The Wing Lenght "<<wing_lenght<<endl;
    }
};
class riptiale : private animal
{
    string habitat;
public:
    riptiale(string n , int a, string h):animal(n,a){
        if(!h.empty()){
            habitat = h;
        }
        else
        {
            habitat = "Not Live Any Where";
        }
    }
    void speak(){
        cout<<"The Name Of The Bird Is :"<<an_name<<endl;
        cout<<"The Age OF The Riptiale Is : "<<endl;
        cout<<habitat<<endl; 
    }
};
int main(){
    string a_name,hab;
    int a_age,option;
    double w_lenght;

    cout<<"Please Enter The Name OF Your Animal :"<<endl;
    getline(cin,a_name);

    cout<<"Please Enter The Age OF Your Animal :"<<endl;
    cin>>a_age;

    while (option != 3)
    {
        cout<<"Choose One OF The OPtion \n1.For Birds \n2.For Raptiles"<<endl;
        cin>>option;

        if(option ==1){
        cout<<"Please Enter The Lenght The Wings :"<<endl;
        cin>>w_lenght;
        birds coco(a_name,a_age,w_lenght);
        coco.speak();
        break;
        }
        else if(option ==2){
        cout<<"Please Enter The Habitat OF The Riptile :"<<endl;
        getline(cin,hab);
        riptiale raptile(a_name,a_age,hab);
        raptile.speak();
        break;
        }
    }
    return 0;
    }
    
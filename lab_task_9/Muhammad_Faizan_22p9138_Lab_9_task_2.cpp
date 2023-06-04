#include <iostream>
#include <string>

using namespace std;

class boat
{
public:
    double boatlenght;
    boat(int lenght ){
        if (lenght >= 0)
        {
            boatlenght = lenght;
        }
        else 
        {
            boatlenght = 0;
        }
    }
    void swim()
    {
        cout<<"Boat Lenght : "<<boatlenght<<endl;
    }
};
class plane
{
public:
    double maxattitude;
    
    plane(double attitude ){
        if ( attitude >= 0)
        {
            maxattitude = attitude;
        }
        else
        {
            maxattitude = 0;
        }
    }

    void fly()
    {
        cout<<"Maximum Attitude : "<<maxattitude<<endl;
    }
};

class Skimmer : protected boat , protected plane
{
    int numPessenger;
public:
    Skimmer(double l = 0, double m = 0 , int p = 0):boat(l),plane(m)
    {
        if (p >= 0)
        {
            numPessenger = p;
        }
        else
        {
            numPessenger = 0;
        }
    }
    void swim_and_fly()
    {
        cout<<"Swim & Fly" ;
        swim();
        fly();
        cout<<"The Number Of Pessenger Is : "<<numPessenger<<endl;
    }
};
int main(){
    double b_lenght,m_attitude;
    int n_pessenger;

    cout<<"Please Enter The Boat Lenght"<<endl;
    cin>>b_lenght;

    cout<<"Please Enter The Max Attitude"<<endl;
    cin>>m_attitude;

    cout<<"Please Enter The Number Of Pessenger In The Boat"<<endl;
    cin>>n_pessenger;

    Skimmer ski_fly(b_lenght,m_attitude,n_pessenger);
    ski_fly.swim_and_fly();

    return 0;
}
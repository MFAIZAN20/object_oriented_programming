#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Complex
{
    int real;
    int imag;
    public:

    //Comstructor For The Main

    Complex(int r = 0 , int m = 0)
    {
        setreal(r);
        setimag(m); 
    }
    /* Friend Functions */

    friend Complex operator+(Complex,Complex);
    
    /* Uninary Operator Overload Fun.*/

    friend Complex operator++(Complex&);
    /* Setter Funtions */
    void setreal(int re)
    {
        if (re >= 0)
        {
            real = re;
        }
        else
        {
            real = 0;
        }
    }

    void setimag(int im)
    {
        if (im >= 0)
        {
            imag = im;
        }
        else
        {
            imag = 0;
        }
    }
    
    //Printing The Data Of The Object

    void display()
    {
        cout<<"The Real Part OF Complex Number Is : "<<real<<" & Imageniry Part Is : "<<imag<<"i"<<endl;
    }
    
};
Complex operator+(Complex cobj_1,Complex cobj_2)
{   Complex reobj;

    reobj.real = cobj_1.real + cobj_2.real;
    reobj.imag = cobj_1.imag + cobj_2.imag;

    return reobj;
}

Complex operator++(Complex &com){
    com.real+1;
    return com;
}
/* Definition OF The Addition Complex Number Function*/
int main()
{   Complex sum;
    Complex ob_1(3,6);
    Complex ob_2(4,8);
    int option;
    while (option != 3)
    {   cout<<"Welcome To Task 5 OF Task Through Friend Functions "<<endl;
        cout<<"Please Select One Of The Following Option  \n\t 1. To Increment The Real Part Of The Complex Number \n\t 2. To Sum Two Complex Numbers"<<endl; 
        cin>>option;
        switch (option)
        {
        case 1:
            ob_1.display();
            cout<<"The Real Number is Successfully Incremented"<<endl;
            operator++(ob_1);
            ob_1.display();
            break;
        case 2:
            ob_1.display();
            ob_2.display();
            cout<<"The Sum Of The The Two Complex Number Is :"<<endl;
            sum=operator+(ob_1,ob_2);
            sum.display();
            break;
        case 3:
        cout<<"The Programm Is Successfully Exited"<<endl;
            break;
        }
    }
}
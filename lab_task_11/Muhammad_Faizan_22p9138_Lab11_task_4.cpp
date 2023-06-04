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

    //Setter Funtions
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
        cout<<"The Sum OF Real & Imag is :"<<real<<" + "<<imag<<"i"<<endl;
    }
    /* Binary Function */
    Complex operator+(Complex &com){   Complex reobj;

    reobj.real = real + com.real;
    reobj.imag = imag + com.imag;

    return reobj;
}
    /* Uniary Function */
    int operator++(){
    real++;
    return real;
}

};

/* Definition OF The Addition Complex Number Function*/
int main()
{
    Complex sum;
    Complex ob_1(2,8);
    Complex ob_2(7,9);

    int option;
    while (option != 3)
    {
        cout<<"Please Select One Of The Following Option  \n\t 1. To Increment The Real Part Of The Complex Number \n\t 2. To Sum Two Complex Numbers \n\t 3. To Exit From The Program"<<endl; 
        cin>>option;
        switch (option)
        {
        case 1:
            ob_1.display();
            cout<<"The Real Number is Successfully Incremented"<<endl;
            ob_1.operator++();
            ob_1.display();
            break;
        case 2:
            ob_1.display();
            ob_2.display();
            cout<<"The Sum Of The The Two Complex Number Is :"<<endl;
            sum =ob_1.operator+(ob_2);
            sum.display();
            break;
        case 3:
        cout<<"The Programm Is Successfully Exited"<<endl;
            break;
        }
    }
}
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Complex
{
    int real;
    int imag;
    public:

    /* Friend Class*/

    friend class friend_class;

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

    void print()
    {
        cout<<"The Sum OF Real & Imag is :"<<real<<" + "<<imag<<"i"<<endl;
    }
    
    
};

class friend_class
{   public:
    Complex addComplex(Complex &,Complex&);
    Complex subComplex(Complex&,Complex&);
};

/* Definition OF The Addition Complex Number Function*/

Complex friend_class::addComplex(Complex &ob1, Complex &ob2)
{
    Complex obj_3;
    
    //Addition Of Two Number

    obj_3.real = ob1.real + ob2.real;
    obj_3.imag = ob1.imag + ob2.imag;
    
    //Returning The Object

    return obj_3;
}
Complex friend_class::subComplex(Complex &o1, Complex &o2)
{
    Complex o3;
    o3.real = o1.real - o2.real;
    o3.imag = o1.imag - o2.imag;

    return o3;
}



int main()
{
    friend_class ob_fend;
    Complex sumCom,subCom;
    Complex ob_1(2,8);
    Complex ob_2(7,9);
    int cho;
    while (cho != 3)
    {
        cout<<"Choose One OF Option \n\t 1. To Diplay The Sum OF Object 1 & 2 \n\t 2. To Display The Sub OF Object 1 & 2"<<endl;
        cin>>cho;
        switch (cho)
        {
        case 1:
            sumCom = ob_fend.addComplex(ob_1,ob_2);
            sumCom.print();
            break;
        case 2:
            subCom = ob_fend.subComplex(ob_1,ob_2);
            subCom.print();
            break;
        }
    }
}
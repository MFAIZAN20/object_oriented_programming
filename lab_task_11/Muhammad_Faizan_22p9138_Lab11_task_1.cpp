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

    void print()
    {
        cout<<"The Sum OF Real & Imag is :"<<real<<" + "<<imag<<"i"<<endl;
    }

    friend Complex add(Complex, Complex);
};

/* Definition OF The Addition Complex Number Function*/

Complex add(Complex obj_1, Complex obj_2)
{
    Complex obj_3;
    
    //Addition Of Two Number

    obj_3.real = obj_1.real + obj_2.real;
    obj_3.imag = obj_1.imag + obj_2.imag;
    
    //Returning The Object

    return obj_3;
}
int main()
{
    Complex sum;
    Complex ob_1(2,8);
    Complex ob_2(7,9);

    ob_1.print();
    ob_2.print();

    sum = add(ob_1,ob_2);
    sum.print();

}
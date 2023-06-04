#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Complex;
/* Operation Class */
class operations
{
    public:
    Complex addComplex(Complex&,Complex&);
    Complex subComplex(Complex&,Complex&);
};
/* Complex Class */
class Complex
{
    int real;
    int imag;
    public:

    /* Friend Functions */
    // friend class operations;
    friend Complex addComplex(Complex&,Complex&);
    friend Complex subComplex(Complex&,Complex&);

    //Comstructor For The Complex Class 

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
};
    /* Definition OF The Addition Complex Number Function*/


Complex addComplex(Complex &obj_1, Complex &obj_2)
{
    Complex obj_3;
    //Addition Of Two Number

    obj_3.real = obj_1.real + obj_2.real;
    obj_3.imag = obj_1.imag + obj_2.imag;
    
    //Returning The Object

    return obj_3;
}

Complex subComplex(Complex &sc1, Complex &sc2)
{
    Complex sc3;
    sc3.real = sc1.real - sc2.real;
    sc3.imag = sc1.imag - sc2.imag;

    return sc3;

}

int main()
{
    // operations op;
    Complex sum,sub;
    Complex ob_1(3,5);
    Complex ob_2(4,8);

    int choose;
    while(choose != 3){
        cout<<"Select One Of The Following Option \n\t 1. To Add Two Complex Numbers \n\t 2. To Subtract To Numbers \n\t 3. To Exit From The Code"<<endl;
        cin>>choose;
        switch(choose){
        case 1:
            ob_1.display();
            ob_2.display();
            cout<<"The Sum OF The Two Number Is : "<<endl;    
            sum = addComplex(ob_1,ob_2);
            sum.display();
        break;

        case 2:
            ob_1.display();
            ob_2.display();
            cout<<"The Sum OF The Two Number Is : "<<endl;    
            sub = subComplex(ob_1,ob_2);
            sub.display();
        break;
            case 3:
                cout<<"Exit Successfully From The Program"<<endl;
            break;

        }
    }
}
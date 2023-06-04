#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<typename V>
class Vector {
    V v;
    public:
    Vector(V vec)
    {
        v = vec;
        cout<<"The Constructor Is Called"<<endl;
    }
    int calculateDotproduct(Vector <V> obj_v)
    {
        return v.calculateDotproduct;
    }
};
class my2Darray{
    int x;
    int y;
    public:
    friend ostream & operator <<(ostream& os,my2Darray& my);
    friend istream& operator>>(istream &in, my2Darray &my2);

    my2Darray(int c_x = 0,int c_y = 0)
    {
        if (c_x >=0)
        {
            x = c_x;
        }
        else
        {
            x = 0;
        }

        if (c_y >=0)
        {
            y = c_y;
        }
        else
        {
            y = 0;
        }
    }
    int calculateDotProduct(my2Darray obja)
    {
        int dot = (x * obja.x) + (y * obja.y);
        return dot;
    }
    
};
ostream& operator<<(ostream &os,my2Darray &my2){
    os<<"Vector : "<<"( "<<my2.x<<" , "<<my2.y<<" )"<<endl;
    return os;
}
istream& operator>>(istream &in, my2Darray &my2)
{
    cout<<"Please Enter X : "<<endl;
    in>>my2.x;
    cout<<"please Enter Y : "<<endl;
    in>>my2.y;
    return in;
}

class my3Darray{
    int x;
    int y;
    int z;
    public:
    friend ostream & operator <<(ostream& os,my3Darray& ab3);
    friend istream& operator>>(istream &in, my3Darray &ab3);
    my3Darray(int c_x = 0,int c_y = 0,int c_z = 0)
    {
        if (c_x >= 0)
        {
            x = c_x;
        }
        else
        {
            ;
        }
        
        if (c_y >= 0)
        {
            y = c_y;
        }
        else
        {
            y = 0;
        }
        
        if (c_z >= 0)
        {
            z = c_z;
        }
        else
        {
            z = 0;
        }
    }
    int calculateDotProduct(my3Darray alpha)
    {
        int dot_pro = (x * alpha.x) + (y * alpha.y) + (z * alpha.z);
        return dot_pro;
    }
};

ostream& operator<<(ostream &os,my3Darray &ab3){
    os<<"Vector : "<<"( "<<ab3.x<<" , "<<ab3.y<<" , "<<ab3.z<<" )"<<endl;
    return os;
}
istream& operator>>(istream &in, my3Darray &ab3)
{
    cin.ignore();
    cout<<"Please Enter X : "<<endl;
    in>>ab3.x;
    cout<<"please Enter Y : "<<endl;
    in>>ab3.y;
    cout<<"Please Enter Z : "<<endl;
    in>>ab3.z;
    return in;
}

int main()
{
    my2Darray object_1(4,8);
    my2Darray object_2;
    
    operator>>(cin,object_2);
    
    operator<<(cout,object_1);
    operator<<(cout,object_2);

    int sum = object_1.calculateDotProduct(object_2);
    cout<<"The Dot Product OF 2D Vector is : "<<sum<<endl;
    my3Darray object_A(4,4,2);
    my3Darray object_B;
    
    operator>>(cin,object_B);
    operator<<(cout,object_A);
    operator<<(cout,object_A);

    int three_sum = object_A.calculateDotProduct(object_B);
    cout<<"The Dot Product OF 3D Vector is : "<<three_sum<<endl;
 
    return 0;
}
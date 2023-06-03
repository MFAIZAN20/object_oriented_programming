#include <iostream>
using namespace std;

int main(){
float weight,height,x;
float BMI;
    cout<<"Please Enter Your Weight:"<<endl;
    cin>>weight;

    cout<<"Please Enter Your Height:"<<endl;
    cin>>height;

    x=height*height;

    BMI=weight/x;
    
    cout<<"Your BMI is:"<<(float)BMI<<endl;
return 0;
}

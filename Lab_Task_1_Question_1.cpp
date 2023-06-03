#include <iostream>
using namespace std;

int main(){
int x,y,z,Sec,Min,Hour;
  /*Taking Input From The User*/
    cout<<"Please Enter The Number OF Seconds"<<endl;	
    cin>>x;
    Hour=x/3600;
    
    y=x%3600;
    Min=y/60;
    Sec=y%60;

cout<<"The Hour is: "<<Hour;
cout<<"The Min is: "<<Min;
cout<<"The Sec is: "<<Sec<<endl;


    
}

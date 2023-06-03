#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct student
{
    string std_name;
    int course[3];
};
void Display_data(student std_display){
    for (int i = 0; i < 3; i++)
    {
        cout<<"The Number Marks Of:"<<i+1<<endl;
        cout<<std_display.course[i]<<endl;
    }
}

student Change_Marks(){
    int num;
    student std_change;
    cout<<"Please Enter The Subject Number To Change The Marks"<<endl;
    cin>>num;
    cin>>std_change.course[num];
    return std_change;
}
void average_marks(student student_data)
{
    int total=0;
    int count=0;
    for (int i = 0; i < 3; i++)
    {
        total=total+student_data.course[i];
        count++;
    }
    float avg=total/count;
    cout<<"The Average Is : "<<avg<<endl;

}

int main(){
    int option;
    student std_data;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Please Enter The Name Of Student : "<<endl;
        getline(cin,std_data.std_name);
    for (int j = 0; j < 3; j++)
    {   
        cout<<"Please Enter The Marks Of The Course at : "<<j+1<<endl;
        cin>>std_data.course[j];
    }
    continue;
    }

    while (option != 4)
    {
        cout<<"\t\t\tMenu\n1. Display Student Data\n2. Calculate Average Marks\n3. Change Marks\n4. Exit From Program"<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
            Display_data(std_data);
            break;
        case 2:
        average_marks(std_data);
            break;
        case 3:
            std_data=Change_Marks();
            break;
        } 
    }
}
#include <iostream>
using namespace std;

int room_choice(int floor);

int main(){
int choice,floor_no,room_no,days,total_charges;
char rooms[4][5]={{'*','*','-','-','-'},{'-','-','-','*','*'},{'-','-','-','*','-'},{'-','-','-','*','-'}};
while (choice!=3)
{
cout<<"\tChoose Menu\n1.Show Avalible/Booked Rooms\n2.Book A Room\n3.Exit a Program"<<endl;
cin>>choice;
switch (choice)
{
case 1:
for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout<<rooms[i][j]<<"\t";   
        }
    cout<<endl;
    }
    break;

case 2:
cout<<"Please Enter Enter The Floor In Which You Want To Stay"<<endl;;
    cin>>floor_no;

    cout<<"Please Enter The Room In Which You Want To Stay"<<endl;;
    cin>>room_no;

    if (rooms [floor_no][room_no] == '-')
    {
        rooms[floor_no][room_no]='*';
        cout<<"Please Enter Duration To Stay in Hotal"<<endl;
        cin>>days;
        total_charges=days*room_choice(floor_no);
        cout<<"Your Total Charges Are: "<<total_charges<<endl;
    }
    else {
        cout<<"This Room Is Already Booked: "<<endl;
    }
    break;
default:
    break;
}
}
}
int room_choice(int floor){
    int price;
    if (floor==1 || floor==2)
    {
        price=10000;
    }
    else if (floor==3 || floor==4)
    {
        price=6000;
    }
return price;
}
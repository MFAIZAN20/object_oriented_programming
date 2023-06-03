#include <iostream>
#include <string>
/*Libraries For Rand And Time Function*/
#include <cstdlib>
#include <ctime>
using namespace std;
/*Class*/
class DiceType
{
    int value;
    public:
/* Default Constructor */
    DiceType()
    {
        value=0;
    }
/*Setting New Values*/
    void setvalue(int up_value)
    {
        value=up_value;
        setvalue(value);
    }
/*Getting values*/    
    int getvalue()
    {
        return value;
    }
/*Function For Roll Dice*/
    void roll()
    {
        char option;
        value=rand()%6+1;
           
        if (value == 6)
        {
        cout<<"wow! it is chakaaaa"<<value<<endl;            
        }
        else
        {
            cout<<"It was :" <<value<<endl;
        }
        
    }
};

int main()
{
    DiceType check;             //Object Created
    char option;

     while (option != 'N' && option != 'n')
    {   
        cout<<"Do you want to Roll The Dice Y/N ?"<<endl;
        cin>>option;

        if (option == 'Y' || option == 'y' )
        {
            check.roll();    
        }
        else if (option == 'N' || option == 'n')
        {
            cout<<"You Exit Successfully"<<endl;
        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }          
    }

/*The Pause and getch(); are used to implement line by line code and avoid error*/
    system("pause");
    
    return 0;
}

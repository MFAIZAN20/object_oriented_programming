#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void text_in_file();
void text_out_file();
    void text_in_file(){
    string intext;
    ofstream infile;
    infile.open("file.txt", ios::app);

    if (!infile.is_open())
    {
        cout<<"The File Does Not Exits"<<endl;
    }
    else
    {
        cout<<"Please Enter Some Text"<<endl;
        cin.ignore();
        getline(cin,intext);
        infile<<intext<<endl;
        cout<<"The Text Is Successfully Added To The File"<<endl;
    }
    infile.close();
    }

void text_out_file(){
    ifstream out_file;
    string out_text;
    out_file.open("file.txt",ios::in);

    if (!out_file.is_open())
    {
        cout<<"There Is Error In Opening The File"<<endl;        
    }
    else{
        cout<<"Reading From File Successfully Open"<<endl;
        
        cin.ignore();
        while (1)
        {
        if (out_file.eof())        
        break;
        else
        out_file>>out_text;
        cout<<out_text<<endl;
        }
    }
    out_file.close();
}

int main(){
    int option=0;
    cout<<"Please Choose The Option\n\t 1.Add Text To The Same File\n\t 2.To Show The Text File \n\t 3.Exit From The Program"<<endl;
    while(option != 3)
    {
        cin>>option;
        switch (option)
        {
        case 1:
        text_in_file();       
            break;
        case 2:        
        text_out_file();
            break;
        }
    }
}
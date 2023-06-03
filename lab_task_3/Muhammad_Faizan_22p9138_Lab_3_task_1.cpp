#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MovieData
{
    string Title;
    string Director;
    string Year_Released;
};
MovieData createMovieData(){
    MovieData in_m_data;
    cout<<"Please Enter Title Of The Movie : "<<endl;
    getline(cin,in_m_data.Title);

    cout<<"Please Enter Name Of The Director : "<<endl;
    getline(cin,in_m_data.Director);

    cout<<"Please Enter The Relase Date : "<<endl;
    getline(cin,in_m_data.Year_Released);

    return in_m_data;
}

void displayMovieData(MovieData m_data){
   // MovieData m_data;
    cout<<"The Title Of The Movie is: "<<m_data.Title<<endl;
    cout<<"The Title Of The Movie is: "<<m_data.Director<<endl;
    cout<<"The Title Of The Movie is: "<<m_data.Year_Released<<endl;
}

int main(){
    MovieData mov;

    mov=createMovieData();

    displayMovieData(mov);

    return 0;
}

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "header.cpp"
using namespace std;

int main()
{
    int size;
    string ne_song;

    cout << "Please Enter Size OF Song List : " << endl;
    cin >> size;
    cin.ignore(); 
    // ignore the newline character in the input buffer
        
    songType song_obj(size);
    song_obj.setlistsize(size);
    song_obj.set_initial_songlist(size);

    cout << "The Song List Successfully Created" << endl;

    int option = 0;
    while (option != 6)
    {
        string song_name;
        cout << "-----Please Choose One Of The Option-----\n\t1.Add Song.\n\t2.Delete The Song\n\t3.Update a Song.\n\t4.To Display All Song List\n\t5.Create A Backup Of The Song\n\t6.Exit." << endl;
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            cout << "------To New Song To Add New-----" << endl;
            cout << "Please Enter The Name Of The Song You Want To Add : " << endl;
            getline(cin,song_name);
            song_obj.Addsong(song_name);
            break; 
        case 2:
            int num,list_size;
            cout << "----You Selected To Delete A Song----" << endl;
            cout<<"Please Enter The Song Number You Want TO delete : ";
            cin>>num;
            song_obj.delete_song(num);
            break;
        case 3:
            cout << "You Selected The Update Song " << endl;
            song_obj.upadate_song_list();
            break;
        case 4:
            cout << "You Selected The Display All Song" << endl;
            song_obj.display_song_list();
            break;
        case 5:
            cout << "Welcome To The Create Backup Song Playlist" << endl;
            songType back_song(song_obj); 
            // initialize back_song with the original song list using the copy constructor
            break;
        }
    }

    return 0;
}
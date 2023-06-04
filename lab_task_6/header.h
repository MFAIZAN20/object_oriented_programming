#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class songType{
    int arr_size;
    string* songlist;

    public:
    /*Constractor For The Function*/
    
    songType(int);
    songType(const songType&);

    ~songType();

    /* Setter Function*/
    
    void setlistsize(int);
    void setsongname(string,int);

    void Addsong(string);


    /* Getter Functions*/
    int getlistsize() const;
    string getsongname(int);

    /* Set Initinal Values */
    void set_initial_songlist(int);
    /* Update Function */
    void upadate_song_list();

    /* Deleting A Song */
    void delete_song(int);
    
    /*Create The Backup Function*/


    /*Main Functions*/

    void display_song_list();
};
#endif

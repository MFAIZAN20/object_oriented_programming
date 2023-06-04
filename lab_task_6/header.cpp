    #include <iostream>
    #include "header.h"
    #include <iomanip>
    #include <string>
    #include <cstring>

    using namespace std;

    /* Constructor */
    songType::songType(int size)
    {
        setlistsize(size);
        songlist = new string[arr_size];
    }    

    /* Destructor */
    songType::~songType()
    {
        delete [] songlist;
        songlist = NULL;
        cout << "The Songlist Is Deleted" << endl;
        cout << "The Songlist Is NULL" << endl;
    }   

    /* Copy constructor */
    songType::songType(const songType& other)
    {
        int size = other.arr_size;
        cout << "--The Copy Constructor is Called--" << endl;
        songlist = new string[other.getlistsize()];
        arr_size = other.getlistsize();

        for (int i = 0; i < size; i++)
        {
            songlist[i] = other.songlist[i];
        }
    }

    /* Setter function */

    void songType::setlistsize(int size)
    {
        if (size > 0)
        {
            arr_size = size;
        }
        else
        {
            arr_size = 0;
        }
    }    
        
    void songType::setsongname(string song_name, int size)
    {
        if (!song_name.empty())
        {
            songlist[size] = song_name;
        }
        else
        {
            songlist[size] = "";
            cout << "Error Occurred" << endl;
        }
    }   

    void songType::Addsong(string sg)
    {
        int old_size = getlistsize();
        int temp_size = old_size + 1;

        string* temp = new string[temp_size];

        /* The New Song Will Be added at the last place in the temp list*/
        /* In this for loop all the present data will be sent to the temp songlist from the first index */
        for (int i = 0; i < old_size; i++)
        {
            temp[i] = songlist[i];
        }
        temp[temp_size - 1] = sg; // add the new song at the last index

        /* Delete the old song list completely and set the new size */
        delete[] songlist;
        setlistsize(temp_size);

        /* Initialize the new song list with empty strings */
        songlist = new string[temp_size];
        for (int i = 0; i < temp_size; i++)
        {
            songlist[i] = "";
        }

        /* Copy the data from the temp list to the songlist */
        for (int i = 0; i < temp_size; i++)
        {
            songlist[i] = temp[i];
        }

        /* Delete the temp list and null the pointer */
        delete[] temp;
        temp = nullptr;
        cout << "Your List Is Successfully Updated" << endl;
    }

    /* Getter function */

    int songType::getlistsize() const
    {
        return arr_size;
    }

    string songType::getsongname(int position)
    {
        return songlist[position];
    }

    void songType::set_initial_songlist(int si)
    {
        string song_name;
        for (int j = 0; j < si ; j++)
        {
            cout << "Please Enter The Song Name For " << j+1 << " Song" << endl;
            getline(cin, song_name);
            songlist[j] = song_name;
        }
    }

    /* Update Songlist Function */

    void songType::upadate_song_list()
    {
        int change, size = getlistsize();

        cout << "Please Enter The Song Number You Want To Change" << endl;
        cin >> change;

        cin.ignore(); // Clear the newline character left in the input buffer

        string n_n_song;
        cout << "Please Enter The New Song Name: " << endl;
        getline(cin, n_n_song);

        for (int i = 0; i < size; i++)
        {
            if (change == i)
            {
                setsongname(n_n_song, change);
            }
        }
        cout << "The Song is updated" << endl;
    }

    /* Deleting the Song From The List */
    void songType::delete_song(int s_num)
    {
        int ori_size = getlistsize();
        int temp_si = ori_size - 1;

        string* temp = new string[temp_si];
        for (int i = 0; i < ori_size; i++)
        {
            if (i >= s_num)
            {
                temp[i-1] = songlist[i];
            }
            else 
            {
                temp[i] = songlist[i];
            }
        }
            
        delete [] songlist;
        setlistsize(temp_si);


        songlist = new string[temp_si];
        for(int i = 0; i < temp_si; i++)
        {
        songlist[i] = temp[i];
        }

        delete [] temp;
        temp = NULL;
    }

    /* Display Song List */
    void songType::display_song_list()
    {
        int lisiz = getlistsize();
    for (int i = 0; i < lisiz; i++)
        {
            cout << "The " << i+1 << " Song Name is: " << getsongname(i) << endl;
        }
    }
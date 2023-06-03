#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
int no_vowels(string Str);
int no_vowel_cont(string words);
char most_freq(string str_1);


int main(){

char option,ch_freq; 
string sentecce,sec_string;
int count=0;
cout<<"Enter Some Sentences To Find Vowels In That: "<<endl;
getline(cin,sentecce);

while (option !='E')
{
cout<<"\t\t\tPress \n A For Count the number of vowels in the string\n B Count both the vowels and consonants in the string\n C Display the most frequent character in the string.\n D Concatenate another string with the existing string."<<endl;
cin>>option;

switch (option)
    {
    case 'A':
        no_vowels(sentecce);
        break;
    case 'B':
        no_vowel_cont(sentecce);
        break;
    case 'C':
        ch_freq=most_freq(sentecce);
        cout<<"The Most Frequent Character Is: "<<ch_freq<<endl;
        break;


    case 'D':
    cout<<"Please Enter The Second String Here"<<endl; 
    getline(cin,sec_string);

    sentecce.append(sec_string);
    cout<<"The Conentae SEntence Is: "<<sentecce<<endl;
        break;
    }
}
}

int no_vowels(string Str)
{
    int count=0;
    int x=Str.length();

    for (int i = 1; i <= x; i++)
    {
        switch (Str[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        count++;
        default:
            break;
        }
    }
    cout<<"The Number Of Vowels Are: "<<count;
    return count;
}
int no_vowel_cont(string words)
{

    int count=0;
    int consonat=0;

    int x=words.length();

    for (int i = 1; i <= x; i++)
    {
        switch (words[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        count++;
        default:
            consonat++;
        }
    }
    cout<<"The Number Of Vowel Are :"<<count<<endl;
    cout<<"The Number Of Of Consonant Are :"<<consonat<<endl;
return 0;
}
//Declearing The Function For Frequency
char most_freq(string str_1){    
    cout<<"Please Enter The First String";

    int z=str_1.length();
    int str_2[z]={0};

    for (int i = 0; i < z; i++)
    {
        for (int j =1; j < z; j++)
        {
            if (str_1[i] == str_1[j])
            {
                str_2[i]++;
            }
        }        
    }
    int max=0;
    char result;
    for (int i = 0; i < z; i++)
    {
    if(max<str_2[i])
        {
            max=str_2[i];
           result=str_1[i];
        }
    }
    return result;
}


#include<iostream>
using namespace std;

class Movie
{
public:
    string title;
    string genre;
    int releseyear;

    void display()
    {
        cout << "Title is:" << title << endl;
        cout << "genre is:" << genre << endl;
        cout << "relsedyear:" << releseyear << endl;
        cout << "---------------------" << endl;
    }
};

int main()
{
    Movie m1[3];
    m1[0].title = "tere ishq mein";
    m1[0].genre = "romantic";
    m1[0].releseyear = 2025;

    m1[1].title = "K.G.F";
    m1[1].genre = "Action";
    m1[1].releseyear = 2022;

    m1[2].title = "hungama";
    m1[2].genre = "comedy";
    m1[2].releseyear = 2012;

    for (int i = 0; i < 3; i++)
    {
        m1[i].display();
    }

    return 0;
}
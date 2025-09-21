#include <iostream>
using namespace std;

class Movie
{
protected:
    string title;

public:
    Movie(string t) : title(t) {}
    virtual void display()
    {
        cout << "Movie: " << title << endl;
    }
    string getTitle() { return title; }
};

int main()
{
    cout << "Netflix Terminal Assistant Initialized." << endl;
    return 0;
}
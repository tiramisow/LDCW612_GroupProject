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

class Genre : public Movie
{
private:
    string genre;

public:
    Genre(string t, string g) : Movie(t), genre(g) {}
    void display() override
    {
        cout << "Movie: " << title << " | Genre: " << genre << endl;
    }
    string getGenre() { return genre; }
};

int main()
{
    Genre m("Titanic", "Romance");
    m.display();
    return 0;
}
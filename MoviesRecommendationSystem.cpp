#include <iostream>
#include <vector>
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

    // added some movies with genres (initial movies data)
    vector<Genre> movies;
    movies.push_back(Genre("Avengers: Endgame", "Action"));
    movies.push_back(Genre("The Dark Knight", "Action"));
    movies.push_back(Genre("Titanic", "Romance"));
    movies.push_back(Genre("La La Land", "Romance"));
    movies.push_back(Genre("Interstellar", "Sci-Fi"));
    movies.push_back(Genre("Inception", "Sci-Fi"));
    movies.push_back(Genre("Kung Fu Panda", "Comedy"));
    movies.push_back(Genre("Zootopia", "Comedy"));

    for (auto &m : movies)
    {
        m.display();
    }

    return 0;
}

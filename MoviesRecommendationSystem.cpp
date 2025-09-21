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

    int genreChoice;
    cout << "Select a genre:\n";
    cout << "1. Action\n2. Romance\n3. Sci-Fi\n4. Comedy\n";
    cout << "Enter option (1-4): ";
    cin >> genreChoice;

    string selectedGenre;
    switch (genreChoice)
    {
    case 1:
        selectedGenre = "Action";
        break;
    case 2:
        selectedGenre = "Romance";
        break;
    case 3:
        selectedGenre = "Sci-Fi";
        break;
    case 4:
        selectedGenre = "Comedy";
        break;
    default:
        cout << "Invalid genre choice." << endl;
        return 0;
    }

    cout << "\nRecommended " << selectedGenre << " movies:\n";
    for (auto &m : movies)
    {
        if (m.getGenre() == selectedGenre)
        {
            m.display();
        }
    }

    return 0;
}

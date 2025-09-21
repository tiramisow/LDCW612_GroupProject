#include <iostream>
#include <vector>
#include <algorithm>
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

string toLower(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

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

    int choice;

    while (true)
    {
        cout << "=== Welcome to Netflix OOP Terminal Assistant ===" << endl;
        cout << "Please choose an option:" << endl;
        cout << "1. Get recommendations by genre" << endl;
        cout << "2. Search a movie and find its genre" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter option (1 or 2): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
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
                continue;
            }

            cout << "\nRecommended " << selectedGenre << " movies:\n";
            for (auto &m : movies)
            {
                if (m.getGenre() == selectedGenre)
                {
                    m.display();
                }
            }
        }
        else if (choice == 2)
        {
            string searchTitle;
            cout << "\nEnter the movie title: ";
            getline(cin, searchTitle);

            bool found = false;
            for (auto &m : movies)
            {
                if (toLower(m.getTitle()) == toLower(searchTitle))
                {
                    cout << "Movie found! " << endl;
                    m.display();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Sorry, movie not found in database." << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting Program. Goodbye!" << endl;
            break; // exit loop
        }
        else
        {
            cout << "Invalid option. Only option 1 to 3" << endl;
        }
    }
    return 0;
}

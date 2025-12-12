// ~~~ QUE 1: Class, Objects, and Array Demonstration (Movie) ~~~ // 


#include <iostream>

using namespace std;

const double PI = 3.14;
const int Max_Movie = 5;
const int Name_Length = 50;

class Movie {
public:

    char title[Name_Length];
    char genre[Name_Length];
    int releasedYear;

    Movie(const char* t, const char* g, int y) {
    
        int i = 0;

        while (t[i] != '\0' && i < Name_Length - 1) { title[i] = t[i]; i++; }
        title[i] = '\0';
          
        i = 0;
    
        while (g[i] != '\0' && i < Name_Length - 1) { genre[i] = g[i]; i++; }
        genre[i] = '\0';

        releasedYear = y;
    }


    Movie() : releasedYear(0) {
        title[0] = '\0';
        genre[0] = '\0';
    }

    void displayInfo() const {
        cout << "   Title: " << title << " | Genre: " << genre << " | Year: " << releasedYear << endl;
    }
};

void que1_demo() {
    cout << "--- 🎬 Task 1: Movie Class & C-Style Array ---" << endl;

    Movie m1("Dhurandar", "Thriller/Drama", 2025);
    Movie m2("Geeta Govinda", "Love", 2021);
    

    Movie movieCollection[Max_Movie] = {m1, m2};
    int count = 2; 

    cout << "Accessing attributes via C-style array:" << endl;
    for (int i = 0; i < count; ++i) {
        
        cout << "   - " << movieCollection[i].title << " (" << movieCollection[i].releasedYear << ")" << endl;
    }
    cout << endl;
}

int main() {
    
    que1_demo(); 
    return 0;

}
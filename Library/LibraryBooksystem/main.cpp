#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability;
    string dateAdd;

public:
    void setBookDetails(string t, string a, string i, string d) {
        title = t;
        author = a;
        ISBN = i;
        dateAdd = d;
        availability = true;
    }

    void displayBookDetails() {
        cout << title << " - " << ISBN << endl;
    }

    string getISBN() {
        return ISBN;
    }
};

int main() {
    Book books[5];
    cout << "Library system initialized." << endl;
    return 0;
}
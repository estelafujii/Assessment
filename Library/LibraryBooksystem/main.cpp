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
    // Set book details
    void setBookDetails(string t, string a, string i, string d) {
        title = t;
        author = a;
        ISBN = i;
        dateAdd = d;
        availability = true;
    }

    // Display book details
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Available: " << (availability ? "Yes" : "No") << endl;
        cout << "---------------------------" << endl;
    }

    // Borrow book
    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book is not available.\n";
        }
    }

    // Return book
    void returnBook() {
        availability = true;
        cout << "Book returned successfully.\n";
    }

    // Getter for ISBN
    string getISBN() {
        return ISBN;
    }
};

// Sorting function (outside the class)
void sortBookData(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getISBN() > books[j + 1].getISBN()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int main() {
    Book books[5];

    // Initialize books
    books[0].setBookDetails("C++ Basics", "John Smith", "333", "01-01-2024");
    books[1].setBookDetails("OOP Concepts", "Jane Brown", "111", "02-01-2024");
    books[2].setBookDetails("Algorithms", "Tom White", "555", "03-01-2024");
    books[3].setBookDetails("Data Structures", "Lisa Green", "222", "04-01-2024");
    books[4].setBookDetails("Programming Logic", "Mark Black", "444", "05-01-2024");

    // Sort books by ISBN
    sortBookData(books, 5);

    cout << "Books sorted by ISBN:\n";
    for (int i = 0; i < 5; i++) {
        books[i].displayBookDetails();
    }

    string inputISBN;

    while (true) {
        cout << "Enter ISBN to borrow (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == inputISBN) {
                books[i].borrowBook();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }

    cout << "Program terminated.\n";
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability;

public:
    Book(string t, string a, string i) {
        title = t;
        author = a;
        ISBN = i;
        availability = true;
    }

    string getISBN() const {
        return ISBN;
    }

    string getTitle() const {
        return title;
    }

    bool isAvailable() const {
        return availability;
    }

    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book is already borrowed.\n";
        }
    }

    void returnBook() {
        if (!availability) {
            availability = true;
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book was not borrowed.\n";
        }
    }

    void display() const {
        cout << "Title: " << title
             << " | Author: " << author
             << " | ISBN: " << ISBN
             << " | Status: "
             << (availability ? "Available" : "Not Available")
             << endl;
    }
};

// Function to display all books
void displayBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].display();
    }
}

// Function to find book by ISBN
int findBookByISBN(Book books[], int size, string isbn) {
    for (int i = 0; i < size; i++) {
        if (books[i].getISBN() == isbn) {
            return i;
        }
    }
    return -1;
}

int main() {

    Book books[5] = {
        Book("Clean Code", "Robert Martin", "111"),
        Book("Design Patterns", "Erich Gamma", "222"),
        Book("C++ Primer", "Lippman", "333"),
        Book("Algorithms", "Sedgewick", "444"),
        Book("Data Structures", "Weiss", "555")
    };

    int choice;
    string isbn;

    do {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1) Display Books\n";
        cout << "2) Borrow Book\n";
        cout << "3) Return Book\n";
        cout << "4) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            displayBooks(books, 5);
            break;

        case 2:
            cout << "Enter ISBN to borrow: ";
            cin >> isbn;
            {
                int index = findBookByISBN(books, 5, isbn);
                if (index != -1)
                    books[index].borrowBook();
                else
                    cout << "Book not found.\n";
            }
            break;

        case 3:
            cout << "Enter ISBN to return: ";
            cin >> isbn;
            {
                int index = findBookByISBN(books, 5, isbn);
                if (index != -1)
                    books[index].returnBook();
                else
                    cout << "Book not found.\n";
            }
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 4);

    return 0;
}
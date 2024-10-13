#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

struct Book {
    string author;
    string title;
    string genre;
    string publisher;
    int year;
    int price;
    int pages;
    double rating;
};

void ShowBook(const Book& book) {
    cout << "Author: " << book.author << endl;
    cout << "Title: " << book.title << endl;
    cout << "Genre: " << book.genre << endl;
    cout << "Publisher: " << book.publisher << endl;
    cout << "Year: " << book.year << endl;
    cout << "Price: " << book.price << endl;
    cout << "Pages: " << book.pages << endl;
    cout << "Rating: " << book.rating << endl;
}

void FillBook(Book& book) {
    cout << "Enter author: ";
    getline(cin, book.author);
    cout << "Enter title: ";
    getline(cin, book.title);
    cout << "Enter genre: ";
    getline(cin, book.genre);
    cout << "Enter publisher: ";
    getline(cin, book.publisher);
    cout << "Enter year: ";
    cin >> book.year;
    cout << "Enter price: ";
    cin >> book.price;
    cout << "Enter pages: ";
    cin >> book.pages;
    cout << "Enter rating: ";
    cin >> book.rating;
    cin.ignore();
}

void saveToFile(const vector<Book>& books, const string& path) {
    ofstream file(path, ios::app);
    if (file.is_open()) {
        for (const auto& book : books) {
            file << book.author << "," << book.title << "," << book.genre << "," << book.publisher << ","
                << book.year << "," << book.price << "," << book.pages << "," << book.rating << endl;
        }
        file.close();
        cout << "Data saved to file" << endl;
    }
    else {
        cout << "Error opening file" << endl;
    }
}

void loadFromFile(vector<Book>& books, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        books.clear();
        string line;
        while (getline(file, line)) {
            Book book;
            size_t pos = 0;

            pos = line.find(",");
            book.author = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            book.title = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            book.genre = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            book.publisher = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            book.year = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            book.price = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            book.pages = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            book.rating = stod(line);

            books.push_back(book);
        }
        file.close();
        cout << "Data loaded from file" << endl;
    }
    else {
        cout << "Error opening file" << endl;
    }
}

void ShowBooks(const vector<Book>& books) {
    cout << "Books: " << endl;
    for (const auto& book : books) {
        ShowBook(book);
    }
    cout << "**************************" << endl;
}

void searchBooks(const vector<Book>& books) {
    string searchTerm;
    cout << "Enter search term (author, title, genre, publisher, year, price, pages, rating): ";
    getline(cin, searchTerm);

 

    bool found = false;

    for (const auto& book : books) {
        vector<string> fields = {
            book.author, book.title, book.genre, book.publisher,
            to_string(book.year), to_string(book.price),
            to_string(book.pages), to_string(book.rating)
        };

    }
}




int main() {
    vector<Book> books;
    string filename = "book.txt";

    loadFromFile(books, filename);
    // Uncomment to fill and save a new book
    // Book myBook;
    // FillBook(myBook);
    // books.push_back(myBook);
    // saveToFile(books, filename);
    ShowBooks(books);
    searchBooks(books);

}

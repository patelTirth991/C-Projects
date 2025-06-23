#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }
};

class Book : public LibraryItem {
private:
    string isbn;

public:
    void setISBN(string i) { isbn = i; }
    string getISBN() const { return isbn; }

    void checkOut() override {
        string date;
        cout << "Enter due date for book: ";
        cin >> date;
        setDueDate(date);
        cout << "Book checked out successfully." << endl;
    }

    void returnItem() override {
        setDueDate("");
        cout << "Book returned successfully." << endl;
    }

    void displayDetails() const override {
        cout << "Book Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};

class DVD : public LibraryItem {
private:
    int duration;

public:
    void setDuration(int d) { duration = d; }

    void checkOut() override {
        string date;
        cout << "Enter due date for DVD: ";
        cin >> date;
        setDueDate(date);
        cout << "DVD checked out successfully." << endl;
    }

    void returnItem() override {
        setDueDate("");
        cout << "DVD returned successfully." << endl;
    }

    void displayDetails() const override {
        cout << "DVD Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    void setIssueNumber(int num) { issueNumber = num; }

    void checkOut() override {
        string date;
        cout << "Enter due date for magazine: ";
        cin >> date;
        setDueDate(date);
        cout << "Magazine checked out successfully." << endl;
    }

    void returnItem() override {
        setDueDate("");
        cout << "Magazine returned successfully." << endl;
    }

    void displayDetails() const override {
        cout << "Magazine Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Due Date: " << getDueDate() << endl;
    }
};

int main() {
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
        cout << "\n=== Library Management System ===" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add DVD" << endl;
        cout << "3. Add Magazine" << endl;
        cout << "4. Display All Items" << endl;
        cout << "5. Check Out Item" << endl;
        cout << "6. Return Item" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            if (cin.fail()) throw "Invalid input. Please enter numbers only.";

            string title, author, isbn;
            int duration, issue, index;

            switch (choice) {
            case 1:
                if (itemCount >= MAX_ITEMS) {
                    cout << "Library is full!" << endl;
                    break;
                }
                libraryItems[itemCount] = new Book();
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                if (isbn.length() != 13) throw "ISBN must be 13 characters.";

                libraryItems[itemCount]->setTitle(title);
                libraryItems[itemCount]->setAuthor(author);
                ((Book*)libraryItems[itemCount])->setISBN(isbn);
                itemCount++;
                cout << "Book added.\n";
                break;

            case 2:
                if (itemCount >= MAX_ITEMS) {
                    cout << "Library is full!" << endl;
                    break;
                }
                libraryItems[itemCount] = new DVD();
                cout << "Enter DVD title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter director/author: ";
                getline(cin, author);
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                if (duration <= 0) throw "Duration must be positive.";

                libraryItems[itemCount]->setTitle(title);
                libraryItems[itemCount]->setAuthor(author);
                ((DVD*)libraryItems[itemCount])->setDuration(duration);
                itemCount++;
                cout << "DVD added.\n";
                break;

            case 3:
                if (itemCount >= MAX_ITEMS) {
                    cout << "Library is full!" << endl;
                    break;
                }
                libraryItems[itemCount] = new Magazine();
                cout << "Enter magazine title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author/editor: ";
                getline(cin, author);
                cout << "Enter issue number: ";
                cin >> issue;
                if (issue <= 0) throw "Issue number must be positive.";

                libraryItems[itemCount]->setTitle(title);
                libraryItems[itemCount]->setAuthor(author);
                ((Magazine*)libraryItems[itemCount])->setIssueNumber(issue);
                itemCount++;
                cout << "Magazine added.\n";
                break;

            case 4:
                for (int i = 0; i < itemCount; i++) {
                    cout << "\nItem " << (i + 1) << ":" << endl;
                    libraryItems[i]->displayDetails();
                }
                break;

            case 5:
                cout << "Enter item number to check out (1-" << itemCount << "): ";
                cin >> index;
                if (index < 1 || index > itemCount) throw "Invalid item number.";
                libraryItems[index - 1]->checkOut();
                break;

            case 6:
                cout << "Enter item number to return (1-" << itemCount << "): ";
                cin >> index;
                if (index < 1 || index > itemCount) throw "Invalid item number.";
                libraryItems[index - 1]->returnItem();
                break;

            case 0:
                cout << "Exiting system." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
            }
        }
        catch (const char* err) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: " << err << endl;
        }

    } while (choice != 0);

    for (int i = 0; i < itemCount; i++) {
        delete libraryItems[i];
    }

    return 0;
}
#include <iostream>
using namespace std;

class LibraryItem {
private:
    string title, author, dueDate;

public:
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
public:
    void checkOut() override { setDueDate("15 Days"); }
    void returnItem() override { setDueDate("Returned"); }
    void displayDetails() const override {
        cout << "Book | Title: " << getTitle()
             << " | Author: " << getAuthor()
             << " | Status: " << getDueDate() << endl;
    }
};

class DVD : public LibraryItem {
public:
    void checkOut() override { setDueDate("7 Days"); }
    void returnItem() override { setDueDate("Returned"); }
    void displayDetails() const override {
        cout << "DVD  | Title: " << getTitle()
             << " | Author: " << getAuthor()
             << " | Status: " << getDueDate() << endl;
    }
};

class Magazine : public LibraryItem {
public:
    void checkOut() override { setDueDate("30 Days"); }
    void returnItem() override { setDueDate("Returned"); }
    void displayDetails() const override {
        cout << "Magazine | Title: " << getTitle()
             << " | Author: " << getAuthor()
             << " | Status: " << getDueDate() << endl;
    }
};

int main() {
    const int MAX = 10;
    LibraryItem* items[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n------ Library Menu ------\n";
        cout << "1. Add Book\n2. Add DVD\n3. Add Magazine\n";
        cout << "4. Check Out Item\n5. Return Item\n6. Display All Items\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if ((choice == 1 || choice == 2 || choice == 3) && count < MAX) {
                LibraryItem* item = nullptr;
                if (choice == 1) item = new Book;
                if (choice == 2) item = new DVD;
                if (choice == 3) item = new Magazine;

                string t, a;
                cout << "Enter Title: "; cin >> t;
                cout << "Enter Author: "; cin >> a;
                item->setTitle(t);
                item->setAuthor(a);
                item->setDueDate("Available");
                items[count++] = item;
            }
            else if (choice == 4) {
                int i; cout << "Enter item index: "; cin >> i;
                items[i]->checkOut();
            }
            else if (choice == 5) {
                int i; cout << "Enter item index: "; cin >> i;
                items[i]->returnItem();
            }
            else if (choice == 6) {
                for (int i = 0; i < count; i++)
                    items[i]->displayDetails();
            }
        }
        catch (...) {
            cout << "\nError: Invalid Input!\n";
        }

    } while (choice != 7);

    for (int i = 0; i < count; i++)
        delete items[i];

    return 0;
}
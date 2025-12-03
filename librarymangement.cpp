#include <iostream>
using namespace std;

class Book {
public:
    int id;
    string name, author;

    void add() {
        cout << "\nBook ID: ";
        cin >> id;
        cout << "Book Name: ";
        cin >> name;
        cout << "Author Name: ";
        cin >> author;
        cout << "Added successfully!\n";
    }

    void show() {
        cout << "\n[" << id << "] " << name << " by " << author << '\n';
    }
};

void search(Book books[], int n) {
    int x;
    cout << "\nSearch ID: ";
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (books[i].id == x) {
            cout << "Book Found!";
            books[i].show();
            return;
        }
    }
    cout << "Not found!\n";
}

int main() {
    Book books[50];
    int n = 0, op;

    do {
        cout << "\n1:Add \n 2:View \n 3:Search \n 4:Exit\nChoice: ";
        cin >> op;

        switch (op) {
        case 1: 
        books[n++].add();
         break;
        case 2:
            if (n == 0) cout << "No Books!\n";
            else for (int i = 0; i < n; i++) books[i].show();
            break;
        case 3: 
        search(books, n); 
        break;
        case 4: 
        cout << "Exit!\n"; 
        break;
        default: cout << "Wrong input!\n";
        }
    } while (op != 4);

    return 0;
}

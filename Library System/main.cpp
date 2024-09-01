#include <iostream>
#include <cstdlib>
using namespace std;


/*
    function to do

    1- Display
    2- add
    3- Boroow
    4- Return
    5- Update
    6- Delete
    7- Exit

*/


// titles author id status
const int sizeOfLibrary = 10;

string Titles[sizeOfLibrary] = { "C++", "Java","Python" };
string Author[sizeOfLibrary] = { "Ahmed", "Ehab","Mohy" };
int Ids[sizeOfLibrary] = { 1,2,3 };
bool Status[sizeOfLibrary] = { true,false,true };

int numOfBooks = 3;



void mainMenu() {
    cout << "1- Display All Books" << endl;
    cout << "2- Add New Book" << endl;
    cout << "3- Borrow Book" << endl;
    cout << "4- Return Book" << endl;
    cout << "5- Update Book" << endl;
    cout << "6- Delete Book" << endl;
    cout << "7- Exit" << endl;
    cout << "\nEnter Your Choice: ";
}

void cinfirmMenu() {
    cout << "\nDo you want to confirm\n";
    cout << "1- yes/n" << endl;
    cout << "2- No/n" << endl;
    cout << "\nYour Choice : ";
}

void updateMenu() {
    cout << "\nWhat do you want to update\n";
    cout << "1- Book Title" << endl;
    cout << "2- Book Author" << endl;
    cout << "\nEnter choice: ";
}


// 1- Display
void displayOneBook(string t, string a, int i, bool s) {
    string bookstatus = (s) ? "Avalilable" : "Not Avalible";
    cout << "Book Info\n\n";
    cout << "Title : " << t << endl;
    cout << "Author : " << a << endl;
    cout << "Id : " << i << endl;
    cout << "Status : " << bookstatus << endl;
    cout << "\n=========================================\n";
}

void displayAllBooks() {
    for (int i = 0; i < numOfBooks; i++) {
        displayOneBook(Titles[i], Author[i], Ids[i], Status[i]);
    }
}


// 2- Add
void addNewBook() {
    if (numOfBooks == sizeOfLibrary) {
        cout << "\nYou Can`t Add New Book\n";
    }
    else {
        string title, author;
        cout << "\nEnter Book Name\n";
        cin >> title;
        Titles[numOfBooks] = title;
        cout << "\nEnter Book Author\n";
        cin >> author;
        Author[numOfBooks] = author;
        Status[numOfBooks] = true;
        Ids[numOfBooks] = numOfBooks + 1;
        numOfBooks++;
        cout << "\nBook Added Successfully\n";
    }
}


// search
int search(int id) {
    for (int i = 0; i < numOfBooks; i++) {
        if (id == Ids[i]) {
            return i;
        }
    }
    return -1;
}


// 3- Borrow
void borrowBook() {
    int id, index, choice;
    cout << "\nEnter id of the book you want to borrow\n";
    cin >> id;
    index = search(id);
    if (index == -1) {
        cout << "\n this book not found\n";
    }
    else {
        if (Status[index]) {
            displayOneBook(Titles[index], Author[index], Ids[index], Status[index]);
            cinfirmMenu();
            cin >> choice;
            if (choice == 1) {
                cout << "\nBook is borrowed successfully\n";
                Status[index] = false;
            }
        }
        else {
            cout << "\nThis book is Already borrowed\n";
        }
    }
}


// 4- Return
void returnBook() {
    int id, index, choice;
    cout << "\nEnter id of the book you want to return\n";
    cin >> id;
    index = search(id);
    if (index == -1) {
        cout << "\n this book not found\n";
    }
    else {
        if (Status[index] == false) {
            displayOneBook(Titles[index], Author[index], Ids[index], Status[index]);
            cinfirmMenu();
            cin >> choice;
            if (choice == 1) {
                cout << "\nBook is returned successfully\n";
                Status[index] = true;
            }
        }
        else {
            cout << "\nThis book is Already returned\n";
        }
    }
}



// 5- Uodate
void updateBook() {
    int id, index, choice1, choice2;
    string str;
    cout << "\nEnter id of the book you want to update\n";
    cin >> id;
    index = search(id);
    if (index == -1) {
        cout << "\n this book not found\n";
    }
    else {
        
            displayOneBook(Titles[index], Author[index], Ids[index], Status[index]);
            cinfirmMenu();
            cin >> choice1;
            if (choice1 == 1) {
                updateMenu();
                cin >> choice2;
                if (choice2 == 1) {
                    cout << "\nEnter New Title for book\n";
                    cin >> str;
                    Titles[index] = str;
                }
                else if (choice2 == 2) {
                    cout << "\nEnter New Author for book\n";
                    cin >> str;
                    Author[index] = str;
                }
                cout << "\nBook Updated Successfully\n";
            }
    }
}


// 6- Delete
void deleteBook() {
    int id, index, choice;
    cout << "\nEnter id of the book you want to delete\n";
    cin >> id;
    index = search(id);
    if (index == -1) {
        cout << "\n this book not found\n";
    }
    else {
        
            displayOneBook(Titles[index], Author[index], Ids[index], Status[index]);
            cinfirmMenu();
            cin >> choice;
            if (choice == 1) {
                if (numOfBooks == id) {
                    numOfBooks--;
                }
                else {
                    for (int i = index; i < numOfBooks; i++) {
                        Titles[i] = Titles[i + 1];
                        Author[i] = Author[i + 1];
                        Ids[i] = Ids[i + 1];
                        Status[i] = Status[i + 1];
                    }
                    numOfBooks--;
                }
                cout << "\nBook deleted successfully\n";
            }
    }
}


int main()
{
    int choice;
    bool flag = true;
    while (flag) {
        mainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            displayAllBooks();
            break;
        case 2:
            addNewBook();
            break;
        case 3:
            borrowBook();
            break;
        case 4:
            returnBook();
            break;
        case 5:
            updateBook();
            break;
        case 6:
            deleteBook();
            break;
        case 7:
            flag = false;
            break;
        default:
            cout << "\nNot valid" << endl;
        }
        system("pause");
        system("cls");
    }
   
}

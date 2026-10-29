#include <iostream>
#include "LibraryLinkedList.h"

BookNode* CreateBook(int id, std::string title) {
    BookNode* book = new BookNode;
    book->bookID = id;
    book->title = title;
    book->next = nullptr;
    return book;
}

int main() {
    LinkedList library;

    // Add initial books
    library.InsertAt(CreateBook(103, "Operating Systems"), 0);
    library.InsertAt(CreateBook(101, "Data Structures"), 1);
    library.InsertAt(CreateBook(105, "Database Systems"), 2);
    library.InsertAt(CreateBook(102, "Computer Networks"), 3);
    library.InsertAt(CreateBook(104, "Software Engineering"), 4);

    std::cout << "INITIAL BOOK COLLECTION";
    library.Print();

    // Remove index 1
    BookNode* removed = library.RemoveAt(1);
    if (removed != nullptr) {
        std::cout << "\nRemoved book: " << removed->title << "\n";
        delete removed;
    }
    std::cout << "\nAFTER REMOVING INDEX 1";
    library.Print();

    // Swap 0 and 2
    library.Swap(0, 2);
    std::cout << "\nAFTER SWAPPING INDEX 0 AND INDEX 2";
    library.Print();

    // Sort
    library.Sort();
    std::cout << "\nAFTER SORTING BY BOOK ID";
    library.Print();

    // Reverse
    library.Reverse();
    std::cout << "\nAFTER REVERSING THE LIST";
    library.Print();

    // Insert at head
    library.Insert(CreateBook(100, "Programming Fundamentals"));
    std::cout << "\nAFTER INSERTING AT THE HEAD";
    library.Print();

    // Remove from head
    removed = library.Remove();
    if (removed != nullptr) {
        std::cout << "\nRemoved from head: " << removed->title << "\n";
        delete removed;
    }
    std::cout << "\nFINAL BOOK COLLECTION";
    library.Print();

    return 0;
}
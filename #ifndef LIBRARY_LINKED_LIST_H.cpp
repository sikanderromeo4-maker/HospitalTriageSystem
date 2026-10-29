#ifndef LIBRARY_LINKED_LIST_H
#define LIBRARY_LINKED_LIST_H

#include "BookNode.h"
#include <iostream>

class LinkedList {
private:
    BookNode* head;
    int count;

    BookNode* GetNodeAt(int index) {
        BookNode* current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }
        return current;
    }

    void CopyBookData(BookNode* a, BookNode* b) {
        std::swap(a->bookID, b->bookID);
        std::swap(a->title, b->title);
    }

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList();

    void Insert(BookNode* book);
    BookNode* Remove();
    void InsertAt(BookNode* book, int index);
    BookNode* RemoveAt(int index);
    void Swap(int index1, int index2);
    void Sort();
    void Reverse();
    void Print();
    bool IsEmpty();
    bool IsNotEmpty();
};

#endif
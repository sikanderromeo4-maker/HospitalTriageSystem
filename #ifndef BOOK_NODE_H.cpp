#ifndef BOOK_NODE_H
#define BOOK_NODE_H

#include <string>
#include <utility>

struct BookNode {
    int bookID;
    std::string title;
    BookNode* next;
};

#endif
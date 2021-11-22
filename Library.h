#pragma once
#include <vector>
#include "Book.h"
#ifndef LIBRARY_H
#define LIBRARY_H

//namespace singleton design
namespace Library {
    namespace Container {
        static std::vector<Book> vec;
    }
    static void printAllBooks();

    static void addBook();

    static void deleteBook();

    static void searchByCategory();

    static void borrowBook();

    int takeInput();

    void run();
}
#endif
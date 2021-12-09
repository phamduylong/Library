#pragma once
#include <vector>
#include <string>
#include "Book.h"
#ifndef LIBRARY_H
#define LIBRARY_H

//namespace singleton design
namespace Library {
    namespace Container {
        static std::vector<Book> db;
    }
    void printAllBooks();

    void addBook();

    void deleteBook();

    void searchByCategory();

    void borrowBook();

    void returnBook();

    void writeToCustomFile();

    void init();

    void readFromFile(std::string filename = "db.txt");

    void writeToFile(std::string filename = "db.txt");

    int takeInput();

    void run();
}
#endif
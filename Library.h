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
    static void printAllBooks();

    static void addBook();

    static void deleteBook();

    static void searchByCategory();

    static void borrowBook();

    static void returnBook();

    static void writeToCustomFile();

    void init();

    static void read_from_file(std::string filename = "db.txt");

    static void write_to_file(std::string filename = "db.txt");

    int takeInput();

    void run();
}
#endif
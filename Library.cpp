#include "Library.h"
#include "Book.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace Library::Container;

//function print all books from library 
static void Library::printAllBooks() {
    if (vec.size() == 0) {
        std::cout << "There are no existing book. Please start by adding new books!" << std::endl;
        return;
    }
    else {
        int order = 1;
        std::sort(vec.begin(), vec.end(),
            [](Book b1, Book b2) {
                return b1.getCategory() < b2.getCategory();
            }
        );
        for (auto& i : vec) {
            std::cout << order++ << ". " << i << std::endl;
        }
    }

}


//function to add new book to library
static void Library::addBook() {
    Book book;
    std::cin >> book;
    vec.push_back(book);
    std::cout << "Book added successfully!" << std::endl;
    write_to_file();
}


//function to delete book from library
static void Library::deleteBook() {
    Book book;
    std::cin >> book;
    auto it = std::find(vec.begin(), vec.end(), book);
    if (it == vec.end()) {
        std::cout << "Cannot find the book! Please try again!" << std::endl;
        return;
    }
    else {
        vec.erase(it);
    }
    write_to_file();
}


//function to search books by category
static void Library::searchByCategory() {
    int order = 1;
    std::sort(vec.begin(), vec.end(),
        [](Book b1, Book b2) {
            return b1.getCategory() < b2.getCategory();
        }
    );
    std::string query;
    std::cout << "Which book category are you looking for?" << std::endl;
    std::getline(std::cin, query);
    if (query == "") {
        printAllBooks();
    }
    std::string copy_query = query;
    copy_query[0] = std::toupper(query[0]);
    for (auto& i : vec) {
        if (i.getCategory().find(query) != std::string::npos || i.getCategory() == copy_query) {
            std::cout << order++ << ". " << i << std::endl;
        }
    }
    if (order == 1) {
        std::cout << "There is no book with this category!" << std::endl;
    }
}


//function to borrow a book
static void Library::borrowBook() {
    Book book;
    std::cin >> book;
    std::vector<Book>::iterator it = std::find(vec.begin(), vec.end(), book);

    if (it == vec.end()) {
        std::cout << "Cannot find book! Please try again!" << std::endl;
        return;
    }
    else if ((*it).getAvailability() == false) {
        std::cout << "Book is being borrowed! Sorry." << std::endl;
    }
    else {
        (*it).changeAvailability();
        std::cout << "You are now borrowing " + (*it).getTitle() + " by " + (*it).getAuthor() + ". Enjoy the book :)" << std::endl;
    }

    write_to_file();
}


//function to return book after borrowing
static void Library::returnBook() {
    Book book;
    std::cin >> book;
    std::vector<Book>::iterator it = std::find(vec.begin(), vec.end(), book);

    if (it == vec.end()) {
        std::cout << "Cannot find book! Please try again!" << std::endl;
        return;
    }
    else if ((*it).getAvailability() == true) {
        std::cout << "Book is not being borrowed!" << std::endl;
    }
    else {
        (*it).changeAvailability();
        std::cout << (*it).getTitle() + "has been returned!" << std::endl;
    }

    write_to_file();
}



//init function
void Library::init() {
    vec.clear();
    Library::read_from_file();
}



//function to read from a file. Can read from custom file (will be implemented later)
static void Library::read_from_file(std::string filename) {
    std::vector<std::string> class_mem;
    std::ifstream ifile(filename);
    if (!ifile.is_open()) {
        std::cout << "An error occured while opening file for reading. Please try again!" << std::endl;
        return;
    }
    std::string tmp;
    while (std::getline(ifile, tmp, ',')) {
        class_mem.push_back(tmp);
        if (class_mem.size() == 4) {
            Book book(class_mem[0], class_mem[1], class_mem[2], std::stoi(class_mem[3]));
            vec.push_back(book);
            class_mem.clear();
        }
    }

}


//function to write to a file. Can write to custom file (will be implemented later)
static void Library::write_to_file(std::string filename) {
    std::ofstream ofile(filename);
    if (!ofile.is_open()) {
        std::cout << "An error occured while opening file for writing. Please try again!" << std::endl;
        return;
    }
    for (auto i : vec) {
        ofile << i.getTitle() + "," + i.getAuthor() + "," + i.getCategory() + "," + std::to_string(i.getAvailability()) + ",";
    }

}


//function to take user's input
int Library::takeInput() {
    int input(0);
    std::cout << "MENU:\n1: Print all books\n2: Add a new book to library\n";
    std::cout << "3: Delete a book\n4: Search for books of a specific category\n5: Borrow a book\n";
    std::cout << "6: Exit\nNOTE : ENTERING -1 WILL CAUSE THE PROGRAM TO STOP AUTOMATICALLY" << std::endl;
    std::cin >> input;
    if (!std::cin) {
        return -1;
    }
    int temp = std::getchar();
    return input;
}


//main program
void Library::run() {
    bool userExit = false;
    while (!userExit) {
        switch (Library::takeInput()) {
        case -1:
            std::cout << "Program exited due to invalid input." << std::endl;
            userExit = true;
            break;
        case 1:
            Library::printAllBooks();
            break;
        case 2:
            Library::addBook();
            break;
        case 3:
            Library::deleteBook();
            break;
        case 4:
            Library::searchByCategory();
            break;
        case 5:
            Library::borrowBook();
            break;
        case 6:
            Library::write_to_file();
            userExit = true;
            break;
        default:
            std::cout << "Invalid input. Please input a number shown on the menu" << std::endl;
            break;
        }
    }
}


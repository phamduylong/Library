#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Library.h"

////namespace singleton design
//namespace Library {
//    namespace {
//        static std::vector<Book> vec;
//    }
//    static void printAllBooks() {
//        int order = 1;
//        std::sort(vec.begin(), vec.end(),
//            [](Book b1, Book b2) {
//                return b1.getCategory() < b2.getCategory();
//            }
//        );
//        for (auto& i : vec) {
//            std::cout << order++ << ". " << i << std::endl;
//        }
//    }
//
//    static void addBook() {
//        Book book;
//        std::cin >> book;
//        vec.push_back(book);
//    }
//
//    static void searchByCategory() {
//        int order = 1;
//        std::sort(vec.begin(), vec.end(),
//            [](Book b1, Book b2) {
//                return b1.getCategory() < b2.getCategory();
//            }
//        );
//        std::string query;
//        std::cout << "Which book category are you looking for?" << std::endl;
//        std::getline(std::cin, query);
//        if (query == "") {
//            printAllBooks();
//        }
//        std::string copy_query = query;
//        copy_query[0] = std::toupper(query[0]);
//        for (auto& i : vec) {
//            if (i.getCategory().find(query) != std::string::npos || i.getCategory() == copy_query) {
//                std::cout << order++ << ". " << i << std::endl;
//            }
//        }
//        if (order == 1) {
//            std::cout << "There is no book with this category!" << std::endl;
//        }
//    }
//
//    int takeInput() {
//        int input(0);
//        std::cout << "MENU:\n1: Print all books\n2: Add a new book to library\n";
//        std::cout << "3: Delete a book\n4 : Search for books of a specific category\n";
//        std::cout << "5 : Exit\nNOTE : ENTERING - 1 WILL CAUSE THE PROGRAM TO STOP AUTOMATICALLY" << std::endl;
//        std::cin >> input;
//        if (!std::cin) {
//            return -1;
//        }
//        int temp = std::getchar();
//        return input;
//    }
//
//    void run() {
//        bool userExit = false;
//        while (!userExit) {
//            switch (Library::takeInput()) {
//            case -1:
//                std::cout << "Program exited due to invalid input." << std::endl;
//                userExit = true;
//                break;
//            case 1:
//                Library::printAllBooks();
//                break;
//            case 2:
//                Library::addBook();
//                break;
//            case 3:
//
//                break;
//            case 4:
//                Library::searchByCategory();
//                break;
//            case 5:
//                userExit = true;
//                break;
//            default:
//                std::cout << "Invalid input. Please input a number shown on the menu" << std::endl;
//                break;
//            }
//        }
//    }
//}


int main() {
    Library::run();
	return 0;
}


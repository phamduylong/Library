#include "Book.h"
#include <iostream>
#include <string>

int Book::tmp_id = 0;

Book::Book (std::string title_, std::string author_, std::string category_) : title(title_), id(++tmp_id), author(author_), category(category_), available(true) {}


void Book::changeAvailability() {
	available = !available;
}

int Book::getId() {
	return id;
}

std::string Book::getTitle() {
	return title;
}

std::string Book::getCategory() {
	return category;
}

bool Book::getAvailability() {
	return available;
}

std::ostream& operator << (std::ostream& os, const Book& book) {
	os << book.title + " - " + book.author + "\nCategory: " + book.category << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Book& book) {
	std::cout << "Name of the book: " << std::endl;
	std::getline(is, book.title);
	std::cout << "Name of the author: " << std::endl;
	std::getline(is, book.author);
	std::cout << "Book's category: " << std::endl;
	std::getline(is, book.category);
	return is;
}

bool operator == (const Book& b1, const Book& b2) {
	if (b1.title == b2.title and b1.author == b2.author and b1.category == b2.category) {
		return true;
	} 
	return false;
}


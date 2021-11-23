#pragma once
#include <string>
#ifndef BOOK_H
#define BOOK_H
class Book {
	std::string title;
	std::string author;
	std::string category;
	bool available;
public:
	Book(std::string title_ = "", std::string author_ = "", std::string category_ = "", int avai = 1);
	void changeAvailability();
	bool getAvailability();
	std::string getTitle();
	std::string getAuthor();
	std::string getCategory();
	friend std::ostream& operator << (std::ostream& os, const Book& book);
	friend std::istream& operator >> (std::istream& is, Book& book);
	friend bool operator == (const Book& b1, const Book& b2);
};
#endif
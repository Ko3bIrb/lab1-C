#include "library.h"
#include <iostream>

int Book::bookCount = 0;
Library* Library::instance = nullptr;

Book::Book(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year) {
    ++bookCount;
    std::cout << "Создана книга \"" << title
        << "\" (" << author << ", " << year << ")\n";
}

Book::~Book() {
    --bookCount;
    std::cout << "Удалена книга \"" << title << "\"\n";
}

std::string Book::getTitle() const {
    return title;
}

void Book::print() const {
    std::cout << "  - \"" << title << "\", "
        << author << ", " << year << " г.\n";
}

int Book::getBookCount() {
    return bookCount;
}

Library::Library(const std::string& name)
    : name(name) {
    std::cout << "Открыта библиотека \"" << name << "\"\n";
}

Library::~Library() {
    std::cout << "Закрыта библиотека \"" << name << "\"\n";
    // книги НЕ удаляются — это агрегация
}

Library* Library::getInstance(const std::string& name) {
    if (instance == nullptr) {
        instance = new Library(name);
    }
    return instance;
}

void Library::destroyInstance() {
    delete instance;
    instance = nullptr;
}

void Library::addBook(Book* book) {
    if (book == nullptr) {
        std::cout << "Нельзя добавить nullptr в библиотеку\n";
        return;
    }
    books.push_back(book);
    std::cout << "Книга \"" << book->getTitle()
        << "\" добавлена в библиотеку \"" << name << "\"\n";
}

void Library::print() const {
    std::cout << "Библиотека \"" << name << "\" содержит:\n";
    if (books.empty()) {
        std::cout << "  (нет книг)\n";
        return;
    }
    for (const auto* book : books) {
        if (book != nullptr) {
            book->print();
        }
    }
}
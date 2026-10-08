#pragma once
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    int year;

    static int bookCount; // счётчик всех созданных книг

public:
    Book(const std::string& title, const std::string& author, int year);
    ~Book();

    std::string getTitle() const;
    void print() const;

    static int getBookCount();
};

class Library {
private:
    std::string name;
    std::vector<Book*> books; // агрегация

    static Library* instance; // единственный экземпляр

    explicit Library(const std::string& name);
    ~Library();

    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;

public:
    static Library* getInstance(const std::string& name = "Городская библиотека");

    void addBook(Book* book);
    void print() const;

    static void destroyInstance();
};
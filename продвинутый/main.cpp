#include <iostream>
#include <locale>
#include "library.h"

int main() {
    setlocale(LC_ALL, "ru");

    std::cout << "Всего книг сейчас: " << Book::getBookCount() << "\n\n";

    Book b1("Война и мир", "Л. Толстой", 1869);
    Book b2("Преступление и наказание", "Ф. Достоевский", 1866);
    Book b3("Евгений Онегин", "А. Пушкин", 1833);

    std::cout << "\nВсего книг сейчас: " << Book::getBookCount() << "\n\n";

    Library* lib1 = Library::getInstance("Городская библиотека");
    Library* lib2 = Library::getInstance();

    std::cout << "\nlib1 == lib2: " << (lib1 == lib2 ? "true" : "false") << "\n\n";

    lib1->addBook(&b1);
    lib1->addBook(&b2);
    lib1->addBook(&b3);

    lib1->print();

    std::cout << "\nКниги всё ещё существуют:\n";
    b1.print();
    b2.print();
    b3.print();

    std::cout << "\nВсего книг сейчас: " << Book::getBookCount() << "\n";

    Library::destroyInstance();

    std::cout << "\nПосле закрытия библиотеки книги всё ещё живы:\n";
    std::cout << "Всего книг сейчас: " << Book::getBookCount() << "\n";

    return 0;
}
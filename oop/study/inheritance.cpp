#include <iostream>
using namespace std;

class book
{
private:
    string isbn;
    string title;
    string author;
    float price;

public:
    void disp_book()
    {
        cout << "ISBN: " << isbn << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
    book(string isbn, string title, string author, float price)
    {
        this->isbn = isbn;
        this->title = title;
        this->author = author;
        this->price = price;
    }
};

class ebook : public book
{
private:
    float file_size;
    string file_format;

public:
    ebook(string isbn, string title, string author, float price, float file_size, string file_format) : book(isbn, title, author, price)
    {
        this->file_size = file_size;
        this->file_format = file_format;
    }
    void disp_ebook()
    {
        disp_book();
        cout << "File Size: " << file_size << endl;
        cout << "File Format: " << file_format << endl;
    }
};

int main()
{
    ebook("1234", "Harry Potter", "JK Rowling", 500, 100, "pdf").disp_ebook();
    return 0;
}

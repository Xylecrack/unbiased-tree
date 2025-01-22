#include <iostream>
#include <string>

using namespace std;

// Base class
class Book
{
  protected:
    string isbn;
    string title;
    string author;
    double cost;

  public:
    Book(string isbn, string title, string author, double cost) : isbn(isbn), title(title), author(author), cost(cost)
    {
    }

    void displayBookDetails() const
    {
        cout << "ISBN: " << isbn << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Cost: " << cost << endl;
    }
};

// Derived class EBook from Book (Single Inheritance)
class EBook : public Book
{
  private:
    double file_size;
    string file_format;

  public:
    EBook(string isbn, string title, string author, double cost, double file_size, string file_format)
        : Book(isbn, title, author, cost), file_size(file_size), file_format(file_format)
    {
    }

    void displayEBookDetails() const
    {
        displayBookDetails();
        cout << "File Size: " << file_size << " MB" << endl;
        cout << "File Format: " << file_format << endl;
    }
};

// Derived class AudioBook from Book (Hierarchical Inheritance)
class AudioBook : public Book
{
  private:
    double audio_length;

  public:
    AudioBook(string isbn, string title, string author, double cost, double audio_length)
        : Book(isbn, title, author, cost), audio_length(audio_length)
    {
    }

    void displayAudioBookDetails() const
    {
        displayBookDetails();
        cout << "Audio Length: " << audio_length << " hours" << endl;
    }
};

int main()
{
    Book book("123-456-789", "C++ Programming", "John Doe", 29.99);
    book.displayBookDetails();
    cout << endl;

    EBook ebook("987-654-321", "Advanced C++", "Jane Smith", 19.99, 5.5, "PDF");
    ebook.displayEBookDetails();
    cout << endl;

    AudioBook audiobook("456-789-123", "C++ for Beginners", "Alice Johnson", 39.99, 10.5);
    audiobook.displayAudioBookDetails();

    return 0;
}
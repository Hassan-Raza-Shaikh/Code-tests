#include<iostream>
#include<string>
using namespace std;

class Book
{
    private:
    int bookid;
    string title;
    string author;
    bool isAvailable;

    public:
    void setBookDetails(int id, string bookTitle, string bookAuthor, bool available)
    {
        bookid=id;
        title=bookTitle;
        author=bookAuthor;
        isAvailable=available;
    }
    void borrowBook()
    {
        isAvailable=0;
    }
    void returnBook()
    {
        isAvailable=1;
    }
    void displayBookInfo()
    {
        cout<<"Book ID: "<<bookid<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Availability: "<<isAvailable<<endl;
    }
};

int main()
{
    Book book;
    cout<<"Book details: "<<endl;
    book.setBookDetails(101,"The Great Gatsby","F. Scott Fitzgerald",1);
    book.displayBookInfo();
    cout<<endl;
    cout<<"Atempting to borrow book... \nYou have borrowed the book: The Great Gatsby "<<endl;
    cout<<endl;
    book.borrowBook();
    cout<<"Updated book details: "<<endl;
    book.displayBookInfo();
    cout<<endl;
    cout<<"Returning the book... \nYou have returned the book: The Great Gatsby "<<endl;
    cout<<endl;
    book.returnBook();
    cout<<"Final book details: "<<endl;
    book.displayBookInfo();

    return 0;
}
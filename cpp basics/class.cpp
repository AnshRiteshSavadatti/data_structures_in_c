#include<iostream>

using namespace std;

class book{
    public:
    string name;
    string author;
    int pages;
};

int main(){
    book book1;
    getline(cin,book1.name);
    getline(cin, book1.author);
    cin >> book1.pages;
    cout << book1.name<< endl;
    cout << book1.author<< endl;
    cout <<book1.pages<< endl;
    return 0;
}

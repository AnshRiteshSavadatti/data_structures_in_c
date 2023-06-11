#include<iostream>
#include<cmath>

using namespace std;

int main(){
    string name = "Ansh";
    int age = 20;
    string phrase = "I am the best";
    string greet = "Namaste";
    cout<<"Hello everyone "<< greet<< endl;
    cout<< "My name is "<<name<< endl;
    cout<< "my current age is "<<age<< " and I have high ambitions"<<endl;
    cout<< phrase.length()<< endl;
    // Will return the total length of the string
    cout << phrase<< endl;
    cout<< phrase[3] << endl;
    // To acess every single charecter
    cout<< phrase.find("the",0) << endl;
    // find returns the index where the string starts or where the charecter is present
    cout << phrase.substr(9 ,4) << endl;
    // this function will return a substring the first input is index and the second input is length which we want
    cout << pow(2,5)<< endl;
    cout << sqrt(25) <<endl;
    cout << round(5.1) << endl;
    // round gives integer near to decimal
    cout << ceil(5.1) << endl;
    // ceil return the next integer ie higher integer while rounding 
    cout << floor(5.8) << endl;
    // floor is opposite of ceil
    cout << fmax(10,20) << endl;
    // fmax returns the highest value number
    cout << fmin(10,20) << endl;
    // fmin returns the lowest value number
    cout << "enter your age ";
    cin >> age;
    cout << "your age is "<<age<<" old" << endl;
    string full_name;
    cout<< "Enter you name ";
    fflush(stdin);
    getline(cin,full_name);
    cout<< "hello "<< full_name<< endl;
    // Mad libs game
    string color, noun , name1;
    cout<<" roses are red"<< endl;
    cout << "violets are blue "<< endl;
    cout << "I love you" << endl;
    cout<< "Enter a color noun and a name"<<endl;
    cout<< "Enter the color"<< endl;
    getline(cin, color);
    cout<< "Enter the noun" << endl;
    getline(cin, noun);
    cout << "Enter the name"<<endl;
    getline(cin, name1);
    cout<< "roses are "<< color<< endl;
    cout<< "Violets are "<< noun<< endl;
    cout<< "I love "<< name1<< endl;
    return 0;
}
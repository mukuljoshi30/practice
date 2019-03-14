#include <iostream>
using namespace std;

class myString {
    string str;
    public:
    void getString() {
        cout << "enter the string you want to reverse"<<endl;
        cin >> str;
    }
    inline void printString(){
        cout << str << endl;
    }
    void reverse_string();
    bool is_palindrome();
};

void myString::reverse_string()
{
    int index = str.length()-1;
    for(int i=0; i<=index/2; i++) {
        char temp = str[i];
        str[i] = str[index-i];
        str[index-i] = temp;
    }
}

bool myString:: is_palindrome()
{
    int index = str.length()-1;
    for(int i=0; i<=index/2; i++) {
        if(str[i] != str[index-i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    myString newString;
    newString.getString();
    newString.reverse_string();
    newString.printString();
    cout << (newString.is_palindrome() ? "String is a palindrome" :
             "String is not a palindrome") << endl;
    return 0;
}



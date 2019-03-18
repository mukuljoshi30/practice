/*
 * It will contain the reverse an integer problem.
 * when reverse and the number are equal then number is palidrome.
 */
#include <iostream>

using namespace std;

static bool is_palindrome(int);
int main()
{
    int number;
    cout<<"enter the number:"<<endl;
    cin>>number;
    cout << (is_palindrome(number) ? "Number is Palindrome" : "Number is not Palindrome") << endl;
    return 0;
}

static bool is_palindrome(int number)
{
    int temp = number, number1 = 0;
    do {

        number1 = (number1*10)+(temp%10);
        temp = temp/10;
    }while(temp);

    return (number == number1);    
}

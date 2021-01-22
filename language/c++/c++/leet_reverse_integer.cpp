//
//  leet_reverse_integer.cpp
//  c++
//
//  Created by mukuljos on 1/7/21.
//  Copyright © 2021 mj. All rights reserved.
//

#include <iostream>

using namespace std;

int main ()
{
    int number, digits = 0;
    cout << "enter the number" << endl;
    cin >> number;
    int number1 = number;
    int temp = number;
    do {
        digits++;
        temp = temp/10;
    }while(temp);
    cout << "number of digits:"<< digits << endl;
    int revnum = 0;
    //reverse the number
    for(int i = digits-1; i>=0; i--) {
        temp = number%10;
        revnum = revnum + (temp*pow(10,i));
        cout << revnum << endl;
        number = number/10;
    }
    if ((number1 >0 && revnum <0)|| (number1<0 && revnum >0)) {
        cout << 0 << endl;
    } else {
        cout <<revnum << endl;
    }
    return 0;
}


/*easier solution*/
 int reverse(int x) {
        long num = 0;
        
        while (x) {
            int digit = x % 10;
            num = num * 10 + digit; 
            x /= 10;
        }
        
        if (num > INT_MAX || num < INT_MIN)
            return 0;
        
        return (int) num;
    }


    /*
     * String to number converiosn
     * https://leetcode.com/problems/string-to-integer-atoi/submissions/
     * */
    class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
    int sign=1;
    int i=0;
    long int ans=0;
    while(i<n)
    {
        if(s[i]==' ')i++;
        else break;
    }
    if(s[i]=='-')
    {
        sign=-1;
        i++;
    }
    else if(s[i]=='+')
    {
        sign=1;
        i++;
    }
    else if(s[i]<'0'&&s[i]>'9')return -1;
    while(i<n&&s[i]>='0'&&s[i]<='9')
    {
        if(ans>INT_MAX)break;
        ans=ans*10+(s[i]-'0');
            i++;
    }
    if(ans>INT_MAX)return sign==1?INT_MAX:INT_MIN;
    return ans*sign;
    }
};
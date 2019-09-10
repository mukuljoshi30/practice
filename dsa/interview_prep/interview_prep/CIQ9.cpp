//
//  CIQ9.cpp
//  interview_prep
//
//  Created by mukuljos on 9/10/19.
//  Copyright © 2019 mukuljos. All rights reserved.
//
/* problem Statement:
 *  Please implement a function to replace each blank
 * in a string with “%20”. For instance, it outputs
 * “We%20are%20happy.” if the input is “We are happy.”.
 */

/* Similar probelm: (which can be solved efficiently by
 * copying from right ot left)
 * Question 10 Given two sorted arrays, denoted as array1 and array2,
 * please merge them into array1 and keep the merged array sorted.
 * Suppose there is sufficient vacant memory at the end of array1
 * to accommodate elements of array2.
 */

#include <iostream>
using namespace std;
#define STRLEN 100
int main()
{
    char str[STRLEN];
    cout << "input the string" << endl;
    gets(str);
    /*
     * count the spaces
     */
    //cout << str;
    int len = 0; //length of the string
    int count = 0; //space count
    while(str[len]!='\0') {
        if(str[len] == ' ') {
            count ++;
        }
        len++;
    }
    
#if 0
    //solution with for loop, not properly cleaned.
    cout << len;
    int j = len;
    str[len+(2*count)+1] = '\0';
    for(int i = len+(2*count); i>=0; i--) {
        if(str[j] == ' ') {
            str[i] = '0';
            str[i-1] = '2';
            str[i-2] = '%';
            i = i-2;
        } else {
            str[i] = str[j];
        }
        j--;
    }
    //end of for loop solution
#endif
    
    int strlen = len;
    int strlenfinal = len+(2*count);
    str[strlenfinal+1] = '\0'; //string termination
    while (strlen>=0) {
        if(str[strlen] == ' ') {
            str[strlenfinal] = '0';
            str[strlenfinal-1] = '2';
            str[strlenfinal-2] = '%';
            strlenfinal-=3;
        } else {
            str[strlenfinal] = str[strlen];
            strlenfinal--;
        }
        strlen--;
    }
    
    cout << str << endl;
    return 0;
}

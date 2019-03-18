/*
 * Given a String, return the character that is most 
 * commonly used in the string
 * -- Examples
 * "abcccccdeba" ==> c
 * there are various methods for this.
 */

#include <iostream>

using namespace std;

char find_max_value_in_array(int* arr)
{
    int max = 0, index = 0;
    for(int i = 0; i<256; i++){
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

class myString {
    string str;
    public:
    void getString() {
        cout << "enter the string:"<<endl;
        cin >> str;
    }
    inline void printString(){
        cout << str << endl;
    }
    
    char method_1_array_of_chars();
};

/*
 * Have an array of 256 char ASCI codes
 * add a value of an array indexed to char which is present in the string one by one
 * find the maximum value in the array
 * print the ASCI value
 */
char myString::method_1_array_of_chars()
{
    int counts[256];
    memset(counts, 0, 256*sizeof(int));
    for(int i = 0; i<str.length()-1; i++) {
        counts[str[i]]++;
    }
    return find_max_value_in_array(counts);
}
        
int main()
{
    myString st;
    st.getString();
    cout << "string given by you" << endl;
    st.printString();
    cout << endl << "char with max number of accurences" << endl;
    cout << st.method_1_array_of_chars() << endl;
    return 0;
}

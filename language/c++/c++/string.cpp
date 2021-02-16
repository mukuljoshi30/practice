/*
 * print/get all cubstrings of a string
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector <string> getSubstrings (vector <char> &stringVector)
{
    if (stringVector.size() == 1) {
        string thisString(1,*(stringVector.end()-1) );
        vector <string> result;
        result.push_back(thisString);
        return result;
    }

    string thisString(1,*(stringVector.end()-1) );
    stringVector.pop_back();
    vector <string> result = getSubstrings(stringVector);

    int len = result.size()-1;
    result.push_back(thisString);

    while(1) {
        string newString = result[len] + thisString;
        result.push_back (newString);
        if(result[len].length() == 1) {
            break;
        }
        len--;
    }
    return result;
}

int main ()
{
    string myString;
    cout << "Enter the string:" << endl;
    cin >> myString;
    vector<char> stringVector(myString.begin(), myString.end());
    
    vector <string> subStrings = getSubstrings(stringVector);
    for (int i = 0; i< subStrings.size(); i++)
        cout<< subStrings[i] << endl; 
    return 0;
}
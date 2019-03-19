#include <iostream>

#define ROW 5
#define COLUMN 4
using namespace std;

class myArray {
    int arr[ROW][COLUMN];
public:
    myArray()
    {
        for (int i=0; i<ROW; i++) {
            for (int j=0; j<COLUMN; j++) {
                arr[i][j] = 0;
            }
        }
    }
    void fill_spiral_values();
    void print_array();
};

void myArray::print_array()
{
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COLUMN; j++) {
            cout << arr[i][j] << "\t";
        }
        cout<<endl;
    }
}

void myArray::fill_spiral_values()
{
    int sc = 0, sr = 0;
    int er = ROW, ec = COLUMN;
    int value = 1;
    do {
    for (int i=sc; i<ec; i++){
        arr[sr][i] = value++;
    }
    sr++;
    for (int i=sr; i<er; i++){
        arr[i][ec-1] = value++;
    }
    ec--;
    for (int i=ec-1; i>=sc; i--){
        arr[er-1][i] = value++;
    }
    er--;
    for (int i=er-1; i >= sr; i--) {
        arr[i][sc] = value++;
    }
    sc++;
    }while (sc<=ec && sr<=er);
}

int main()
{
    myArray arr;
    arr.print_array();
    arr.fill_spiral_values();
    arr.print_array();
    return 0;
}

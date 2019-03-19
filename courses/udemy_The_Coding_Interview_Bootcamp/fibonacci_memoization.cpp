#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
#if 0
auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout << duration.count() << endl;
#endif
void fibonacci_number_iterate(int n)
{
    long int number[n];
    for (int i=0; i<=n-1; i++) {
        if (i<2) {
            number[i] = 1;
        } else {
            number[i] = number[i-1]+number[i-2];
        }
    }
    cout << number[n-1] << endl;
}

long int fibonacci(int n)
{
    if (n<=2) {
        return 1;
    }
    cout << n << endl;
    return fibonacci(n-1) + fibonacci(n-2);
}
void fibonacci_number_recursion(int n)
{
    cout << fibonacci(n) << endl;
}

int main ()
{
    int n;
    
    cout << "enter the value of n: ";
    cin >> n;
    high_resolution_clock::time_point t1;
    cout << endl << "result with Iteration" << endl;
    fibonacci_number_iterate(n);
    high_resolution_clock::time_point t2;
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    cout << time_span.count() << endl;
    
    cout << "result with recursion" << endl;
    fibonacci_number_recursion(n);
    
    return 0;
}

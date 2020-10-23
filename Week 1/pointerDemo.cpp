#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long
#define ar array

using namespace std;
const ll M = 1000000007;
const int mxN = 1e3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int value1 = 200000, value2;
    int * ptr;
    ptr = &value1;
    cout << *ptr << endl;

    value2 = *ptr;
    cout << value2 << endl;
    // cout << &value1 << " " << &value2 << " " << ptr << endl;
    cout << &value1 << endl;
    cout << ptr << endl;
    ptr = &value2;
    *ptr += 2000;
    cout << value1 << " " << value2 << endl;
    
    return 0;
}

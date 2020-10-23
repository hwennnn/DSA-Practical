#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long
#define ar array

using namespace std;
const ll M = 1000000007;
const int mxN = 1e3;

void changeValue(int x, int* y){
    x += 10;
    *y += 10;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x = 30, y;
    y = x;
    cout << &x << " " << &y << endl;
    changeValue(x,&y);

    cout << x << " " << y << endl;
    
    return 0;
}

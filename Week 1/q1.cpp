#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long
#define ar array

using namespace std;

// find the length of the integer
int length(int n){
    int i = 0;
    while (n > 0){
        n /= 10;
        i += 1;
    }
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, len;
    cin >> t;
    len = length(t);

    for (int i = len-1; i >= 0; i--){
        cout << (t / int(pow(10,i))) % 10 << "   ";
    }

    cout << endl;
    return 0;
}

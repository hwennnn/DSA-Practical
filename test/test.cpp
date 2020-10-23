#include <iostream>
#include <math.h>
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
    int t, len, r;
    cin >> t;
    len = length(t);
    r = pow(10,len-1);


    for (int i = 0; i < len; i++){
        cout << (t/r) %10 << " ";
        r /=10;
    }
    cout << endl;
    return 0;
}

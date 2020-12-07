#include <iostream>

using namespace std;

// recursive function
int gcd(int a, int b){
    if (b == 0) return a;

    return gcd(b, a%b);
}

int main(){
    cout << gcd(24,54) << endl;
    cout << gcd(8,12) << endl;
    cout << gcd(24,60) << endl;
    cout << gcd(41,27) << endl;

    // iterative solution
    int a = 8, b = 12;
    
    while (b != 0){
        int temp = a;
        a = b;
        b = temp%b;
    }
    cout << a << endl;

    return 0;
}
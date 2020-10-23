#include <iostream> //Include resource
#include <string.h>
#include <cmath>

using namespace std;

int main(){
    cout << (10 << 2);
    int digits, r, numOfDigits;

    cin >> digits;

    numOfDigits = to_string(digits).size();

    r = pow(10, numOfDigits - 1);

    for(int i = 0; i < numOfDigits; i++){
        cout << (digits / r) % 10 << "   ";
        r = r / 10;
    }

    cout << endl;
    return 0;

}
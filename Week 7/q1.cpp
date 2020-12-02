#include <iostream>

using namespace std;

// g++ --std=c++17 q1.cpp -o ./output.out && ./output.out

long power(int a, int n){
    if (n == 0) return 1;
    return a * power(a, n-1);
}

int main(){
    int a = 5;
    if (a > 0)
        cout << power(a,3) << endl;

    return 0;
}
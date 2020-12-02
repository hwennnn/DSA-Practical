#include <iostream>

using namespace std;

// g++ --std=c++17 q2.cpp -o ./output.out && ./output.out

void printBackward(int array[], int n){
    if (n > 0){
        printBackward(array+1, n-1);
        cout << array[0] << " ";
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int length = sizeof(arr) / sizeof(int);

    printBackward(arr, length);
    cout << endl;

    return 0;
}
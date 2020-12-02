#include <iostream>

using namespace std;

// g++ --std=c++17 q2.cpp -o ./output.out && ./output.out

void printBackward(int array[], int n){
    if (n > 0){
        printBackward(array+1, n-1);
        cout << array[0] << " ";
    }
}

// Intuition: We can utilise the nature of the array, which its size is always fixed.
// First we start calling the function recursively from the n, which is the size of the array.
// while going forward to the array, we push the current element one index forward from the original index.
// How? Since the array size is always fixed, we can simply add a dummy element behind, which is array + 1
// Example: 1 2 3 4 5 6 will become 2 3 4 5 6 -1263665114 when we do array + 1.
// So this operation will be called until it reached the first index (which is n == 0)
// Then the printing function of array[0] will be called recursively starting from 
// 6 -1263665114 770897334 -367065504 32766 540317233
// 5 6 -1263665114 770897334 -367065504 32766 ......

// Also there is other way you can do this without modifying the array (which is less fancier but work optimally)

// void printBackward(int array[], int n){
//     if (n > 0){
//         cout << array[n-1] << " ";
//         printBackward(array, n-1);
//     }
// }

int main(){
    int arr[] = {1,2,3,4,5,6};
    int length = sizeof(arr) / sizeof(int);

    printBackward(arr, length);
    cout << endl;

    return 0;
}
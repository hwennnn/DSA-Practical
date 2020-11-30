#include <iostream>

using namespace std;

// g++ --std=c++17 q3.cpp -o ./output.out && ./output.out


int maxArray(int array[], int start, int end){
    if (start == end){
        return array[start];
    }else{
        int mid = (start + end) >> 1;
        return max(maxArray(array, start, mid), maxArray(array, mid+1, end));
    }
}

int main(){
    int arr[] = {1201,120,30,110,500,1000};
    int length = sizeof(arr) / sizeof(int);

    cout << maxArray(arr, 0, length-1) << endl;

    return 0;
}
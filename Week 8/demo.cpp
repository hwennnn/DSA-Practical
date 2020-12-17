#include <iostream>

using namespace std;

static int comparisons = 0;

int search (int dataArray[], int arraySize, int target);
int binarySearch (int dataArray[], int arraySize, int target);
int search (int dataArray[],  int arraySize,  int start, int target);
int binarySearch (int dataArray[], int first, int last, int target);
void printResult(int result);


int main(){
    int dataArray[1000];
    int size = sizeof(dataArray) / sizeof(int);

    for (int data=2, i=0; i < size; i++, data += 2){
        dataArray[i] = data;
    }

    int target;
    cout << "Please enter a target number to search: ";
    cin >> target; cout << endl;

    int result = search(dataArray, size, target);
    cout << "Sequential Search : " << comparisons << endl;
    printResult(result);

    int result2 = binarySearch(dataArray, size, target);
    cout << "Binary Search     : " << comparisons << endl;
    printResult(result2);

    int result3 = search(dataArray, size, 0, target);
    printResult(result3);

    int result4 = binarySearch(dataArray, 0, size-1, target);
    printResult(result4);

    return 0;
}

int search (int dataArray[], int arraySize, int target){
    comparisons = 0;
    for (int i = 0; i < arraySize; i++){
        comparisons++;
        if (dataArray[i] == target) return i;
    }

    return -1;
}

int binarySearch (int dataArray[], int arraySize, int target){
    comparisons = 0;
    int low = 0, high = arraySize - 1;

    while (low <= high){
        comparisons++;
        int mid = (low + high) / 2;

        if (dataArray[mid] == target) return mid;
        else if (dataArray[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
            
    }

    return -1;
}

int search (int dataArray[],  int arraySize,  int start, int target){
    if (start == arraySize) return -1;
    if (dataArray[start] == target) return start;

    return search(dataArray, arraySize, start + 1, target);
}

int binarySearch (int dataArray[], int first, int last, int target){
    if (first > last) return -1;
    int mid = (first + last) / 2;

    if (dataArray[mid] == target) return mid;
    else if (dataArray[mid] < target) return binarySearch(dataArray, mid + 1, last, target);
    else return binarySearch(dataArray, first, mid - 1, target);
}

void printResult(int result){
    if (result != -1)
        cout << "Found at index " << result << endl;
    else
        cout << "Not found" << endl;
}
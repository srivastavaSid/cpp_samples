#include <iostream>

void rearrangeSortedArrInMaxMin (int *arr, int size) {
    int l(0), r(size-1);
    if (size % 2 == 0) {
        int mid = (size/2) -1;
        int temp = arr[mid];
        for (int i = mid; i < r; i++) {
            arr[i] = arr[i+1];
        }
        arr[r] = temp;
        r--;
    }
    int mid = l + (r-l)/2;
    for (int i = 1; i <= mid; i++) {
        int temp = arr[mid+i];
        for (int j = mid+i-1; j >= mid-i; j--) {
            arr [j+1] = arr[j];
        }
        arr[mid-i] = temp;
    }
}

void printArr(int *arr, int size) {
    for (int i=0; i<size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void main () {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int sz = sizeof(arr)/sizeof(arr[0]);
    rearrangeSortedArrInMaxMin(arr, sz);
    printArr(arr, sz);
}
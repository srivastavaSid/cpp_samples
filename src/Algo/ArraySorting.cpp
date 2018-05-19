#include <iostream>

template<typename T>
void selectionSort(T *arr, int sz) {
    for(int i=0; i<sz-1; i++) {
        int minIdx = i;
        for (int j=i+1; j<sz; j++) {
            if (arr[minIdx] > arr[j])
                minIdx = j;
        }
        std::swap(arr[minIdx], arr[i]);
    }
}

template<typename T>
void bubbleSort(T *arr, int sz) {
    for(int i=0; i<sz-1; i++) {
        for (int j=0; j<sz-1-i; j++) {
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
        }
    }
}

template<typename T>
void insertionSort(T *arr, int sz) {
    for (int i=1; i<sz; i++) {
        int temp = arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp; 
    }
}

template<typename T>
void printArr(T* arr, int sz) {
    for (int i=0; i<sz; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template<typename T>
void mergeUtil (T *arr, int l, int m, int r) {
    T* leftArr  = new T[m-l+1];
    T* rightArr = new T[r-m];
    for (int i=l; i<=m; i++)
        leftArr[i-l] = arr[i];
    for (int i=m+1; i<=r; i++)
        rightArr[i-m-1] = arr[i];

    int leftItr(0), rightItr(0), i(l);
    while (leftItr<(m-l+1) && rightItr<(r-m)) {
        if (leftArr[leftItr] > rightArr[rightItr])
            arr[i++] = rightArr[rightItr++];
        else
            arr[i++] = leftArr[leftItr++];
    }
    while (leftItr<(m-l+1))
        arr[i++] = leftArr[leftItr++];
    while (rightItr<(r-m))
        arr[i++] = rightArr[rightItr++];
}

template<typename T>
void mergeSortUtil(T* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left)/2;
        mergeSortUtil(arr, left, mid);
        mergeSortUtil(arr, mid+1, right);
        mergeUtil(arr, left, mid, right);
    }
}

template<typename T>
void mergeSort(T* arr, int sz) {
    if (sz == 1)
        return;
    mergeSortUtil(arr, 0, sz-1);
}

template<typename T>
void heapify(T* arr, int sz, int pos) {
    int cLeft = 2*pos + 1;
    int cRight = 2*pos + 2;
    int max = pos;
    if (cLeft < sz && arr[cLeft] > arr[max])
        max = cLeft;
    if (cRight < sz && arr[cRight] > arr[max])
        max = cRight;
    if (max != pos) {
        std::swap(arr[pos], arr[max]);
        heapify(arr, sz, max);
    }
}

template<typename T>
void heapSort(T* arr, int sz) {
    for (int i=sz/2 -1; i>=0; i--)
        heapify(arr, sz, i);

    for (int i=0; i<sz-1; i++) {
        std::swap(arr[0], arr[sz-1-i]);
        heapify(arr, sz-1-i, 0);
    }
}

void main() {
    int arr[] = {3, 2, 7, 8, 1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, sz);
    printArr(arr, sz);
}
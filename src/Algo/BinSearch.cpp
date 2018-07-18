#include <iostream>

int binSearch (int *arr, int size, int key) {
    int l(0), r(size -1);
    while (l <= r) { // l and m might be same
        int m = l + (r-l)/2;
        if (arr[m] == key) {
            return m;
        }
        if (arr[m] < key) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return -1;
}

int floorSearch (int *arr, int size, int key) {
    if (key < arr[0]) {
        return -1;
    }

    if (size == 1) {
        return 0;
    }
    else if (size == 2) {
        if (key < arr[1]) {
            return 0;
        }
        else {
            return 1;
        }
    }

    int l(0), r(size -1);
    while (l < r-1) { // so that l, m and r will remian distinct
        int m = l + (r-l)/2;
        if (arr[m] <= key) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l;
}

int ceilSearch (int *arr, int size, int key) {
    if (key > arr[size -1]) {
        return -1;
    }

    if (size == 1) {
        return 0;
    }
    else if (size == 2) {
        if (key > arr[0]) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int l(0), r(size -1);
    while (l < r-1) { // so that l, m and r will remian distinct
        int m = l + (r-l)/2;
        if (arr[m] >= key) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return r;
}

int getRightMostIndex (int *arr, int size, int key) {
    int rIdx = floorSearch(arr, size, key);
    return arr[rIdx] == key ? rIdx : -1; 
}

int getLeftMostIndex (int *arr, int size, int key) {
    int lIdx = ceilSearch(arr, size, key);
    return arr[lIdx] == key ? lIdx : -1;
}

int getRotationIdx (int *arr, int size) {
    int ret(-1);
    if (size ==2 && arr[1] < arr[0])
        ret = 1;

    int l(0), r(size-1), m(0);
    while(r-l > 1) {
        m = l + (r-l)/2;
        if (arr[m] < arr[m-1] && arr[m] < arr[m+1])
            ret = m;
        if (arr[l] < arr[m])
            l = m;
        else
            r = m;
    }
    return ret;
}

void main() {
    // int testArr[] = {1, 2, 3, 4, 5, 5, 5, 5, 7};
    // int idx = getLeftMostIndex(testArr, sizeof(testArr)/sizeof(testArr[0]), 5);
    int testArr[] = {5, 1, 2, 3, 4, 5};
    int idx = getRotationIdx(testArr, sizeof(testArr)/sizeof(testArr[0]));
    std::cout << "index = " << idx << std::endl;
}
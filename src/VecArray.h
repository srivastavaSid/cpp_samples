#include <iostream>

#ifndef vecArray_h
#define vecArray_h
    template<typename T>
    class vecArray {
        public:
            static const DEF_CAPACITY = 100
            vecArray(int newCap = DEF_CAPACITY):
                capacity(newCap), sz(0) {
                    arr = new T[newCap];
                }
            vecArray(vecArray& rhs):
                capacity(rhs.capacity), sz(rhs.sz) {
                    arr = new T[capacity];
                    for (int i=0; i<sz; i++) {
                        arr[i] = rhs.arr[i];
                    }
                }
            vecArray(vecArray&& rhs):
                capacity(std::move(rhs.capacity)), sz(std::move(rhs.sz)), arr(std::move(rhs.arr)) {
                    rhs.capacity = 0;
                    rhs.sz = 0;
                    rhs.arr = nullptr;
                }
            vecArray& operator = (vecArray& rhs) {
                vecArray temp = rhs;
                std::swap(temp, *this);
                return *this;
            }
            vecArray& operator = (vecArray&& rhs) {
                std::swap(capacity, rhs.capacity);
                std::swap(sz, rhs.sz);
                std::swap(arr, rhs.arr);
                return *this;
            }
            ~vecArray() {
                delete [] arr;
                capacity = 0;
                sz = 0;
                arr = nullptr;
            }
            void reserve (int newCap) {
                if (capacity < newCap) {
                    T* temp = new T[newCap];
                    for (int i=0; i<sz; i++)
                        temp[i] = arr[i];
                    delete [] arr;
                    arr = temp;
                    capacity = newCap;
                }
            }
        private:
            int capacity;
            int sz;
            T* arr;
    };
#endif
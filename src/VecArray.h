#include <iostream>

#ifndef vecArray_h
#define vecArray_h
    template<typename T>
    class vecArray {
        public:
            static const int DEF_CAPACITY = 100;
            vecArray(int newCap = DEF_CAPACITY):
                mCap(newCap), mSize(0) {
                    mArr = new T[newCap];
                }
            vecArray(const vecArray& rhs):
                mCap(rhs.mCap), mSize(rhs.mSize) {
                    mArr = new T[mCap];
                    for (int i=0; i<mSize; i++) {
                        mArr[i] = rhs.mArr[i];
                    }
                }
            vecArray(vecArray&& rhs):
                mCap(std::move(rhs.mCap)), mSize(std::move(rhs.mSize)), mArr(std::move(rhs.mArr)) {
                    rhs.mCap = 0;
                    rhs.mSize = 0;
                    rhs.mArr = nullptr;
                }
            vecArray& operator = (const vecArray& rhs) {
                vecArray temp = rhs;
                std::swap(temp, *this);
                return *this;
            }
            vecArray& operator = (vecArray&& rhs) {
                std::swap(mCap, rhs.mCap);
                std::swap(mSize, rhs.mSize);
                std::swap(mArr, rhs.mArr);
                return *this;
            }
            ~vecArray() {
                delete [] mArr;
                mCap = 0;
                mSize = 0;
                mArr = nullptr;
            }
            void reserve (int newCap) {
                if (mCap < newCap) {
                    T* temp = new T[newCap];
                    for (int i=0; i<mSize; i++)
                        temp[i] = mArr[i];
                    delete [] mArr;
                    mArr = temp;
                    mCap = newCap;
                }
            }
            T& operator [] (int idx) {
                return mArr[idx];
            }
            const T& operator [] (int idx) const {
                return mArr[idx];
            }
            bool empty () const {
                return size() == 0;
            }
            int size() const {
                return mSize;
            }
            int capacity() const {
                return mCap;
            }
            void pushBack(const T& x) {
                if (mSize == mCap) {
                    reserve(mCap*2);
                }
                mArr[mSize++] = x;
            }
            void pushBack(T&& x) {
                if (mSize == mCap) {
                    reserve(mCap*2);
                }
                mArr[mSize++] = std::move(x);
            }
            const T& back() const {
                return mArr[mSize -1];
            }
            T& back() {
                return const_cast<T&>( (static_cast<const vecArray&>(*this)).back());
            }
            void popBack() {
                mSize--;
            }
            using iterator = T*;
            using const_iterator = const T*;
            iterator begin() {
                return &(mArr[0]);
            }
            const_iterator begin() const {
                return &(mArr[0]);
            }
            iterator end() {
                return &(mArr[mSize]);
            }
            const_iterator end() const {
                return &(mArr[mSize]);
            }
            void printVec() {
                for (auto it=begin(); it!=end(); it++)
                    std::cout << *it << " ";
                std::cout << std::endl;
            }
        private:
            int mCap;
            int mSize;
            T* mArr;
    };
#endif
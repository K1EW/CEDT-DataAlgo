#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include <iostream>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
    int i=a,j=b;
    while (i < j){
        using std::swap;
        swap(mData[(mFront + i++)%mCap],mData[(mFront + j--)%mCap]);
    }
}

#endif
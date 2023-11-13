#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  T temp = mData[(mFront+pos)%mCap];
  for (int i=pos;i<=(int)mSize-2;i++)
    mData[(mFront+i)%mCap] = mData[(mFront+i+1)%mCap];
  mData[(mFront+mSize-1)%mCap] = temp;
}

#endif

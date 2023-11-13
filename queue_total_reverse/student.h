#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  mFront = (mFront + (aux?(1 - mSize):(mSize - 1)) + mCap)%mCap;
  aux = (aux?0:1);
}

template <typename T>
const T& CP::queue<T>::front() const {
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  return mData[(mFront + (aux?(1 - mSize):(mSize - 1)) + mCap)%mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  if (mSize + 1 > mCap){
    T* arr = new T[mSize+1]();
    for (size_t i = 0; i < mSize; i++) {
      arr[i] = mData[((aux?((mFront + mSize - 1)%mCap):mFront) + i) % mCap];
    }
    delete[] mData;
    mData = arr;
    mCap = mSize+1;
    mFront = 0;
  }
  mData[(mFront + (aux?-mSize:mSize) +mCap) % mCap] = element;
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  mFront = (mFront + (aux?-1:1) + mCap) % mCap;
  mSize--;
}

#endif
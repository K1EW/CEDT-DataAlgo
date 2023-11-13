#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  return mData[(mFront + (mSize + idx)%mSize + mCap)%mCap];
}

#endif

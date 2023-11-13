#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    T* newData = new T[mSize];
    for (int i=0;i<mSize;i++)
        newData[i] = mData[i];
    mCap = mSize;
    delete[] mData;
    mData = newData;
}

#endif

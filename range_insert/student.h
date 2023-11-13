#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  int n = mSize + (last - first), start = position - this->begin();
  T* newData = new T[n];
  int i=0, j=0;
  auto it = first;
  while (i < n){
    if (i < start || it == last) newData[i++] = mData[j++];
    else{
      while (it != last){
        newData[i++] = *it;
        it++;
      }
    }
  }
  mCap = n, mSize = n;
  delete[] mData;
  mData = newData;
}

#endif

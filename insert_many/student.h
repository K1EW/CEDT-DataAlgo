#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  std::sort(data.begin(), data.end());
  int cnt = 0, n = mSize + data.size();
  T* newData = new T[n];
  int i=0,j=0,k=0;
  while (i<n){
    if (i == data[j].first + cnt){
      newData[i] = data[j].second;
      j++;
      cnt++;
    }else{
      newData[i] = mData[k++];
    }
    i++;
  }
  mSize = n;
  mCap = n;
  delete[] mData;
  mData = newData;
}

#endif

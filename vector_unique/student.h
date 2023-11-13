#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <set>


template <typename T>
void CP::vector<T>::uniq() {
  std::set<T> s;
  for (auto it = this->begin(); it != this->end(); it++)
    s.insert(*it);
  int n = s.size();
  T* newData = new T[n];
  int i=0;
  s.clear();
  for (auto it = this->begin(); it != this->end(); it++){
    if (s.count(*it)) continue;
    else{
      newData[i++] = *it;
      s.insert(*it);
    }
  }
  mCap = n, mSize = n;
  delete[] mData;
  mData = newData;
}

#endif

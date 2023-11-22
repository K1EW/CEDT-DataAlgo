#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include <algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  std::sort(pos.begin(), pos.end());
  int i=0, j=0, k=0;
  while (i<mSize){
    while (i == pos[k]){ i++, k++;}
    mData[(mFront+j)%mCap] = mData[(mFront+i)%mCap];
    i++,j++;
  }
  mSize -= pos.size();
}

#endif

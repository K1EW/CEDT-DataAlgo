#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  node* trav = mHeader->prev;
  int n = 0;
  for (auto it = ls.begin(); it != ls.end(); it++){
    if ((*it).size() != 0){
      n += (*it).size();
      node* intrav = (*it).begin().ptr;
      trav->next = intrav;
      intrav->prev = trav;
      intrav = (*it).mHeader;
      trav = intrav->prev;
      (*it).mSize = 0;
      intrav->next = intrav;
      intrav->prev = intrav;
    }
  }
  trav->next = mHeader;
  mHeader->prev = trav;
  mSize += n;
}

#endif

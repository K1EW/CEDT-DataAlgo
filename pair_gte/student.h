#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T1,typename T2>
bool CP::pair<T1,T2>::operator>=(const pair<T1,T2>& other) const {
  if (first > other.first) return true; //x.first > y.first
  if (!(other.first > first)){ //!(y.first > x.first)
    if (second > other.second) return true;
    else if (!(other.second > second)) return true;
  }
  return false;
}

#endif

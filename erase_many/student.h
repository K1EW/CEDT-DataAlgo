#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  int cnt=0;
  for (auto p : pos){
    erase(this->begin() + (p - cnt));
    cnt++;
  }
}

#endif

#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  T* arr = new T[pos];
  for (int i=0;i<pos;i++){
    arr[i] = top();
    pop();
  }
  push(value);
  for (int i=pos-1;i>=0;i--)
    push(arr[i]);
}

#endif

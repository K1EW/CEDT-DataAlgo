#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
    using std::swap;
    int A = a-begin(), B = b-begin();
    if (A < 0 || A >= mSize || B < 0 || B >= mSize || A + m - 1 >= mSize || B + m - 1 >= mSize || A + m - 1 >= B && B + m - 1 >= A || m <= 0) return false;
    while(m--) swap(mData[A++], mData[B++]);
    return true;       
}

#endif

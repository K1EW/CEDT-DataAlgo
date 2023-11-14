void replace(const T& x, list<T>& y) {
  list<T> l;
  for (auto it = begin(); it != end(); it++){
    if (*it != x) l.push_back(*it);
    else{
      for (auto yit = y.begin(); yit != y.end(); yit++)
        l.push_back(*yit);
    }
  }
  clear();
  for (auto it = l.begin(); it != l.end(); it++)
    push_back(*it);
}
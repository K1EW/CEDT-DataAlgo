void splitList(list<T>& list1, list<T>& list2) {
  int n = (size()+1)/2, m = size()/2;
  if (n==0) return;
  node *trav = mHeader;
  for (int i=0;i<n;i++) trav = trav->next;
  node *trav2 = trav->next;
  
  list1.mHeader->prev->next = mHeader->next;
  mHeader->next->prev = list1.mHeader->prev;
  trav->next = list1.mHeader;
  list1.mHeader->prev = trav;

  list2.mHeader->prev->next = trav2;
  trav2->prev = list2.mHeader->prev;
  mHeader->prev->next = list2.mHeader;
  list2.mHeader->prev = mHeader->prev;

  mHeader->prev = mHeader;
  mHeader->next = mHeader;

  mSize = 0;
  list1.mSize += n;
  list2.mSize += m;
}
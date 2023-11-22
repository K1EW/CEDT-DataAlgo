#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t aux) {
  if (n == NULL) return 0;
  if (n->left == NULL && n->right == NULL) return aux;
  return my_recur(n->left, aux+1) + my_recur(n->right, aux+1);
}
template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::sum_leaves_depth() {
  return my_recur(mRoot, 0);
}

#endif

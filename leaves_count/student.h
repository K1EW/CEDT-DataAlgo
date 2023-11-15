#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count(node* n) {
  if (n==NULL) return 0;
  if (n->left == NULL && n->right == NULL) return 1;
  size_t lft = 0;
  size_t rght = 0;
  if (n->left != NULL) lft = leaves_count(n->left);
  if (n->right != NULL) rght = leaves_count(n->right);
  return lft + rght;
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count() {
  return leaves_count(mRoot);
}


#endif

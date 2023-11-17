#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename KeyT,
          typename MappedT,
          typename CompareT >

CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node* trav = this->mRoot;
  node* ptr = NULL;
  while(trav != NULL){
    if (trav->data.first < val) trav = trav->right;
    else{
      ptr = trav;
      trav = trav->left;
    }
  }
  if (ptr == NULL) return result;
  node* red[this->mSize];
  node* green[this->mSize];
  int i=0,j=0;
  if (ptr->left) green[j++] = ptr->left;
  trav = ptr;
  while (trav != NULL){
    if (trav->data.first >= val) red[i++] = trav;
    else green[j++] = trav;
    trav = trav->parent;
  }
  for (int k=0;k<i;k++){
    if (k-1>=0){
      red[k]->left = red[k-1];
      red[k-1]->parent = red[k];
    }
    if (red[k]->parent && red[k]->parent->right == red[k]) red[k]->parent->right = NULL;
  }
  for (int k=0;k<j;k++){
    if (k-1>=0){
      green[k]->right = green[k-1];
      green[k-1]->parent = green[k];
    }
    if (green[k]->parent && green[k]->parent->left == green[k]) green[k]->parent->left = NULL;
  }
  if (j != 0){
    green[j-1]->parent = NULL;
    this->mRoot = green[j-1];
  }else this->mRoot = NULL;

  if (i != 0){
    red[i-1]->parent = NULL;
    result.mRoot = red[i-1];
  }else result.mRoot = NULL;

  return result;
}

#endif

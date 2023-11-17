// Your code here

int DFS(node* n, KeyT &key, int &bal){
    int height = 0;
    if (n==NULL) return -1;
    int lchild = DFS(n->left, key, bal);
    int rchild = DFS(n->right, key, bal);
    int val = (lchild - rchild) >= 0 ? (lchild - rchild) : (rchild - lchild);
    if (val > bal){
        key = n->data.first;
        bal = val;
    }else if (val == bal){
    if (n->data.first < key)
        key = n->data.first;
    }
    return 1 + std::max(lchild, rchild);
}

KeyT getValueOfMostImbalanceNode() {
    int maxBal = 0;
    KeyT minKey = mRoot->data.first;
    DFS(mRoot, minKey, maxBal);
    return minKey;
}
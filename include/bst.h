// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#endif  // INCLUDE_BST_H_

template <typename T>
class BST {
 public:
    struct Node {
    T value;
    int count;
    Node *left;
    Node *right;
    };
 private:
    Node* root;
    Node* addNode(Node *, T);
    int depthTree(Node*);
    int searchNode(Node*, T);
    void delTree(Node*);
    //Node* delNode(Node*,int);
 public:
    BST();
    ~BST();
    void add(T);
    //void print();
    int depth();
    int search(T);
};

template <typename T>
BST<T>::BST():root(nullptr) {}

template <typename T>
BST<T>::~BST() {
  if (root)
    delTree(root);
}

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node *root, T value) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->count = 1;
    root->left = root->right = nullptr;
  } else if (root->value > value) {
    root->left = addNode(root->left, value);
  } else if (root->value < value) {
    root->right = addNode(root->right, value);
  } else {
    root->count++;
    return root;
  }
}

template <typename T>
void BST<T>::add(T value) {
  root = addNode(root, value);
}

template <typename T>
void BST<T>::delTree(Node* root) {
  if (root == nullptr) {
    return;
  } else {
    delTree(root->left);
    delTree(root->right);
    delete root;
  }
}

template <typename T>
int BST<T>::depth() {
  return depthTree(root) - 1;
}

template <typename T>
int BST<T>::search(T value) {
  return searchNode(root, value);
}

template <typename T>
int BST<T>::searchNode(Node* root, value) {
  if (root == nullptr) {
    return 0;
  } else if (root->value < value) {
    return searchNode(root->left, value);
  } else {
    return searchNode(root->right, value);
  }
}

template <typename T>
int BST<T>::depthTree(Node* root) { //глубина для каждой ветки
  int vetka1, vetka2;
  if (root == nullptr) {
    return 0;
  } else {
    vetka1 = depthTree(root->left);
    vetka2 = depthTree(root->right);
    if (vetka1 > vetka2) {
      return vetka1++;
    } else { return vetka2++; }
  }
}

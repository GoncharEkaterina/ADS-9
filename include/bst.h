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
    void printTree(Node*);
    int depthTree(Node*);
    int searchNode(Node*, T);
    void delTree(Node*);
    Node* delNode(Node*,int);
  public:
  BST();
  ~BST();
  void add(T);
  void print();
  int depth();
  int search(T);
  void clear();
  void remove(int);
};

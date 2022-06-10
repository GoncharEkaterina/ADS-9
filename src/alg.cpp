// Copyright 2021 NNTU-CS
#include <algorithm>
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include  "bst.h"
//using namespace std;

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> Tree;
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "File error" << std::endl;
    return Tree;
  }
  char ch;
  int coun = 0;
  std::string str = "";
  while (!file.eof()) {
    ch = file.get();
    coun++;
    if (ch >= 'A' && ch <= 'Z') {
      ch = ('a' - 'A') + ch;
    }
    if (ch >= 'a' && ch <= 'z') {
      str += ch;
    } else {
      Tree.add(str);
      str = "";
    }
  }
  file.close();
  return Tree;
}

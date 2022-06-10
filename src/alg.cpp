// Copyright 2021 NNTU-CS
#include <algorithm>
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include  "bst.h"
using namespace std;

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  string ch;
  BST<string> Tree;
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "File error" << endl;
    return Tree;
  }
  int count = 0;
  string str;
  while (!file.eof()) {
    ch = file.get();
    count++;
    if (ch >= 'A' && ch <= 'Z') {
      ch += ('a' - 'A');
    }
    if (ch >= 'a' && ch <= 'z') {
      str += ch;
    } else {
      Tree.addword(str);
      ch = "";
    }
  }
  file.close();
  return Tree;
}

#include <iostream>

struct Node {
  int value = 0;
  Node *left = nullptr;
  Node *right = nullptr;
};

struct Tree {
  Node *root = nullptr;
};

void Insert(Node *&root, const int &value) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
  } else if (value < root->value) {
    Insert(root->left, value);
  } else if (value > root->value) {
    Insert(root->right, value);
  }
}

void FindLeaves(Node *root, int *leaves, int &j) {
  if (root == nullptr) {
    return;
  }
  if (root->left == nullptr && root->right == nullptr) {
    leaves[j] = root->value;
    ++j;
  }
  FindLeaves(root->left, leaves, j);
  FindLeaves(root->right, leaves, j);
}

void DeleteTree(Node *root) {
  if (root == nullptr) {
    return;
  }
  DeleteTree(root->left);
  DeleteTree(root->right);
  delete root;
}

int main() {
  int size = 0;
  int value = 1;
  Node *root = nullptr;
  while (value != 0) {
    std::cin >> value;
    if (value != 0) {
      Insert(root, value);
      ++size;
    }
  }
  int *leaves = new int[size];
  int j = 0;
  FindLeaves(root, leaves, j);
  for (int i = 0; i < j; ++i) {
    std::cout << leaves[i] << " ";
  }
  DeleteTree(root);
  delete[] leaves;
  return 0;
}

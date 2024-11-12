#include <iostream>

struct Node {
  int value = 0;
  Node *left = nullptr;
  Node *right = nullptr;
};

struct Tree {
  Node *root = nullptr;
};

int Max(Node *node) {
  while (node->right != nullptr) {
    node = node->right;
  }
  return node->value;
}

int SecondLargest(Node *root) {
  if (root->right == nullptr) {
    return Max(root->left);
  }
  Node *parent = nullptr;
  Node *current = root;
  while (current->right != nullptr) {
    parent = current;
    current = current->right;
  }
  if (current->left != nullptr) {
    return Max(current->left);
  }
  return parent->value;
}

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

void DeleteTree(Node *root) {
  if (root == nullptr) {
    return;
  }
  DeleteTree(root->left);
  DeleteTree(root->right);
  delete root;
}

int main() {
  int value = 1;
  Node *root = nullptr;
  while (value != 0) {
    std::cin >> value;
    if (value != 0) {
      Insert(root, value);
    }
  }
  std::cout << SecondLargest(root);
  DeleteTree(root);
  return 0;
}

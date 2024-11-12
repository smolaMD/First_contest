#include <iostream>

int MinValue(const int *pre, const int &size) {
  int min_v = pre[0];
  for (int i = 0; i < size; ++i) {
    if (pre[i] < min_v) {
      min_v = pre[i];
    }
  }
  return min_v;
}

int MaxValue(const int *pre, const int &size) {
  int max_v = pre[0];
  for (int i = 0; i < size; ++i) {
    if (pre[i] > max_v) {
      max_v = pre[i];
    }
  }
  return max_v;
}

struct Node {
  int value = 0;
  Node *left = nullptr;
  Node *right = nullptr;
};

Node *Insert(Node *root, const int &value) {
  auto *node = new Node;
  node->value = value;
  if (root == nullptr) {
    return node;
  }
  if (value < root->value) {
    root->left = Insert(root->left, value);
  } else {
    root->right = Insert(root->right, value);
  }
  return root;
}

Node *BuildTree(const int *pre, const int &arr_size, int &i, const int &min_v, const int &max_v) {
  if (i >= arr_size || pre[i] < min_v || pre[i] > max_v) {
    return nullptr;
  }
  auto *root = new Node;
  root->value = pre[i];
  ++i;
  root->left = BuildTree(pre, arr_size, i, min_v, root->value);
  root->right = BuildTree(pre, arr_size, i, root->value, max_v);
  return root;
}

void PostOrder(Node *root, int *post, int &j) {
  if (root == nullptr) {
    return;
  }
  PostOrder(root->left, post, j);
  PostOrder(root->right, post, j);
  post[j++] = root->value;
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
  int n = 0;
  std::cin >> n;
  int *pre = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> pre[i];
  }
  int *post = new int[n];
  int min_v = MinValue(pre, n);
  int max_v = MaxValue(pre, n);
  int i = 0;
  Node *root = BuildTree(pre, n, i, min_v, max_v);
  int j = 0;
  PostOrder(root, post, j);
  for (int i = 0; i < n; ++i) {
    std::cout << post[i] << " ";
  }
  DeleteTree(root);
  delete[] pre;
  delete[] post;
  return 0;
}

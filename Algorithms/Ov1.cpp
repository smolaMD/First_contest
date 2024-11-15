#include <cstring>
#include <iostream>

int MaxValue(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

struct Node {
  int value = 0;
  int cnt = 1;
  Node *left = nullptr;
  Node *right = nullptr;
  int height = 0;
};

struct Tree {
  Node *root = nullptr;
  int size = 0;
};

int Height(Node *node) {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

void FixHeight(Node *node) {
  node->height = MaxValue(Height(node->left), Height(node->right)) + 1;
}

int BalanceFactor(Node *node) {
  return Height(node->right) - Height(node->left);
}

Node *Right(Node *node) {
  Node *left = node->left;
  node->left = left->right;
  left->right = node;
  FixHeight(left);
  FixHeight(node);
  return left;
}

Node *Left(Node *node) {
  Node *right = node->right;
  node->right = right->left;
  right->left = node;
  FixHeight(right);
  FixHeight(node);
  return right;
}

Node *Balance(Node *node) {
  if (BalanceFactor(node) == 2) {
    if (BalanceFactor(node->right) < 0) {
      node->right = Right(node->right);
    }
    node = Left(node);
  }
  if (BalanceFactor(node) == -2) {
    if (BalanceFactor(node->left) > 0) {
      node->left = Left(node->left);
    }
    node = Right(node);
  }
  return node;
}

int Max(Node *node) {
  while (node->right != nullptr) {
    node = node->right;
  }
  return node->value;
}

int Min(Node *node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node->value;
}

Node *Insert(Node *node, const int &value) {
  if (node == nullptr) {
    node = new Node();
    node->value = value;
    node->cnt = 1;
    node->height = 1;
    return node;
  }
  if (value < node->value) {
    node->left = Insert(node->left, value);
  } else if (value > node->value) {
    node->right = Insert(node->right, value);
  } else {
    node->cnt++;
    return node;
  }
  FixHeight(node);
  return Balance(node);
}

Node *DeleteMin(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->left == nullptr) {
    if (node->cnt > 1) {
      node->cnt--;
      return node;
    }
    Node *right_node = node->right;
    delete node;
    return right_node;
  }
  node->left = DeleteMin(node->left);
  return Balance(node);
}

Node *DeleteMax(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->right == nullptr) {
    if (node->cnt > 1) {
      node->cnt--;
      return node;
    }
    Node *left_node = node->left;
    delete node;
    return left_node;
  }
  node->right = DeleteMax(node->right);
  return Balance(node);
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
  int m = 0;
  std::cin >> m;
  Tree tree;
  tree.root = nullptr;
  for (int i = 0; i < m; ++i) {
    char command[20];
    std::cin >> command;
    if (strcmp(command, "insert") == 0) {
      int n = 0;
      std::cin >> n;
      tree.root = Insert(tree.root, n);
      ++tree.size;
      std::cout << "ok\n";
    }
    if (strcmp(command, "extract_min") == 0) {
      if (tree.size == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Min(tree.root) << "\n";
        tree.root = DeleteMin(tree.root);
        --tree.size;
      }
    }
    if (strcmp(command, "get_min") == 0) {
      if (tree.size == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Min(tree.root) << "\n";
      }
    }
    if (strcmp(command, "extract_max") == 0) {
      if (tree.size == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Max(tree.root) << "\n";
        tree.root = DeleteMax(tree.root);
        --tree.size;
      }
    }
    if (strcmp(command, "get_max") == 0) {
      if (tree.size == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Max(tree.root) << "\n";
      }
    }
    if (strcmp(command, "size") == 0) {
      std::cout << tree.size << "\n";
    }
    if (strcmp(command, "clear") == 0) {
      DeleteTree(tree.root);
      tree.root = nullptr;
      tree.size = 0;
      std::cout << "ok\n";
    }
  }
  DeleteTree(tree.root);
  return 0;
}

#include <iostream>

struct Node {
  int data = 0;
  bool used = false;
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
};

struct Heap {
  int size_ = 0;
  Node *head_ = nullptr;

  void Insert(int value) {
    if (head_ == nullptr) {
      head_ = new Node();
      head_->data = value;
      return;
    }
    Node *current = head_;
    while (true) {
      if (current->data == value) {
        break;
      }
      if (current->data > value) {
        if (current->left == nullptr) {
          current->left = new Node();
          current->left->data = value;
          current->left->parent = current;
          return;
        }
        current = current->left;
      } else {
        if (current->data < value) {
          if (current->right == nullptr) {
            current->right = new Node();
            current->right->data = value;
            current->right->parent = current;
            return;
          }
          current = current->right;
        }
      }
    }
  }
};

Node *GoLeft(const Heap heap, Node *node) {
  if (heap.head_ == nullptr) {
    return nullptr;
  }
  if (node->left == nullptr) {
    if (node->right == nullptr) {
      return node;
    }
    return GoLeft(heap, node->right);
  }
  return GoLeft(heap, node->left);
}

Node *GoUp(const Heap heap, Node *&node, bool is_delete = false) {
  if (node == nullptr) {
    return nullptr;
  }
  if (heap.head_ == node) {
    if (is_delete) {
      delete node;
    }
    return nullptr;
  }
  while (node->parent != nullptr && (node->parent->right == nullptr || node->parent->right == node)) {
    node = node->parent;
    if (is_delete) {
      delete node->right;
    }
  }
  if (node->parent == nullptr) {
    if (is_delete) {
      delete node;
    }
    return nullptr;
  }
  if (is_delete) {
    Node *temp = node->parent;
    temp->left = nullptr;
    delete node;
    return temp->right;
  }
  return node->parent->right;
}

void GetLists(Heap heap, int *&lists) {
  int cnt = 0;
  Node *current = heap.head_;
  if (current == nullptr) {
    return;
  }
  while (true) {
    current = GoLeft(heap, current);
    if (current->left == nullptr && current->right == nullptr) {
      lists[cnt] = current->data;
      cnt++;
    }
    current = GoUp(heap, current);
    if (current == nullptr) {
      break;
    }
  }
}

void Delete(Heap heap, Node *&node) {
  Node *temp_l = node->right;
  Node *temp_r = node->left;
  delete node;
  if (temp_l != nullptr) {
    Delete(heap, temp_l);
  }
  if (temp_r != nullptr) {
    Delete(heap, temp_r);
  }
}
int main() {
  int n = 0;
  Heap heap;
  int tmp = -1;
  while (tmp != 0) {
    std::cin >> tmp;
    if (tmp != 0) {
      heap.Insert(tmp);
    }
    ++n;
  }
  int *lists = new int[n]{};
  GetLists(heap, lists);
  for (int i = 0; lists[i] != 0; ++i) {
    std::cout << lists[i] << ' ';
  }
  std::cout << '\n';
  Delete(heap, heap.head_);
  delete[] lists;
}

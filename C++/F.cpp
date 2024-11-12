#include <cstdio>
#include <cstring>
#include <iostream>

template <typename T>
struct Node {
  T value;
  Node *next = nullptr;
  Node *prev = nullptr;
};

template <typename T>
struct Deque {
  Node<T> *front = nullptr;
  Node<T> *back = nullptr;
  size_t size = 0;
};

template <typename T>
size_t Size(Deque<T> &deque) {
  return deque.size;
}

template <typename T>
void PushFront(Deque<T> &deque, T &value) {
  ++deque.size;
  if (deque.size == 1) {
    auto *node = new Node<T>;
    node->value = value;
    deque.front = node;
    deque.back = node;
  } else {
    auto *node = new Node<T>;
    node->value = value;
    node->prev = deque.front;
    deque.front->next = node;
    deque.front = node;
  }
}

template <typename T>
void PopFront(Deque<T> &deque) {
  if (deque.size == 0) {
    return;
  }
  if (deque.size == 1) {
    delete deque.back;
    deque.back = nullptr;
    deque.front = nullptr;
    --deque.size;
  } else {
    (deque.front->prev)->next = nullptr;
    Node<T> *tmp_front = deque.front->prev;
    delete deque.front;
    deque.front = tmp_front;
    --deque.size;
  }
}

template <typename T>
T Front(Deque<T> &deque) {
  return deque.front->value;
}

template <typename T>
void PushBack(Deque<T> &deque, T &value) {
  ++deque.size;
  if (deque.size == 1) {
    auto *node = new Node<T>;
    node->value = value;
    deque.back = node;
    deque.front = node;
  } else {
    auto *node = new Node<T>;
    node->value = value;
    node->next = deque.back;
    deque.back->prev = node;
    deque.back = node;
  }
}

template <typename T>
void PopBack(Deque<T> &deque) {
  if (deque.size == 0) {
    return;
  }
  if (deque.size == 1) {
    delete deque.back;
    deque.back = nullptr;
    deque.front = nullptr;
    --deque.size;
  } else {
    (deque.back->next)->prev = nullptr;
    Node<T> *tmp_back = deque.back->next;
    delete deque.back;
    deque.back = tmp_back;
    --deque.size;
  }
}

template <typename T>
T Back(Deque<T> &deque) {
  return deque.back->value;
}

int main() {
  int n = 0;
  std::cin >> n;
  Deque<int> deque;
  for (int i = 0; i < n; ++i) {
    char command[20];
    std::cin >> command;
    if (strcmp(command, "push_front") == 0) {
      int value = 0;
      std::cin >> value;
      PushFront(deque, value);
      std::cout << "ok\n";
    }
    if (strcmp(command, "push_back") == 0) {
      int value = 0;
      std::cin >> value;
      PushBack(deque, value);
      std::cout << "ok\n";
    }
    if (strcmp(command, "pop_front") == 0) {
      if (Size(deque) == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Front(deque) << '\n';
        PopFront(deque);
      }
    }
    if (strcmp(command, "pop_back") == 0) {
      if (Size(deque) == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Back(deque) << '\n';
        PopBack(deque);
      }
    }
    if (strcmp(command, "front") == 0) {
      if (Size(deque) == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Front(deque) << '\n';
      }
    }
    if (strcmp(command, "back") == 0) {
      if (Size(deque) == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Back(deque) << '\n';
      }
    }
    if (strcmp(command, "size") == 0) {
      std::cout << Size(deque) << '\n';
    }
    if (strcmp(command, "clear") == 0) {
      while (Size(deque) != 0) {
        PopBack(deque);
      }
      std::cout << "ok\n";
    }
    if (strcmp(command, "exit") == 0) {
      while (Size(deque) != 0) {
        PopBack(deque);
      }
      std::cout << "bye\n";
      break;
    }
  }
  return 0;
}

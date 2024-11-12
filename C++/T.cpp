#include <cstring>
#include <iostream>

struct Node {
  int value = 0;
  Node *next = nullptr;
  Node *prev = nullptr;
};

struct Deque {
  Node *front = nullptr;
  Node *back = nullptr;
  Node *mid = nullptr;
  size_t size = 0;
};

void PushFront(Deque &deque, int &value) {
  ++deque.size;
  if (deque.size == 1) {
    auto *node = new Node;
    node->value = value;
    deque.front = node;
    deque.back = node;
    deque.mid = node;
  } else {
    auto *node = new Node;
    node->value = value;
    node->prev = deque.front;
    deque.front->next = node;
    deque.front = node;
    if (deque.size % 2 == 0) {
      deque.mid = deque.mid->next;
    }
  }
}

void PopFront(Deque &deque) {
  if (deque.size == 0) {
    return;
  }
  if (deque.size == 1) {
    delete deque.back;
    deque.back = nullptr;
    deque.front = nullptr;
    deque.mid = nullptr;
  } else {
    if (deque.size == 2) {
      deque.mid = deque.mid->prev;
    } else if (deque.size % 2 == 0) {
      deque.mid = deque.mid->prev;
    }
    (deque.front->prev)->next = nullptr;
    Node *tmp_front = deque.front->prev;
    delete deque.front;
    deque.front = tmp_front;
  }
  --deque.size;
}

int Front(Deque &deque) {
  return deque.front->value;
}

void PushBack(Deque &deque, int &value) {
  ++deque.size;
  if (deque.size == 1) {
    auto *node = new Node;
    node->value = value;
    deque.back = node;
    deque.front = node;
    deque.mid = node;
  } else {
    auto *node = new Node;
    node->value = value;
    node->next = deque.back;
    deque.back->prev = node;
    deque.back = node;
    if (deque.size % 2 != 0) {
      deque.mid = deque.mid->prev;
    }
  }
}

void PopBack(Deque &deque) {
  if (deque.size == 0) {
    return;
  }
  if (deque.size == 1) {
    delete deque.back;
    deque.back = nullptr;
    deque.front = nullptr;
    deque.mid = nullptr;
  } else {
    if (deque.size % 2 != 0) {
      deque.mid = deque.mid->next;
    }
    (deque.back->next)->prev = nullptr;
    Node *tmp_back = deque.back->next;
    delete deque.back;
    deque.back = tmp_back;
  }
  --deque.size;
}

int Back(Deque &deque) {
  return deque.back->value;
}

void Insert(Deque &deque, int &value) {
  if (deque.size == 0 || deque.size == 1) {
    PushBack(deque, value);
  } else {
    auto *node = new Node;
    node->prev = deque.mid->prev;
    node->next = deque.mid;
    node->value = value;
    node->prev->next = node;
    node->next->prev = node;
    ++deque.size;
    if (deque.size % 2 != 0) {
      deque.mid = deque.mid->prev;
    }
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  Deque deque;
  for (int i = 0; i < n; ++i) {
    char command[20];
    std::cin >> command;
    if (strcmp(command, "+") == 0) {
      int value = 0;
      std::cin >> value;
      PushBack(deque, value);
    }
    if (strcmp(command, "-") == 0) {
      std::cout << Front(deque) << '\n';
      PopFront(deque);
    }
    if (strcmp(command, "*") == 0) {
      int value = 0;
      std::cin >> value;
      Insert(deque, value);
    }
  }
  while (deque.size != 0) {
    PopBack(deque);
  }
  return 0;
}

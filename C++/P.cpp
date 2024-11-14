#include <iostream>

struct Node {
  int value = 0;
  Node *next = nullptr;
  Node *prev = nullptr;
};

struct Deque {
  Node *front = nullptr;
  Node *back = nullptr;
  size_t size = 0;
};

void PushFront(Deque &deque, int &value) {
  ++deque.size;
  if (deque.size == 1) {
    auto *node = new Node;
    node->value = value;
    deque.front = node;
    deque.back = node;
  } else {
    auto *node = new Node;
    node->value = value;
    node->prev = deque.front;
    deque.front->next = node;
    deque.front = node;
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
    --deque.size;
  } else {
    (deque.front->prev)->next = nullptr;
    Node *tmp_front = deque.front->prev;
    delete deque.front;
    deque.front = tmp_front;
    --deque.size;
  }
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
  } else {
    auto *node = new Node;
    node->value = value;
    node->next = deque.back;
    deque.back->prev = node;
    deque.back = node;
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
    --deque.size;
  } else {
    (deque.back->next)->prev = nullptr;
    Node *tmp_back = deque.back->next;
    delete deque.back;
    deque.back = tmp_back;
    --deque.size;
  }
}

int Back(Deque &deque) {
  return deque.back->value;
}

bool Game(Deque &deque1, Deque &deque2, int &cnt) {
  bool flag = true;
  while (deque1.size != 0 && deque2.size != 0) {
    if ((Front(deque1) > Front(deque2) && (Front(deque1) - Front(deque2) != 9)) ||
        (Front(deque2) - Front(deque1) == 9)) {
      int top1 = Front(deque1);
      int top2 = Front(deque2);
      PushBack(deque1, top1);
      PushBack(deque1, top2);
      PopFront(deque1);
      PopFront(deque2);
    } else {
      int top1 = Front(deque1);
      int top2 = Front(deque2);
      PushBack(deque2, top1);
      PushBack(deque2, top2);
      PopFront(deque1);
      PopFront(deque2);
    }
    ++cnt;
    if (cnt == 1000000) {
      flag = false;
      return flag;
    }
  }
  return flag;
}

int main() {
  Deque deque1;
  Deque deque2;
  for (int i = 0; i < 5; ++i) {
    int value = 0;
    std::cin >> value;
    PushBack(deque1, value);
  }
  for (int i = 0; i < 5; ++i) {
    int value = 0;
    std::cin >> value;
    PushBack(deque2, value);
  }
  int cnt = 0;
  if (Game(deque1, deque2, cnt)) {
    if (deque1.size == 0) {
      std::cout << "second " << cnt;
    } else if (deque2.size == 0) {
      std::cout << "first " << cnt;
    }
  } else {
    std::cout << "botva";
  }
  while (deque1.size != 0) {
    PopBack(deque1);
  }
  while (deque2.size != 0) {
    PopBack(deque2);
  }
  return 0;
}

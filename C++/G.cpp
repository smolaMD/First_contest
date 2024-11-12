#include <cstring>
#include <iostream>

struct DNode {
  int value = 0;
  DNode *next = nullptr;
  DNode *prev = nullptr;
};

struct Deque {
  DNode *front = nullptr;
  DNode *back = nullptr;
  size_t size = 0;
};

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
    DNode *tmp_front = deque.front->prev;
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
    auto *node = new DNode;
    node->value = value;
    deque.back = node;
    deque.front = node;
  } else {
    auto *node = new DNode;
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
    DNode *tmp_back = deque.back->next;
    delete deque.back;
    deque.back = tmp_back;
    --deque.size;
  }
}

int Back(Deque &deque) {
  return deque.back->value;
}

struct Node {
  int value = 0;
  Node *prev = nullptr;
};

struct Queue {
  Node *back = nullptr;
  Node *front = nullptr;
  size_t size = 0;
};

void Push(Queue &queue, int &value) {
  auto *node = new Node;
  node->value = value;
  if (queue.size == 0) {
    queue.back = node;
    queue.front = node;
  } else {
    queue.back->prev = node;
    queue.back = node;
  }
  ++queue.size;
}

void Pop(Queue &queue) {
  if (queue.size == 0) {
    return;
  }
  if (queue.size == 1) {
    queue.front = nullptr;
    delete queue.back;
    queue.back = nullptr;
  } else {
    Node *tmp = queue.front->prev;
    delete queue.front;
    queue.front = tmp;
  }
  --queue.size;
}

int Front(Queue &queue) {
  return queue.front->value;
}

int main() {
  int n = 0;
  std::cin >> n;
  Queue queue;
  Deque min_deque;
  for (int i = 0; i < n; ++i) {
    char command[20];
    std::cin >> command;
    if (strcmp(command, "enqueue") == 0) {
      int value = 0;
      std::cin >> value;
      Push(queue, value);
      std::cout << "ok\n";
      while (min_deque.size != 0 && Back(min_deque) > value) {
        PopBack(min_deque);
      }
      PushBack(min_deque, value);
    }
    if (strcmp(command, "dequeue") == 0) {
      if (queue.size == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Front(queue) << '\n';
        if (min_deque.size != 0) {
          if (Front(min_deque) == Front(queue)) {
            PopFront(min_deque);
          }
        }
        Pop(queue);
      }
    }
    if (strcmp(command, "front") == 0) {
      if (queue.size == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Front(queue) << '\n';
      }
    }
    if (strcmp(command, "size") == 0) {
      std::cout << queue.size << '\n';
    }
    if (strcmp(command, "clear") == 0) {
      while (queue.size != 0) {
        if (min_deque.size != 0) {
          if (Front(min_deque) == Front(queue)) {
            PopFront(min_deque);
          }
        }
        Pop(queue);
      }
      std::cout << "ok\n";
    }
    if (strcmp(command, "min") == 0) {
      if (queue.size == 0) {
        std::cout << "error\n";
      } else {
        std::cout << Front(min_deque) << '\n';
      }
    }
  }
  while (queue.size != 0) {
    Pop(queue);
  }
  while (min_deque.size != 0) {
    PopBack(min_deque);
  }
  return 0;
}

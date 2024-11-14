#include <cstring>
#include <iostream>

struct Node {
  int value;
  Node *next;
};

struct Stack {
  Node *head;
  int size = 0;
};

void Push(Stack &stack, int x) {
  ++stack.size;
  if (stack.size == 1) {
    Node *node_ptr = new Node;
    node_ptr->value = x;
    stack.head = node_ptr;
  } else {
    Node *node_ptr = new Node;
    node_ptr->value = x;
    node_ptr->next = stack.head;
    stack.head = node_ptr;
  }
}

int Back(Stack &stack) {
  if (stack.size == 0) {
    return -1;
  }
  return stack.head->value;
}

void Pop(Stack &stack) {
  if (stack.size == 0) {
    return;
  }
  if (stack.size == 1) {
    --stack.size;
    delete stack.head;
    return;
  }
  Node *tmp_ptr = stack.head->next;
  --stack.size;
  delete stack.head;
  stack.head = tmp_ptr;
}

void CountExprassion(Stack &stack, char *exprassion, const size_t exp_len) {
  for (int i = 0; i < static_cast<int>(exp_len); ++i) {
    if (isdigit(exprassion[i])) {
      int arr[100];
      int j = 0;
      while (isdigit(exprassion[i])) {
        arr[j] = (static_cast<int>(exprassion[i]) - 48);
        ++j;
        ++i;
      }
      int mltp = 1;
      int num = 0;
      for (int k = j - 1; k >= 0; --k) {
        num += arr[k] * mltp;
        mltp *= 10;
      }
      Push(stack, num);
    } else if (exprassion[i] == '+') {
      int tmp = Back(stack);
      Pop(stack);
      tmp += Back(stack);
      Pop(stack);
      Push(stack, tmp);
    } else if (exprassion[i] == '-') {
      int tmp = Back(stack);
      Pop(stack);
      tmp = Back(stack) - tmp;
      Pop(stack);
      Push(stack, tmp);
    } else if (exprassion[i] == '*') {
      int tmp = Back(stack);
      Pop(stack);
      tmp *= Back(stack);
      Pop(stack);
      Push(stack, tmp);
    }
  }
}

int main() {
  char exprassion[100];
  std::cin.getline(exprassion, 100);
  Stack stack;
  size_t exp_len = strlen(exprassion);
  CountExprassion(stack, exprassion, exp_len);
  std::cout << Back(stack);
  while (stack.size != 0) {
    Pop(stack);
  }
  return 0;
}

#include <iostream>

struct Node {
  char value;
  Node *next = nullptr;
};

struct Stack {
  Node *head = nullptr;
  size_t size = 0;
};

size_t Size(Stack &stack) {
  return stack.size;
}

void Push(Stack &stack, char x) {
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

char Back(Stack &stack) {
  return stack.head->value;
}

void Pop(Stack &stack) {
  if (stack.size == 0) {
    return;
  }
  if (stack.size == 1) {
    delete stack.head;
    stack.head = nullptr;
    --stack.size;
  } else {
    Node *tmp_ptr = stack.head->next;
    delete stack.head;
    stack.head = tmp_ptr;
    --stack.size;
  }
}

int main() {
  Stack stack;
  int max_size = 100001;
  char *str = new char[max_size];
  std::cin.getline(str, max_size);
  bool flag = true;
  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
      Push(stack, str[i]);
    } else {
      if (Size(stack) == 0) {
        flag = false;
        break;
      }
      char b = Back(stack);
      Pop(stack);
      if ((str[i] == ')' && b != '(') || (str[i] == '}' && b != '{') || (str[i] == ']' && b != '[')) {
        flag = false;
      }
    }
  }
  if (flag && Size(stack) == 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  while (Size(stack) != 0) {
    Pop(stack);
  }
  delete[] str;
  return 0;
}

#pragma once

#include <cstddef>
#include <cstring>

struct Node {
    char* data;
    Node* next;
};

struct Stack {
  Node* head = nullptr;
  std:: size_t size = 0;
};

namespace stack_incide {
inline char* CopyString(const char* str) {
    std::size_t len = std::strlen(str);
    char* copy = new char[len + 1];
    std::memcpy(copy, str, len);
    copy[len] = '\0';
    return copy;
}
}

inline void Push(Stack* stack, const char* str) {
    Node* node = new Node;
    node->data = stack_detail::CopyString(str);
    node->next = stack->head;
    stack->head = node;
    ++stack->size;
}

inline void Pop(Stack* stack) {
    if (stack->head == nullptr) {
        return;
    }
    Node* victim = stack->head;
    stack->head = victim->next;
    delete[] victim->data;
    delete victim;
    --stack->size;
}

inline char* Top(Stack* stack) {
    if (stack->head == nullptr) {
        return nullptr;
    }
    return stack->head->data;
}

inline std::size_t Size(Stack* stack) {
    return stack->size;
}

inline void Clear(Stack* stack) {
    while (stack->head != nullptr) {
        Node* victim = stack->head;
        stack->head = victim->next;
        delete[] victim->data;
        delete victim;
    }
    stack->size = 0;
}

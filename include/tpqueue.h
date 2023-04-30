// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>
#include <utility>
template <typename T>
class TPQueue {
 private:
  std::list <T> list1;
  T CopyObj;
  int head;

 public:
  TPQueue() {
    head = -1;
  }
  bool isEmpty() {
    return head == -1;
  }
  T pop() {
    head = -1;
    auto i = list1.front();
    list1.pop_front();
    return i;
  }
  T top() {
    return list1.front();
  }
  void push(T val) {
    if (head == -1) {
      list1.push_front(val);
      ++head;
    } else {
      CopyObj = list1.front();
      if (CopyObj.prior == val.prior) {
        list1.push_front(val);
        list1.sort(const SYM &val1, const SYM &val2, []() {
          return val1.ch <= val2.ch;
        });
      } else {
        list1.push_front(val);
        list1.sort(const SYM &val1, const SYM &val2 []() {
          return val1.ch <= val2.ch;
        });
      }
      head++;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

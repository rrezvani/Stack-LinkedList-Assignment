#ifndef GENSTACK_H
#define GENSTACK_H
#include "linkedlist.h"
#include <iostream>

using namespace std; //linked list based stack 

template <typename T>
class GenStack {
  public:
    GenStack();
    ~GenStack();
    //core functions
    void push(T data);
    T pop();
    //aux functions
    T peek();
    bool isEmpty();
    bool isFull();
    int getSize();
    void printThing();
  private:
    DoublyLinkedList<T> *dl = new DoublyLinkedList<T>;
};

template <typename T>
GenStack<T>::GenStack() {

}

template <typename T>
GenStack<T>::~GenStack() {
  delete dl;
}

template <typename T>
void GenStack<T>::push(T data) {
  dl->InsertFront(data);
}

template <typename T>
T GenStack<T>::pop() {
  if (isEmpty()) {
    throw runtime_error("There is nothing in your stack!");
  }
  return dl->RemoveFront();
}

template <typename T>
T GenStack<T>::peek() {
  return dl->Peek();
}

template <typename T>
void GenStack<T>::printThing() {
  dl->printList(false);
}

template <typename T>
int GenStack<T>::getSize() {
  return dl->GetSize();
}

template <typename T>
bool GenStack<T>::isEmpty() {
  return dl->IsEmpty();
}

#endif

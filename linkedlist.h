#include <iostream> //list node and doubly linked list implementation from class, I added a peek function as well

using namespace std;

template <typename T> //since we need to make the stack accessible with any data type, we must make it a a template class
class ListNode {
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();
    ListNode *next;
    ListNode *prev;
    T data;
};

template <typename T>
ListNode<T>::ListNode() {

}

template <typename T>
ListNode<T>::ListNode(T d) {
  data = d;
  next = NULL;
  prev = NULL;
}

template <typename T>
ListNode<T>::~ListNode() {
  next = NULL;
  prev = NULL;
}

template <typename T>
class DoublyLinkedList {
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    size_t size;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void InsertFront(T d);
    void InsertBack(T d);
    T RemoveFront();
    T RemoveBack();
    T Remove(T key);
    int Find(T value);
    bool IsEmpty();
    size_t GetSize();
    void printList(bool printLink);
    T Peek();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
  front = NULL;
  back = NULL;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  while (front != NULL) {
    RemoveFront(); //deleting all the nodes in the linked list until there are none left
  }
}

template <typename T>
void DoublyLinkedList<T>::InsertFront(T d) {
  ListNode<T> *node = new ListNode<T>(d);

  if (size == 0) {
    back = node;
  }
  else {
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}

template <typename T>
void DoublyLinkedList<T>::InsertBack(T d) {
  ListNode<T> *node = new ListNode<T>(d);

  if (size == 0) {
    front = node;
  }

  else {
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <typename T>
T DoublyLinkedList<T>::RemoveFront() {
  ListNode<T> *tp = front;

  if (front->next == NULL) {
    back = NULL;
  }
  else {
    front->next->prev = NULL;
  }
  front = front->next;
  tp->next = NULL;
  T temp = tp->data;
  size--;
  delete tp;
  return temp;
}

template <typename T>
T DoublyLinkedList<T>::RemoveBack() {
  ListNode<T> *tp = back;

  if (back->prev == NULL) {
    front = NULL;
  }
  else {
    back->prev->next = NULL;
  }
  back = back->prev;
  tp->prev = NULL;
  T temp = tp->data;
  size--;
  delete tp;
  return temp;
}

template <typename T>
int DoublyLinkedList<T>::Find(T value) {
  int index = -1;
  ListNode<T> *currentNode = front;

  while (currentNode != NULL) {
    ++index;
    if (currentNode->data == value) {
      break;
    }
    else {
      currentNode = currentNode->next;
    }
  }
  if (currentNode == NULL) {
    index = -1;
  }
  delete currentNode;
  return index;
}

template <typename T>
T DoublyLinkedList<T>::Remove(T key) {
  ListNode<T> *currentNode = front;

  while (currentNode->data != key) {
    currentNode = currentNode->next;

    if (currentNode == NULL) {
      return 0;
    }
  }

  if (currentNode == front) {
    front = currentNode->next;
    front->prev = NULL;
  }

  if (currentNode == back) {
    back = currentNode->prev;
    back->next = NULL;
  }

  if (currentNode != front && currentNode != back) {
    currentNode->next->prev = currentNode->prev;
    currentNode->prev->next = currentNode->next;
  }

  currentNode->next = NULL;
  currentNode->prev = NULL;
  T temp = currentNode->data;
  size--;
  delete currentNode;
  return temp;
}

template <typename T>
size_t DoublyLinkedList<T>::GetSize() {
  return size;
}

template <typename T>
bool DoublyLinkedList<T>::IsEmpty() {
  if (size == 0) {
    return true;
  }
  return false;
}

template <typename T>
T DoublyLinkedList<T>::Peek() {
  return front->data; //simply returns the data of the top value
}

template <typename T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode<T> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";

       curr = curr->next;
       if(curr != 0){
         cout << " ==> ";
       }
    }
    cout << endl;
}

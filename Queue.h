#ifndef WEEK8_QUEUE_H
#define WEEK8_QUEUE_H

template<class T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;

        Node(T anElement, Node* aNextPointer = nullptr) {
            element = anElement;
            next = aNextPointer;
        }
    };

    Node* front;
    Node* back;
    int numNodes;

public:
    Queue();
    ~Queue();
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    void clear();
};

//************************************************
// Constructor                                   *
//************************************************
template <class T>
Queue<T>::Queue() {
    front = nullptr;
    back = nullptr;
    numNodes = 0;
}

//************************************************
// Destructor                                    *
//************************************************
template <class T>
Queue<T>::~Queue() {
    clear();
}

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************
template <class T>
void Queue<T>::enqueue(T num) {
    Node *newNode = new Node(num);
    if (isEmpty()) {
        front = newNode;
        back = newNode;
    }
    else {
        back->next = newNode;
        back = newNode;
    }
    ++numNodes;
}

//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************
template <class T>
void Queue<T>::dequeue(T& num) {
    if (!isEmpty()) {
        Node* nodePtr = nullptr;
        num = front->element;
        nodePtr = front->next;
        delete front;
        front = nodePtr;
        --numNodes;
    }
    else {
        std::cout << "Queue is empty" << std::endl;
    }
}

//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************
template <class T>
bool Queue<T>::isEmpty() {
    if (numNodes == 0) {
        return true;
    }
    return false;
}

//************************************************
// Function clear dequeues all the elements      *
// in the queue.                                 *
//************************************************
template <class T>
void Queue<T>::clear() {
    T value;
    while (!isEmpty()) {
        dequeue(value);
    }
    front = nullptr;
    back = nullptr;
}

#endif //WEEK8_QUEUE_H

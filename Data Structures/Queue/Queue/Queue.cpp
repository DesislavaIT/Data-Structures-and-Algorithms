#include "Queue.hpp"
#include <iostream>

using namespace std;

void Queue::copy(const Queue& rhs)
{
    Node* curr = rhs.front;
    while (curr != nullptr)
    {
        push(curr->data);
        curr = curr->previous;
    }
}

void Queue::free()
{
    while(front != nullptr)
    {
        Node* previous = front->previous;
        delete front;
        front = previous;
    }
}

Queue::Queue(const Queue& rhs)
{
    copy(rhs);
}

Queue& Queue::operator=(const Queue& rhs)
{
    if (this != &rhs)
    {
        free();
        copy(rhs);
    }
    
    return *this;
}

Queue::~Queue()
{
     free();
}

void Queue::push(int number)
{
    if (isEmpty())
    {
        front = new Node(number);
        back = front;
    }
    else
    {
        back->previous = new Node(number);
        back = back->previous;
    }
}

void Queue::pop()
{
    if (!isEmpty())
    {
        Node* oldFront = front;
        front = front->previous;
        delete oldFront;
    }
    else
    {
        cout << "Queue is empty" << endl;
    }
}

int Queue::peek() const
{
    if (!isEmpty())
    {
        return front->data;
    }
    else
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
}

bool Queue::isEmpty() const
{
    return front == nullptr;
}

int main() {
    Queue s;
    s.push(1);
    s.push(2);
    s.push(3);

    Queue d(s);
    while (!d.isEmpty())
    {
        cout << d.peek();
        d.pop();
    }
}

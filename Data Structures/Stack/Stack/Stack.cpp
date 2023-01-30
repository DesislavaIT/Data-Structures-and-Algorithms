#include "Stack.hpp"
#include <iostream>

using namespace std;

void Stack::_copyStackRecursive(Node* current)
{
    if (current != nullptr)
    {
        _copyStackRecursive(current->previous);
        push(current->data);
    }
}

void Stack::copyStack(const Stack& rhs)
{
    _copyStackRecursive(rhs.top);
}

void Stack::free() {
    while(top != nullptr)
    {
        Node* previous = top->previous;
        delete top;
        top = previous;
    }
}

Stack::Stack(const Stack& rhs)
{
    copyStack(rhs);
}

Stack& Stack::operator=(const Stack& rhs)
{
    if (this != &rhs)
    {
        free();
        copyStack(rhs);
    }
    
    return *this;
}

Stack::~Stack()
{
    free();
}

void Stack::push(int number)
{
    if (isEmpty())
    {
        top = new Node(number);
    }
    else
    {
        Node* newTop = new Node(number, top);
        top = newTop;
    }
}

void Stack::pop()
{
    if (!isEmpty())
    {
        Node* oldTop = top;
        top = top->previous;
        delete oldTop;
    }
    else
    {
        cout << "Stack is empty";
    }
}

int Stack::peek() const
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        cout << "Stack is empty";
        return 0;
    }
}

bool Stack::isEmpty() const
{
    return top == nullptr;
}


int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    Stack d(s);
    while (!d.isEmpty())
    {
        cout << d.peek();
        d.pop();
    }
}

#include "SinglyLinkedList.hpp"
#include <iostream>

using namespace std;

void SinglyLinkedList::free()
{
    if(head != nullptr)
    {
        SLL_Node* previous = head;
        SLL_Node* current = head->next;
        while(current != nullptr)
        {
            delete previous;
            previous = current;
            current = current->next;
        }
        
        delete previous;
        head = nullptr;
        tail = nullptr;
    }
}

void SinglyLinkedList::copy(const SinglyLinkedList& rhs)
{
    SLL_Node* node = rhs.head;
    while(node != nullptr)
    {
        AddAtEnd(node->value);
        node = node->next;
    }
}

SinglyLinkedList::SinglyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& rhs)
{
    copy(rhs);
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& rhs)
{
    if (this != &rhs)
    {
        free();
        copy(rhs);
    }
    
    return *this;
}

SinglyLinkedList::~SinglyLinkedList()
{
    free();
}

void SinglyLinkedList::AddAtEnd(int data)
{
    SLL_Node* node = new SLL_Node(data);
    if(head == nullptr)
    {
        head = node;
        tail = node;
        return;
    }
    
    tail->next = node;
    tail = node;
}

void SinglyLinkedList::AddAtBeginning(int data)
{
    SLL_Node* node = new SLL_Node(data);
    if(head == nullptr)
    {
        head = node;
        tail = node;
        return;
    }
    
    node->next = head;
    head = node;
}

void SinglyLinkedList::AddAtPosition(int data, int position)
{
    if(position == 0)
    {
        AddAtBeginning(data);
    }
    else
    {
        int counter = 1;
        SLL_Node* node = new SLL_Node(data);
        SLL_Node* previous = head;
        SLL_Node* current = head->next;
        while(counter < position)
        {
            if(current == nullptr)
            {
                cout << "Index out of bounds!\n";
                return;
            }
            
            previous = current;
            current = current->next;
            counter++;
        }
        
        previous->next = node;
        node->next = current;
        if(tail == previous)
        {
            tail = previous->next;
        }
    }
}

void SinglyLinkedList::DeleteAtEnd()
{
    if(head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }
    else if(head == tail)
    {
        delete head;
        return;
    }
    
    SLL_Node* previous = head;
    SLL_Node* current = head->next;
    while(current->next != nullptr)
    {
        previous = current;
        current = current->next;
    }
    
    previous->next = nullptr;
    tail = previous;
    delete current;
}

void SinglyLinkedList::DeleteAtBeginning()
{
    if(head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }
    else if(tail == head)
    {
        tail = nullptr;
    }
    
    SLL_Node* current = head;
    head = head->next;
    delete current;
}

void SinglyLinkedList::DeleteAtPosition(int position)
{
    if(head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }
    else if(position == 0)
    {
        DeleteAtBeginning();
        return;
    }
    
    int counter = 1;
    SLL_Node* previous = head;
    SLL_Node* current = head->next;
    while(counter < position)
    {
        if(current == nullptr)
        {
            cout << "Index out of bounds!\n";
            return;
        }
        
        previous = current;
        current = current->next;
        counter++;
    }
    
    if(current == nullptr)
    {
        cout << "Index out of bounds!\n";
        return;
    }
    
    previous->next = current->next;
    if(tail == current)
    {
        tail = previous;
    }
    
    delete current;
}

void SinglyLinkedList::Reverse()
{
    if(head == nullptr || head == tail)
    {
        return;
    }
    
    SLL_Node* first = head;
    SLL_Node* second = first->next;
    SLL_Node* third = second->next;
    first->next = nullptr;
    head = tail;
    tail = first;
    
    while(third != nullptr)
    {
        second->next = first;
        first = second;
        second = third;
        third = third->next;
    }
    
    second->next = first;
}

void SinglyLinkedList::Print() const
{
    if(head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }
    
    SLL_Node* current = head;
    while(current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    
    cout << "\n";
}

bool SinglyLinkedList::Search(int data) const
{
    if(head == nullptr)
    {
        return false;
    }
    
    SLL_Node* current = head;
    while(current != nullptr)
    {
        if(current->value == data)
        {
            return true;
        }
        
        current = current->next;
    }
    
    return false;
}

int main() {
    SinglyLinkedList l;
    l.AddAtPosition(0, 0);
    l.AddAtPosition(1, 1);
    l.AddAtPosition(2, 2);
    l.AddAtPosition(3, 3);
    l.Print();
}

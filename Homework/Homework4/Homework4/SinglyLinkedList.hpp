#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

struct SLL_Node
{
    int value;
    SLL_Node* next;
    SLL_Node(int data)
    {
        value = data;
        next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    SLL_Node* head;
    SLL_Node* tail;
    void free();
    void copy(const SinglyLinkedList&);
public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList&);
    SinglyLinkedList& operator=(const SinglyLinkedList&);
    ~SinglyLinkedList();
    void AddAtEnd(int);
    void AddAtBeginning(int);
    void AddAtPosition(int, int);
    void DeleteAtEnd();
    void DeleteAtBeginning();
    void DeleteAtPosition(int);
    void Reverse();
    void Print() const;
    bool Search(int) const;
};

#endif

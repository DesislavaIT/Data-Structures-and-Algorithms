#ifndef Queue_hpp
#define Queue_hpp

struct Node {
    int data;
    Node* previous = nullptr;

    Node(int data, Node* previous = nullptr)
    {
        this->data = data;
        this->previous = previous;
    }
};

class Queue
{
private:
    Node* front = nullptr;
    Node* back = nullptr;
    
    void copy(const Queue&);
    void free();
public:
    Queue() = default;
    Queue(const Queue&);
    Queue& operator=(const Queue&);
    ~Queue();
    void push(int);
    void pop();
    int peek() const;
    bool isEmpty() const;
};

#endif

#ifndef Stack_hpp
#define Stack_hpp

struct Node {
    int data;
    Node* previous = nullptr;

    Node(int data, Node* previous = nullptr)
    {
        this->data = data;
        this->previous = previous;
    }
};

class Stack {
private:
    Node* top = nullptr;
    
    void _copyStackRecursive(Node*);
    void copyStack(const Stack&);
    void free();
public:
    Stack() = default;
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    ~Stack();
    void push(int);
    void pop();
    int peek() const;
    bool isEmpty() const;
};

#endif

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

struct Node
{
    Node *left;
    Node *right;
    int value;
    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST
{
private:
    Node* root;

    Node* findRecursive(Node*, int) const;
    Node* insertRecursive(Node*, int);
    Node* removeRecursive(Node*, int);
    void printSorted(Node*) const;
    Node* findMax(Node*) const;
    Node* findMin(Node*) const;
    Node* lowerBound(Node*, int) const;
public:
    BST() = default;
    void insert(int);
    void remove(int);
    bool exists(int) const;
    int findMin() const;
    int findMax() const;
    int lowerBound(int) const;
    void printSorted() const;
};

#endif

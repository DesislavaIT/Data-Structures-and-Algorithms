#include "BinarySearchTree.hpp"
#include <iostream>

using namespace std;

Node* BST::findRecursive(Node* curNode, int value) const
{
    if(curNode == nullptr)
        return nullptr;
    
    if(curNode->value == value)
        return curNode;
    
    if(curNode->value < value)
        return findRecursive(curNode->right, value);
    
    return findRecursive(curNode->left, value);
}

Node* BST::insertRecursive(Node *curNode, int value)
{
    if(curNode == nullptr)
    {
        return new Node(value);
    }
    
    if(curNode->value < value)
    {
        curNode->right = insertRecursive(curNode->right, value);
    }
    
    else
    {
        curNode->left = insertRecursive(curNode->left, value);
    }
    
    return curNode;
}

Node* BST::removeRecursive(Node* curNode, int value)
{
    if(curNode == nullptr)
    {
        return nullptr;
    }
    
    if(curNode->value < value)
    {
        curNode->right = removeRecursive(curNode->right, value);
    }
    else if(curNode->value > value)
    {
        curNode->left = removeRecursive(curNode->left, value);
    }
    else
    {
        if(curNode->left == nullptr)
        {
            Node* tmp = curNode->right;
            delete curNode;
            return tmp;
        }
        
        Node* maxInLeftSubTree = findMax(curNode->left);
        curNode->value = maxInLeftSubTree->value;
        curNode->left = removeRecursive(curNode->left, curNode->value);
    }
    
    return curNode;
}

void BST::printSorted(Node *root) const
{
    if(root == nullptr)
    {
        return;
    }
    
    printSorted(root->left);
    cout<<root->value<<" ";
    printSorted(root->right);
}

Node* BST::findMax(Node *root) const
{
    if(root->right != nullptr)
    {
        return findMax(root->right);
    }
    
    return root;
}

Node* BST::findMin(Node *root) const
{
    if(root->left != nullptr)
    {
        return findMin(root->left);
    }
    
    return root;
}

Node* BST::lowerBound(Node* root, int value) const
{
    if(root == nullptr)
    {
        return nullptr;
    }
    else if(root->value == value)
    {
        return root;
    }
    else if(root->value < value)
    {
        return lowerBound(root->right, value);
    }
    else
    {
        Node* tmp = lowerBound(root->left, value);
        if(tmp != nullptr)
            return tmp;
        else
            return root;
    }
}

void BST::insert(int value)
{
    if(root == nullptr)
    {
        root = new Node(value);
    }
    else
    {
        insertRecursive(root, value);
    }
}

void BST::remove(int value)
{
    root = removeRecursive(root, value);
}

bool BST::exists(int value) const
{
    return findRecursive(root, value) != nullptr;
}

int BST::findMin() const
{
    if(root == nullptr)
        return -1;
    
    return findMin(root)->value;
}

int BST::findMax() const
{
    if(root == nullptr)
        return -1;
    
    return findMax(root)->value;
}

int BST::lowerBound(int value) const
{
    Node* lb = lowerBound(root, value);
    if(lb == nullptr)
        return -1;
    else
        return lb->value;
}

void BST::printSorted() const
{
    printSorted(root);
}

int main()
{
    //Some tests
    return 0;
}

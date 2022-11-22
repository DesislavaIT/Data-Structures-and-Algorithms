#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

//class Node {
//    public:
//        int data;
//        Node *leftNode;
//        Node *rightNode;
//        Node(int d) {
//            data = d;
//            leftNode = NULL;
//            rightNode = NULL;
//        }
//};
//
//class Solution {
//    public:
//          Node* insert(Node* root, int data) {
//            if(root == NULL) {
//                return new Node(data);
//            } else {
//                Node* cur;
//                if(data <= root->data) {
//                    cur = insert(root->leftNode, data);
//                    root->leftNode = cur;
//                } else {
//                    cur = insert(root->rightNode, data);
//                    root->rightNode = cur;
//               }
//
//               return root;
//           }
//        }
//
//
//    void leaves(Node *root) {
//        int sum = 0;
//        list<Node*> l;
//        l.push_front(root);
//        while(l.size() > 0)
//        {
//            Node* curr = l.front();
//            l.pop_front();
//            if(curr->leftNode == nullptr && curr->rightNode == nullptr)
//            {
//                if(curr->data % 2 == 1)
//                {
//                    sum += curr->data;
//                }
//            }
//
//            if(curr->rightNode != nullptr)
//            {
//                l.push_front(curr->rightNode);
//            }
//
//            if(curr->leftNode != nullptr)
//            {
//                l.push_front(curr->leftNode);
//            }
//        }
//
//        cout << sum;
//    }
//
//
//}; //End of Solution
//
//int main() {
//
//    Solution myTree;
//    Node* root = NULL;
//
//    int t;
//    int data;
//
//    std::cin >> t;
//
//    while(t-- > 0) {
//        std::cin >> data;
//        root = myTree.insert(root, data);
//    }
//
//    myTree.leaves(root);
//    return 0;
//}

struct Node{
    Node *left;
    Node *right;
    int value;
    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{

public:
    BST(){
        root = NULL;
    }
    void insert(int value){
        root = insert(root, value);
    }

    void printSpecific(int dividedBy){
        Helper(root, dividedBy);
    }

private:
    // you can implemented helper functions if you want
    void Helper(Node* root, int dividedBy)
    {
        if(root->value % dividedBy == 0 && (root->left != nullptr || root->right != nullptr))
        {
            cout << root->value << ' ';
        }
        
        if(root->left != nullptr)
        {
            Helper(root->left, dividedBy);
        }
        
        if(root->right != nullptr)
        {
            Helper(root = root->right, dividedBy);
        }
    }

    Node* root;

    Node* insert(Node *curNode, int value){
        if(curNode == NULL){
            curNode =  new Node(value);
        }else if(curNode->value < value){
            curNode->right = insert(curNode->right, value);
        }else if(curNode->value > value){
            curNode->left = insert(curNode->left, value);
        }else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
      cin >> n;
      int value;
      BST tree;
      for(int i = 0 ; i < n; i++){
      cin >> value;
      tree.insert(value);
    }
      int dividedBy;
      cin >> dividedBy;
      tree.printSpecific(dividedBy);
    return 0;
}

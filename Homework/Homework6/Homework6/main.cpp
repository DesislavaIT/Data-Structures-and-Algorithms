#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct SkiNode
{
    long long value;
    int x;
    int y;
    int leftY;
    int rightY;
    SkiNode* left = nullptr;
    SkiNode* right = nullptr;
};

void inOrderTraversal(SkiNode* node)
{
    if(node != nullptr)
    {
        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }
}

void CalculateRowSum(SkiNode* node, int minLeftIndex, vector<long long>& arr)
{
    if(node != nullptr)
    {
        CalculateRowSum(node->left, minLeftIndex, arr);
        arr[node->x + minLeftIndex] += node->value;
        CalculateRowSum(node->right, minLeftIndex, arr);
    }
}

SkiNode arr[1000000];

void Problem1()
{
    int N;
    cin >> N;
    
    //Initialize root
    int counter = 0;
    SkiNode* root = &arr[counter++];
    root->x = 0;
    root->y = 0;
    cin >> root->value;
    cin >> root->leftY;
    cin >> root->rightY;
    int minLeftIndex = root->x;
    int maxRightIndex = root->x;
    
    queue<SkiNode*> q;
    q.push(root);
    
    for(int i = 1; i < N; i += 2)
    {
        SkiNode* r = q.front();
        q.pop();
        if(minLeftIndex > r->x)
        {
            minLeftIndex = r->x;
        }
        
        if(maxRightIndex < r->x)
        {
            maxRightIndex = r->x;
        }
        
        SkiNode* node1 = &arr[counter++];
        node1->x = r->x - 1;
        node1->y = r->leftY;
        cin >> node1->value;
        cin >> node1->leftY;
        cin >> node1->rightY;
        r->left = node1;
        q.push(node1);
    
        SkiNode* node2 = &arr[counter++];
        node2->x = r->x + 1;
        node2->y = r->rightY;
        cin >> node2->value;
        cin >> node2->leftY;
        cin >> node2->rightY;
        r->right = node2;
        q.push(node2);
    }
    
    while(q.size() > 0)
    {
        SkiNode* r = q.front();
        q.pop();
        if(minLeftIndex > r->x)
        {
            minLeftIndex = r->x;
        }
        
        if(maxRightIndex < r->x)
        {
            maxRightIndex = r->x;
        }
    }
    
    minLeftIndex *= -1;
    vector<long long> sums(minLeftIndex + maxRightIndex + 1);
    CalculateRowSum(root, minLeftIndex, sums);
    for(int i = 0; i < minLeftIndex + maxRightIndex + 1; i++)
    {
        if(sums[i] != 0)
        {
            cout << sums[i] << ' ';
        }
    }
}

void inOrderTraversal(SkiNode* node, vector<long long>& v)
{
    if(node != nullptr)
    {
        inOrderTraversal(node->left, v);
        v.push_back(node->value);
        inOrderTraversal(node->right, v);
    }
}

void Problem2()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        
        int counter = 0;
        vector<SkiNode> arr2(N);
        SkiNode* root = &arr2[counter++];
        root->x = 0;
        root->y = 0;
        cin >> root->value;
        cin >> root->leftY;
        cin >> root->rightY;
        
        queue<SkiNode*> q;
        q.push(root);
        
        for(int i = 1; i < N; i += 2)
        {
            SkiNode* r = q.front();
            q.pop();
            
            while(r->leftY == -1 && r->rightY == -1)
            {
                r = q.front();
                q.pop();
            }
            
            if(r->leftY != -1)
            {
                SkiNode* node1 = &arr2[counter++];
                node1->x = r->x - 1;
                node1->y = r->leftY;
                cin >> node1->value;
                cin >> node1->leftY;
                cin >> node1->rightY;
                r->left = node1;
                q.push(node1);
            }
            else
            {
                i--;
            }
            
            if(i == N)
            {
                break;
            }
            
            if(r->rightY != -1)
            {
                SkiNode* node2 = &arr2[counter++];
                node2->x = r->x + 1;
                node2->y = r->rightY;
                cin >> node2->value;
                cin >> node2->leftY;
                cin >> node2->rightY;
                r->right = node2;
                q.push(node2);
            }
            else
            {
                i--;
            }
        }
        
        vector<long long> v;
        inOrderTraversal(root, v);
        
        bool ans = true;
        for(int j = 0; j < v.size() - 1; j++)
        {
            if(v[j] >= v[j + 1])
            {
                ans = false;
                break;
            }
        }
        
        if(ans)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}

struct Node
{
    int value;
    Node* parent;
};

void Problem3()
{
    int N;
    cin >> N;
    vector<Node> arr3(N);
    for(int i = 0; i < N - 1; i++)
    {
        int father, child;
        cin >> father >> child;
        Node* f = &arr3[father];
        Node* ch = &arr3[child];
        f->value = father;
        ch->value = child;
        ch->parent = f;
    }
    
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        Node* iter = &arr3[y];
        bool ans = false;
        while(iter->parent != nullptr && iter->value > x)
        {
            if(iter->parent->value == x)
            {
                ans = true;
                break;
            }
            
            iter = iter->parent;
        }
        
        if(ans)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}

struct StringNode
{
    string value;
    StringNode* left = nullptr;
    StringNode* right = nullptr;
};

StringNode arr1[1000000];
int counter = 0;

StringNode* insert(StringNode* root, string key)
{
    if (root == nullptr)
    {
        StringNode* node = &arr1[counter++];
        node->value = key;
        return node;
    }
    
    if (key < root->value)
        root->left = insert(root->left, key);
    else if (key > root->value)
        root->right = insert(root->right, key);
    
    return root;
}

bool contains(StringNode* root, string key)
{
    if (root->value == key)
    {
        return true;
    }
    
    if (key < root->value && root->left != nullptr)
        return contains(root->left, key);
    else if (key > root->value && root->right != nullptr)
        return contains(root->right, key);
    
    return false;
}

void Problem4()
{
    int N;
    cin >> N;
    
    //Initialize root
    StringNode* root = &arr1[counter++];
    cin >> root->value;
    
    for(int i = 1; i < N; i++)
    {
        string key;
        cin >> key;
        insert(root, key);
    }
    
    int Q;
    cin >> Q;
    vector<string> words(N);
    for(int i = 0; i < Q; i++)
    {
        cin >> words[i];
    }
    
    for(int i = 0; i < Q; i++)
    {
        if(contains(root, words[i]))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem4();
    return 0;
}

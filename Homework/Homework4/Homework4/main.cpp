#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if(llist == nullptr)
    {
        return llist;
    }
    else if(position == 0)
    {
        SinglyLinkedListNode* current = llist;
        llist = llist->next;
        delete current;
        return llist;
    }
    
    int counter = 1;
    SinglyLinkedListNode* previous = llist;
    SinglyLinkedListNode* current = llist->next;
    while(counter < position)
    {
        if(current == nullptr)
        {
            return llist;
        }
        
        previous = current;
        current = current->next;
        counter++;
    }
    
    if(current == nullptr)
    {
        return llist;
    }
    
    previous->next = current->next;
    delete current;
    
    return llist;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    vector<SinglyLinkedListNode*> v1;
    vector<SinglyLinkedListNode*> v2;
    SinglyLinkedListNode* current = head1;
    while(current != nullptr)
    {
        v1.push_back(current);
        current = current->next;
    }

    current = head2;
    while(current != nullptr)
    {
        v2.push_back(current);
        current = current->next;
    }
    int result = 0;
    
    for(unsigned long int i = v1.size() - 1, j = v2.size() - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(v1[i] != v2 [j])
        {
            result = v1[i + 1]->data;
            break;
        }
    }
    
    return result;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    if(llist == nullptr)
    {
        llist = node;
    }
    else
    {
        if(position == 0)
        {
            node->next = llist;
            llist = node;
        }
        else
        {
            SinglyLinkedListNode* previous = llist;
            SinglyLinkedListNode* current = llist->next;
            int counter = 1;
            while(counter < position)
            {
                previous = current;
                current = current->next;
                counter++;
            }
            
            previous->next = node;
            node->next = current;
        }
    }
    
    return llist;
}

struct Node
{
    int value;
    int index;
    Node* previous;
    Node* next;
};

void Problem4()
{
    int T, N;
    cin >> T >> N;
    vector<int> list;
    vector<Node> v(100001);
    for(int i = 0; i < 100001; i++)
    {
        v[i].value = 0;
        v[i].index = i;
    }
    
    Node* head;
    Node* tail;
    int listCounter = 0;
    int element;
    for(int i = 0; i < T; i++)
    {
        cin >> element;
        if(v[element].value == 0)
        {
            v[element].value = 1;
            cout << "false\n";
            if(listCounter == N)
            {
                if(head == tail)
                {
                    v[head->index].value = 0;
                    head = &v[element];
                    tail = head;
                    continue;
                }
                
                v[head->index].value = 0;
                head = head->next;
                head->previous->next = nullptr;
                head->previous = nullptr;
                tail->next = &v[element];
                v[element].previous = tail;
                tail = tail->next;
                tail->next = nullptr;
            }
            else
            {
                if(listCounter == 0)
                {
                    head = &v[element];
                    tail = head;
                }
                else
                {
                    tail->next = &v[element];
                    v[element].previous = tail;
                    tail = tail->next;
                    tail->next = nullptr;
                }
                
                listCounter++;
            }
        }
        else if(head != tail)
        {
            cout << "true\n";
            if(head == &v[element])
            {
                head = head->next;
            }
            else
            {
                v[element].previous->next = v[element].next;
            }
            
            if(tail == &v[element])
            {
                tail = tail->previous;
            }
            else
            {
                v[element].next->previous = v[element].previous;
            }
            
            tail->next = &v[element];
            v[element].previous = tail;
            tail = tail->next;
            tail->next = nullptr;
        }
    }
}

struct Ball
{
    int number;
    int color;
    Ball* previous;
    Ball* next;
};

Ball* head;
Ball* tail;

int deleteBalls(Ball* middle)
{
    int result = 0;
    Ball* start = middle;
    int colors = 1;
    while(start->previous != nullptr && start->color == start->previous->color)
    {
        colors++;
        start = start->previous;
    }
    
    Ball* end = middle;
    while(end->next != nullptr && end->color == end->next->color)
    {
        colors++;
        end = end->next;
    }
    
    Ball* left = start->previous;
    Ball* right = end->next;
    
    if(colors >= 3)
    {
        if(start == head)
        {
            head = end->next;
        }
        else
        {
            start->previous->next = end->next;
        }
        
        if(end == tail)
        {
            tail = start->previous;
        }
        else
        {
            end->next->previous = start->previous;
        }
        
        Ball* current = start;
        while(current != end)
        {
            current->previous = nullptr;
            current = current->next;
            current->previous->next = nullptr;
        }
        
        end->previous = nullptr;
        end->next = nullptr;
        
        result += colors;
        
        if(left != nullptr && right != nullptr && left->color == right->color)
        {
            result += deleteBalls(left);
        }
        
        return result;
    }
    else
    {
        return result;
    }
}

void Problem5()
{
    int N;
    cin >> N;
    vector<Ball> balls(500000);
    for(int i = 0; i < N; i++)
    {
        balls[i].number = i;
        cin >> balls[i].color;
        if(i != 0 && i != N - 1)
        {
            balls[i].previous = &balls[i - 1];
            balls[i].next = &balls[i + 1];
            balls[i - 1].next = &balls[i];
            balls[i + 1].previous = &balls[i];
        }
    }
    int count = N;
    head = &balls[0];
    tail = &balls[count - 1];
    
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int number, color;
        cin >> number >> color;
        if(head == nullptr)
        {
            cout << "Game Over\n";
            continue;
        }
        
        balls[count].number = count;
        balls[count].color = color;
        
        if(tail != &balls[number])
        {
            balls[number].next->previous = &balls[count];
            balls[count].next = balls[number].next;
            balls[count].previous = &balls[number];
            balls[number].next = &balls[count];
        }
        else
        {
            balls[count].next = balls[number].next;
            balls[count].previous = &balls[number];
            balls[number].next = &balls[count];
            tail = &balls[count];
        }
        
        cout << deleteBalls(&balls[count]) << "\n";
        
        count++;
    }
    
    if(head == nullptr)
    {
        cout << -1;
    }
    else
    {
        Ball* current = head;
        while(current != nullptr)
        {
            cout << current->color << " ";
            current = current->next;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem5();
    return 0;
}

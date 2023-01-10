#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <climits>

using namespace std;

void BFS(int v, map<int, int>& m, vector<vector<long long>>& graph, int componentNumber, vector<bool>& visited)
{
    list<int> queue;
    visited[v] = true;
    queue.push_back(v);
    m.insert({v, componentNumber});
    while(!queue.empty())
    {
        v = queue.front();
        queue.pop_front();
 
        for (auto adjecent = graph[v].begin(); adjecent != graph[v].end(); adjecent++)
        {
            if (!visited[*adjecent])
            {
                visited[*adjecent] = true;
                m.insert({*adjecent, componentNumber});
                queue.push_back(*adjecent);
            }
        }
    }
}

void Problem1()
{
    long long N, M;
    cin >> N >> M;
    vector<vector<long long>> graph(N); //vertex, children
    for(long long i = 0; i < M; i++)
    {
        long long vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1 - 1].push_back(vertex2 - 1);
        graph[vertex2 - 1].push_back(vertex1 - 1);
    }
    
    long long K;
    cin >> K;
    
    map<int, int> components;
    vector<bool> visited(graph.size(),false);
    int component = 1;
    for(int i = 0; i < graph.size(); i++)
    {
        if(!visited[i])
        {
            BFS(i, components, graph, component, visited);
            component++;
        }
    }
    
    for(long long i = 0; i < K; i++)
    {
        long long vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        cout << (components[vertex1 - 1] == components[vertex2 - 1]) << ' ';
    }
}

void TopologicalSortHelper(char v, vector<bool>& visited, stack<char>& s, map<char, vector<char>>& graph)
{
    visited[(int)v - 'a'] = true;
  
    for (auto i = graph[v].begin(); i != graph[v].end(); i++)
    {
        if (!visited[(int)*i - 'a'])
        {
            TopologicalSortHelper(*i, visited, s, graph);
        }
    }
        
    s.push(v);
}
  
void TopologicalSort(map<char, vector<char>>& graph)
{
    stack<char> s;
    vector<bool> visited(26, false);
    for (int i = 0; i < 26; i++)
    {
        if ((!visited[i]) && (graph.find((char)(i + 97)) != graph.end()))
        {
            TopologicalSortHelper((char)(i + 97), visited, s, graph);
        }
    }
        
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

void Problem2()
{
    int N;
    cin >> N;
    vector<string> input(N);
    for(int i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    
    map<char, vector<char>> graph;
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < input[i].length() && j < input[i + 1].length(); j++)
        {
            if(input[i][j] != input[i + 1][j])
            {
                graph[input[i][j]].push_back(input[i + 1][j]);
                if(graph.find(input[i + 1][j]) == graph.end())
                {
                    vector<char> v;
                    graph.insert({input[i + 1][j], v});
                }
                break;
            }
        }
    }
    
    TopologicalSort(graph);
}

void BFS2(long long v, long long N, vector<bool>& visited, vector<long long>& result, long long counter, set<pair<long long, long long>>& pairs)
{
    queue<long long> queue;
    visited[v] = true;
    queue.push(v);
    result[v] = counter;
    long long visitedCount = 1;
    while(!queue.empty() && visitedCount < N)
    {
        int size = queue.size();
        counter++;
 
        for(int j = 0; j < size; j++)
        {
            v = queue.front();
            queue.pop();
            for (long long i = 0; i < N; i++)
            {
                if (!visited[i] && i != v && pairs.find({v, i}) == pairs.end())
                {
                    visited[i] = true;
                    visitedCount++;
                    queue.push(i);
                    result[i] = counter;
                    
                }
                
                if(visitedCount == N)
                    break;
            }
        }
    }
}

void Problem3()
{
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> graph(N);
        set<pair<int, int>> pairs;
        for(int j = 0; j < M; j++)
        {
            int vertex1, vertex2;
            cin >> vertex1 >> vertex2;
            vertex1--;
            vertex2--;
            pairs.insert({vertex1, vertex2});
            pairs.insert({vertex2, vertex1});
        }
        
        int K;
        cin >> K;
        K--;
        vector<bool> visited(graph.size(), false);
        vector<int> result(graph.size());
        int counter = 0;
        BFS2(K, graph, visited, result, counter, pairs);
        for(int j = 0; j < result.size(); j++)
        {
            if(j != K)
            {
                cout << (result[j] == 0 ? -1 : result[j]) << ' ';
            }
        }
        
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}

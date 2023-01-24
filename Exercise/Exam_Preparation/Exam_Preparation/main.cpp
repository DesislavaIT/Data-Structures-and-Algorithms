#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void Pancakes() //medium
{
    long long pancakesCount, cookersCount;
    cin >> pancakesCount >> cookersCount;

    vector<int> initialCookers(cookersCount);
    for (int i = 0; i < cookersCount; ++i) {
        cin >> initialCookers[i];
    }

    long long start = 1;
    long long end = 1e17;
    long long answer = 0;
    while (start <= end) {
        long long middle = (end + start) / 2;

        long long currentPancakes = 0;
        for (int initialCooker : initialCookers) {
            currentPancakes += middle / initialCooker;

            if (currentPancakes >= pancakesCount) {
                break;
            }
        }

        if (currentPancakes >= pancakesCount) {
            answer = middle;
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }

    cout << answer;
}
//new problem
void SmallerNumbersCount() //easy
{
    int N, M;
    cin >> N >> M;
    vector<long long> v1(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v1[i];
    }
    
    sort(v1.begin(), v1.end());
    vector<long long> v2(M);
    for(int i = 0; i < M; i++)
    {
        cin >> v2[i];
        int l = 0;
        int r = N - 1;
        int answer = 0;
        if(v1[r] < v2[i])
        {
            cout << N << ' ';
            continue;
        }
        
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(v1[mid] >= v2[i])
            {
                r = mid - 1;
                answer = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        cout << answer << ' ';
    }
}
//new problem
void LongestSubArray() //medium
{
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    
    set<int> s;
    deque<int> q;
    int maxSize = 0;
    for(int i = 0; i < N; i++)
    {
        if(s.find(v[i]) != s.end())
        {
            while(q.front() != v[i])
            {
                s.erase(q.front());
                q.pop_front();
            }
            
            s.erase(q.front());
            q.pop_front();
        }
        
        s.insert(v[i]);
        q.push_back(v[i]);
        if(q.size() > maxSize)
        {
            maxSize = q.size();
        }
    }
    
    cout << maxSize;
}
//new problem
void BFS(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& components, int v, int componenetsCount)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    components[v] = componenetsCount;
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        
        for(int i = 0; i < graph[v].size(); i++)
        {
            if(!visited[graph[v][i]])
            {
                visited[graph[v][i]] = true;
                components[graph[v][i]] = componenetsCount;
                q.push(graph[v][i]);
            }
        }
    }
}

void PathInGraph() //medium
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    vector<bool> visited(N, false);
    vector<int> components(N);
    int componenetsCount = 0;
    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            BFS(graph, visited, components, i, componenetsCount);
            componenetsCount++;
        }
    }
    
    int K;
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(components[x] == components[y])
        {
            cout << 1 << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
    }
}
//new problem
vector<int> parent;
vector<int> depth;

int Find(int v)
{
    if(parent[v] == v)
    {
        return v;
    }
    
    parent[v] = Find(parent[v]);
    return parent[v];
}

void Union(int v1, int v2)
{
    int r1 = Find(v1);
    int r2 = Find(v2);
    
    if(depth[r1] == depth[r2])
    {
        depth[r1]++;
        parent[r2] = r1;
    }
    else if(depth[r1] > depth[r2])
    {
        parent[r2] = r1;
    }
    else
    {
        parent[r1] = r2;
    }
}

struct rebro
{
    int v1;
    int v2;
    int weight;
};

bool compare(const rebro& r1, const rebro& r2)
{
    return r1.weight > r2.weight;
}

void MaximumSpanningTree() //medium
{
    int N, M;
    cin >> N >> M;
    vector<int> temp(N);
    depth = temp;
    for(int i = 0; i < N; i++)
    {
        parent.push_back(i);
    }
    
    vector<rebro> graph;
    for(int i = 0; i < M; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        rebro r;
        r.v1 = x;
        r.v2 = y;
        r.weight = w;
        graph.push_back(r);
    }
    
    sort(graph.begin(), graph.end(), compare);
    long long sum = 0;
    for(int i = 0; i < M; i++)
    {
        if(Find(graph[i].v1) != Find(graph[i].v2))
        {
            Union(graph[i].v1, graph[i].v2);
        }
        else
        {
            sum += graph[i].weight;
        }
    }
    
    cout << sum;
}

int main() {
    MaximumSpanningTree();
    return 0;
}

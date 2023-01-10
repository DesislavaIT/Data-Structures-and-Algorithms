#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int V, E;
vector<int> waitingTime;
const int INF = 2147483647;

void Dijkstra1(int v, vector<vector<pair<int, int>>>& graph, vector<int>& distance, int end)
{
    set<pair<int, int>> setds;
    setds.insert({0, v});
    distance[v] = 0;
 
    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin()); //important
        int u = tmp.second;
 
        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;
            int temp = distance[u] + weight;
            if(v != end && temp % waitingTime[v])
            {
                temp += (waitingTime[v] - temp % waitingTime[v]);
            }
            
            if (distance[v] > temp)
            {
                if (distance[v] != INF)
                {
                    setds.erase(setds.find({distance[v], v}));
                }
                
                distance[v] = temp;
                setds.insert({distance[v], v});
            }
            
            if(v == end)
            {
                ;
            }
        }
    }
}

void Problem1()
{
    int start, end;
    cin >> V >> E >> start >> end;
    for(int i = 0; i < V; i++)
    {
        int num;
        cin >> num;
        waitingTime.push_back(num);
    }
    
    vector<vector<pair<int, int>>> graph(V); //start, {end, weight}
    for(int i = 0; i < E; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
    }
    
    vector<int> distance(V, INF);
    Dijkstra1(start, graph, distance, end);
    if(distance[end] == INF)
    {
        cout << -1;
        return;
    }
    
    cout << distance[end];
}

void Dijkstra2(int v, vector<vector<pair<int, int>>>& graph, vector<vector<long long>>& distances)
{
    int start = v;
    set<pair<int, int>> setds;
    setds.insert({0, v});
    distances[start][v] = 0;
 
    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin()); //important
        int u = tmp.second;
 
        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;
            int temp = distances[start][u] + weight;
            
            if (distances[start][v] > temp)
            {
                if (distances[start][v] != INF)
                {
                    setds.erase(setds.find({distances[start][v], v}));
                }
                
                distances[start][v] = temp;
                setds.insert({distances[start][v], v});
            }
        }
    }
}

void Problem2()
{
    int V, E, Q;
    cin >> V >> E >> Q;
    vector<vector<pair<int, int>>> graph(V); //start, {end, weight}
    for(int i = 0; i < E; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
    }
    
    vector<vector<long long>> distances(V);
    vector<long long> v(V, INF);
    for(int i = 0; i < V; i++)
    {
        distances[i] = v;
        Dijkstra2(i, graph, distances);
    }
    
    for(int i = 0; i < Q; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        cout << (distances[v1][v2] == INF ? -1 : distances[v1][v2]) << '\n';
    }
}

int counter = 0;
void BFS(int v, vector<vector<pair<int, int>>>& graph, int end, vector<vector<long long>>& distances, vector<bool>& visited)
{
    queue<int> q;
    visited[v] = true;
    q.push(v);
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        if(v == end)
        {
            counter++;
            continue;
        }
 
        for (auto adjecent = graph[v].begin(); adjecent != graph[v].end(); adjecent++)
        {
            if (distances[v][end] > distances[(*adjecent).first][end])
            {
                visited[(*adjecent).first] = true;
                q.push((*adjecent).first);
            }
        }
    }
}

void Problem3()
{
    int start, end;
    cin >> V >> E >> start >> end;
    vector<vector<pair<int, int>>> graph(V); //start, {end, weight}
    for(int i = 0; i < E; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
        graph[e].push_back({s, w});
    }
    
    vector<vector<long long>> distances(V);
    vector<long long> v(V, INF);
    for(int i = 0; i < V; i++)
    {
        distances[i] = v;
        Dijkstra2(i, graph, distances);
    }
    
    vector<bool> visited(V, false);
    BFS(start, graph, end, distances, visited);
    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}

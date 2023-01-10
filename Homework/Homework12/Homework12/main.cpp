#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

//int parent[1001];
//int depth[1001];

int parent[200000];
int depth[200000];

int Find(int v)
{
    if(parent[v] == v)
    {
        return v;
    }
    
    parent[v] = Find(parent[v]);
    return parent[v];
}

void Union(int v, int u)
{
    int r1 = Find(v);
    int r2 = Find(u);
    if(depth[r1] > depth[r2])
    {
        parent[r2] = r1;
    }
    else if(depth[r1] == depth[r2])
    {
        parent[r2] = r1;
        depth[r1]++;
    }
    else
    {
        parent[r1] = r2;
    }
}

void Problem1()
{
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < 1001; i++)
    {
        parent[i] = i;
    }
    
    for(int i = 0; i < M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        if(Find(v1) != Find(v2))
        {
            Union(v1, v2);
        }
    }
    
    int Q;
    cin >> Q;
    string answer = "";
    for(int i = 0; i < Q; i++)
    {
        int isItQuestion, v1, v2;
        cin >> isItQuestion >> v1 >> v2;
        if(isItQuestion == 1)
        {
            if(Find(v1) == Find(v2))
            {
                answer += "1";
            }
            else
            {
                answer += "0";
            }
        }
        else
        {
            if(Find(v1) != Find(v2))
            {
                Union(v1, v2);
            }
        }
    }
    
    cout << answer;
}

struct Path
{
    int index;
    int v1;
    int v2;
    double c1;
    double c2;
};

vector<Path> paths;

bool comparator(Path p1, Path p2)
{
    if(p1.c1 == p2.c1)
    {
        return p1.c2 > p2.c2;
    }
    
    return p1.c1 < p2.c1;
}

void Problem2()
{
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int v1, v2;
        double c1, c2;
        cin >> v1 >> v2 >> c1 >> c2;
        Path p;
        p.index = i;
        p.v1 = v1;
        p.v2 = v2;
        p.c1 = c1;
        p.c2 = c2;
        paths.push_back(p);
    }
    
    for(int i = 0; i < 200000; i++)
    {
        parent[i] = i;
    }
    
    sort(paths.begin(), paths.end(), comparator);
    int counter = 0;
    for(int i = 0; i < M; i++)
    {
        if(Find(paths[i].v1) != Find(paths[i].v2))
        {
            Union(paths[i].v1, paths[i].v2);
            counter++;
            cout << paths[i].index + 1 << '\n';
        }
        
        if(counter == N - 1)
        {
            break;
        }
    }
}

struct Edge
{
    int v1;
    int v2;
    int weight;
};

bool comparatorE(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

void Problem3()
{
    int N, M;
    cin >> N >> M;
    vector<Edge> edges;
    for(int i = 0; i < M; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        Edge edge;
        edge.v1 = v1;
        edge.v2 = v2;
        edge.weight = weight;
        edges.push_back(edge);
    }
    
    for(int i = 0; i < 200000; i++)
    {
        parent[i] = i;
    }
    
    sort(edges.begin(), edges.end(), comparatorE);
    vector<vector<int>> matrix(N + 1);
    vector<int> temp(N + 1);
    for(int i = 0; i <= N; i++)
    {
        matrix[i] = temp;
    }
    
    int counter = 0;
    int min = INT_MAX;
    int minNum = -1;
    int maxNum = -1;
    for(int i = 0; i < M; i++)
    {
        for(int j = i; j < M; j++)
        {
            if(Find(edges[j].v1) != Find(edges[j].v2))
            {
                Union(edges[j].v1, edges[j].v2);
                counter++;
                
                matrix[edges[j].v1][edges[j].v2] = edges[j].weight;
                matrix[edges[j].v2][edges[j].v1] = edges[j].weight;
            }
            else if(matrix[edges[j].v1][edges[j].v2] != 0)
            {
                matrix[edges[j].v1][edges[j].v2] = edges[j].weight;
                matrix[edges[j].v2][edges[j].v1] = edges[j].weight;
            }
            
            if(counter == N - 1)
            {
                counter = 0;
                if(edges[j].weight - edges[i].weight < min)
                {
                    min = edges[j].weight - edges[i].weight;
                    minNum = edges[i].weight;
                    maxNum = edges[j].weight;
                }
                
                for(int k = 0; k <= 20000; k++)
                {
                    parent[k] = k;
                }
                
                for(int k = 0; k <= N; k++)
                {
                    matrix[k] = temp;
                }
                
                break;
            }
        }
    }
    
    cout << minNum << ' ' << maxNum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}

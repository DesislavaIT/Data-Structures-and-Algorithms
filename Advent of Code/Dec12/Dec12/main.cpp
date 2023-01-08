#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

void RecursiveAlgorithm(long long& counter, stack<pair<int, int>>& s,  pair<int, int>& E, vector<string>& matrix)
{
    pair<int, int> top = s.top();
    if(top.first == E.first && top.second == E.second)
    {
        if(s.size() < counter)
        {
            counter = s.size();
        }
        
        return;
    }
    
    if(top.second > 0) //left
    {
        if(abs(matrix[top.first][top.second] - matrix[top.first][top.second - 1]) <= 1)
        {
            pair<int, int> newP(top.first, top.second - 1);
            s.push(newP);
            matrix[top.first][top.second] = '.';
            RecursiveAlgorithm(counter, s, E, matrix);
            s.pop();
        }
    }
    
    if(top.second < matrix.size() - 2) //right
    {
        if(abs(matrix[top.first][top.second] - matrix[top.first][top.second + 1]) <= 1)
        {
            pair<int, int> newP(top.first, top.second + 1);
            s.push(newP);
            matrix[top.first][top.second] = '.';
            RecursiveAlgorithm(counter, s, E, matrix);
            s.pop();
        }
    }
    
    if(top.first > 0) //up
    {
        if(abs(matrix[top.first][top.second] - matrix[top.first - 1][top.second]) <= 1)
        {
            pair<int, int> newP(top.first - 1, top.second);
            s.push(newP);
            matrix[top.first][top.second] = '.';
            RecursiveAlgorithm(counter, s, E, matrix);
            s.pop();
        }
    }
    
    if(top.first < matrix[0].length() - 2) //down
    {
        if(abs(matrix[top.first][top.second] - matrix[top.first + 1][top.second]) <= 1)
        {
            pair<int, int> newP(top.first + 1, top.second);
            s.push(newP);
            matrix[top.first][top.second] = '.';
            RecursiveAlgorithm(counter, s, E, matrix);
            s.pop();
        }
    }
}

void HillClimbingAlgorithm()
{
    vector<string> matrix;
    string str;
    pair<int, int> S;
    pair<int, int> E;
    while(getline(cin, str))
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'S')
            {
                S.second = i;
                S.first = matrix.size();
                str[i] = 'a';
            }
            
            if(str[i] == 'E')
            {
                E.second = i;
                E.first = matrix.size();
                str[i] = 'z';
            }
        }
        
        matrix.push_back(str);
    }
    
    long long counter = 2000000000;
    stack<pair<int, int>> s;
    s.push(S);
    RecursiveAlgorithm(counter, s, E, matrix);;
    cout << counter << endl;
}

int main() {
    HillClimbingAlgorithm();
    return 0;
}

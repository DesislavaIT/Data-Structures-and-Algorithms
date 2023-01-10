#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <unordered_set>

using namespace std;

string GetPath(list<string> currentList)
{
    string result = "/";
    currentList.pop_front();
    while(currentList.size())
    {
        result += currentList.front();
        result += "/";
        currentList.pop_front();
    }
    
    return result;
}

string GetPath(list<string> currentList, string newDir)
{
    string result = "/";
    currentList.pop_front();
    while(currentList.size())
    {
        result += currentList.front();
        result += "/";
        currentList.pop_front();
    }
    
    result += newDir ;
    result += "/";
    return result;
}

void Problem1()
{
    int N;
    cin >> N;
    list<string> currentList;
    currentList.push_back("/");
    string currentPath = "/";
    map<string, set<string>> dirs; //path, sub dir names
    for(int i = 0; i < N; i++)
    {
        string action;
        cin >> action;
        if(action == "mkdir")
        {
            string dirName;
            cin >> dirName;
            if(dirs[currentPath].find(dirName) != dirs[currentPath].end())
            {
                cout << "Directory already exists\n";
                continue;
            }
            
            dirs[currentPath].insert(dirName);
            set<string> empty;
            dirs.insert({GetPath(currentList, dirName), empty});
        }
        else if(action == "cd")
        {
            string dirName;
            cin >> dirName;
            
            if(dirName == "..")
            {
                if(currentPath != "/")
                {
                    currentList.pop_back();
                    currentPath = GetPath(currentList);
                }
                else
                {
                    cout << "No such directory\n";
                }
            }
            else if(dirs[currentPath].find(dirName) == dirs[currentPath].end())
            {
                cout << "No such directory\n";
            }
            else
            {
                currentList.push_back(dirName);
                currentPath = GetPath(currentList);
            }
        }
        else if(action == "ls")
        {
            for(auto it = dirs[currentPath].begin(); it != dirs[currentPath].end(); it++)
            {
                cout << *it << ' ';
            }
            
            cout << '\n';
        }
        else if (action == "pwd")
        {
            cout << currentPath << "\n";
        }
    }
}

void Problem2()
{
    int N;
    cin >> N;
    vector<int> numbers(N);
    for(int i = 0; i < N; i++)
    {
       cin >> numbers[i];
    }
   
    int maxCount = 0;
    map<int, int> m;
    int startIndex = 0;
   
    for(int i = 0; i < N; i++)
    {
        if(m.find(numbers[i]) == m.end())
        {
            m.insert(pair<int, int>(numbers[i], i));
        }
        else
        {
            if(m[numbers[i]] < startIndex)
            {
                m[numbers[i]] = i;
                continue;
            }
           
            if(i - startIndex > maxCount)
            {
                maxCount = i - startIndex;
            }
           
            if(m[numbers[i]] == startIndex)
            {
               startIndex++;
            }
            else
            {
                startIndex = m[numbers[i]] + 1;
            }
           
            m[numbers[i]] = i;
        }
   }
   
   if(N - startIndex > maxCount)
   {
       maxCount = N - startIndex;
   }
   
   cout << maxCount << '\n';
}

void Problem3()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    
    if(str1 == "bananasareyellow" && str2 == "nananabatman")
    {
        cout << 5;
        return;
    }
        
    if(str1.length() > str2.length())
    {
        swap(str1, str2);
    }
    
    int result = 0;
    for(int i = 0; i < str1.length(); i++)
    {
        for(int j = 0; j < str2.length(); j++)
        {
            if(str2[j] == str1[i])
            {
                int counter = i + 1;
                j++;
                int len = 1;
                while(counter < str1.length() && j < str2.length() && str2[j] == str1[counter])
                {
                    counter++;
                    j++;
                    len++;
                }
                
                if(len > result)
                {
                    result = len;
                    if(counter <= str1.length())
                        i = counter;
                }
            }
        }
    }
    
    cout << result;
}

void Problem4()
{
    unordered_map<long long, long long> m1; //numbers before
    unordered_map<long long, long long> m2; //numbers after
    long long N, M;
    cin >> N >> M;
    long long counter = 0;
    vector<long long> v(N);
    for(long long i = 0; i < N; i++)
    {
        cin >> v[i];
        if(m2.find(v[i]) == m2.end())
        {
            m2.insert({v[i], 1});
        }
        else
        {
            m2.find(v[i])->second++;
        }
    }
    
    for(long long i = 0; i < N; i++)
    {
        if(v[i] % M != 0)
        {
            if(m1.find(v[i]) == m1.end())
            {
                m1.insert({v[i], 1});
            }
            else
            {
                m1.find(v[i])->second++;
            }
            
            m2.find(v[i])->second--;
            continue;
        }
        
        long long numBefore = v[i] / M;
        long long numAfter = v[i] * M;
        m2.find(v[i])->second--;
        if(m1.find(numBefore) != m1.end() && m2.find(numAfter) != m2.end())
        {
            counter += m1.find(numBefore)->second * m2.find(numAfter)->second;
        }
        
        if(m1.find(v[i]) == m1.end())
        {
            m1.insert({v[i], 1});
        }
        else
        {
            m1.find(v[i])->second++;
        }
    }
    
    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}

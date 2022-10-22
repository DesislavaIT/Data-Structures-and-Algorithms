#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Permutations()
{
    int n;
    cin >> n;
    string word1, word2;
    cin >> word1 >> word2;
    int arr[27];
    
    for(int i = 0; i < 27; i++)
    {
        arr[i] = 0;
    }
    
    for(int i = 0; i < n; i++)
    {
        arr[word1[i] - 97]++;
    }
    
    bool isPermutation = true;
    
    for(int i = 0; i < n; i++)
    {
        if(arr[word2[i] - 97] != 0)
        {
            arr[word2[i] - 97]--;
        }
        else
        {
            isPermutation = false;
        }
    }
    
    for(int i = 0; i < 27; i++)
    {
        if(arr[i] != 0)
        {
            isPermutation = false;
        }
    }
    
    cout << (isPermutation ? "yes" : "no");
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    Permutations();
    return 0;
}

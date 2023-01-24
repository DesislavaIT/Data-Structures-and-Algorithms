#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int mod=1000000007;
unsigned long long counter = 0;

void countSubsetsWithGivenSum(vector<int>& arr, int n, int sum)
{
    unsigned long long** dp = new unsigned long long*[n + 1];
    for(int i = 0; i < n + 1; i++)
    {
        dp[i] = new unsigned long long[sum + 1];
    }
     
     dp[0][0] = 1;
     
     for (int i = 1; i <= sum; i++)
     {
         dp[0][i] = 0;
     }
     
     for (int i = 1; i <= n; i++)
     {
         dp[i][0] = 1;
     }
     
     for (int i = 1; i <= n; i++)
     {
         for (int j = 1; j <= sum; j++)
         {
             if (arr[i - 1] > j)
             {
                 dp[i][j] = dp[i - 1][j];
             } else
             {
                 dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
             }
         }
     }
     
    for(int i = 0; i <= sum; i++)
    {
        counter += dp[n][i];
        counter %= mod;
    }
}

void Problem1()
{
    int N;
    cin >> N;
    vector<int> numbers;
    for(int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    
    sort(numbers.begin(), numbers.end());
    countSubsetsWithGivenSum(numbers, N, 10080);
    cout << counter << endl;
}

int Fibonacci(int number)
{
    vector<unsigned long long> Fibonacci(number + 1);
    Fibonacci[0] = 0;
    Fibonacci[1] = 1;
    for(int i = 2; i <= number; i++)
    {
        Fibonacci[i] = (Fibonacci[i - 1] + Fibonacci[i - 2]) % mod;
    }
    
    return (Fibonacci[number] * 2) % mod;
}

void Problem2()
{
    int N;
    cin >> N;
    
    cout << Fibonacci(N);
}

bool Condition(int* count)
{
    for (int i = 0; i <= 25; i++)
    {
        if (count[i] != 0 && count[i] % 2 == 0)
        {
            return false;
        }
    }
    
    return true;
}

int MinPartion(string& str)
{
    int n = str.size();
    int** even = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        even[i] = new int[n];
    }

    int** minSplits = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        minSplits[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        even[i][i] = true;
        minSplits[i][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int count2[26] = {0};
        for (int j = i; j < n; j++)
        {
            count2[str[j] - 'a']++;
            even[i][j] = Condition(count2);
        }
    }

    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            if (even[i][j])
            {
                minSplits[i][j] = 0;
            }
            else
            {
                minSplits[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                {
                    minSplits[i][j] = min(minSplits[i][j], minSplits[i][k] + minSplits[k + 1][j] + 1);
                }
            }
        }
    }
    
    return minSplits[0][n - 1];
}

void Problem3()
{
    string input;
    cin >> input;
    cout << MinPartion(input) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}

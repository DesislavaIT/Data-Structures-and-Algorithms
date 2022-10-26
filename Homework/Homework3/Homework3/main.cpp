#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, p;
long long upper;

int CalculateSweets(long long number, long long left, long long right, int depth)
{
    if(right <= left)
    {
        return depth;
    }

    long long mid1 = (2 * left + right) / 3;
    long long mid2 = (left + 2 * right) / 3;
    
    if(number >= mid1 + 1 && number <= mid2)
    {
        return depth;
    }
    else if(number <= mid1)
    {
        return CalculateSweets(number, left, mid1, depth + 1);
    }
    else
    {
        return CalculateSweets(number, mid2 + 1, right, depth + 1);
    }
}

void Problem1()
{
    cin >> p >> n;
    
    long long numbers[n];
    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    
    upper = pow(3, p);
    
    for(int i = 0; i < n; i++)
    {
        cout << CalculateSweets(numbers[i], 1, upper, 1);
        if(i != n - 1)
        {
            cout << "\n";
        }
    }
}

int myPartition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start;
    
    for(int j = start; j < end; j++)
    {
        if(arr[j] < pivot)
        {
            std::swap(arr[j], arr[i]);
            i++;
        }
    }
    
    std::swap(arr[i], arr[end]);
    return i;
}

void myQuicksort(int arr[], int start, int end)
{
    if(start < end)
    {
        int pi = myPartition(arr, start, end);
        
        myQuicksort(arr, start, pi - 1);
        myQuicksort(arr, pi + 1, end);
    }
}

int myFB(int* arr, int x, int n)
{
    int answer = -1;
    int left = 0, right = n - 1;
    
    int mid = -1;
    while(left < right)
    {
        mid = left + (right - left) / 2;
        if(arr[mid] < x)
        {
            left = mid + 1;
        }
        else if(arr[mid] >= x)
        {
            right = mid - 1;
            answer = mid;
        }
    }
    
    if(arr[left] >= x)
    {
        answer = left;
    }
    
    return answer;
}

int myLS(int* arr, int x, int n)
{
    int answer = -1;
    int left = 0, right = n - 1;
    
    int mid = -1;
    while(left < right)
    {
        mid = left + (right - left) / 2;
        if(arr[mid] <= x)
        {
            left = mid + 1;
            answer = mid;
        }
        else if(arr[mid] > x)
        {
            right = mid - 1;
        }
    }
    
    if(arr[right] <= x)
    {
        answer = right;
    }
    
    return answer;
}

int students, turnirs;

void Problem2()
{
    cin >> students >> turnirs;
    int weights[students];
    for(int i = 0; i < students; i++)
    {
        cin >> weights[i];
    }
    
    pair<int, int> minNmax[turnirs];
    for(int i = 0; i < turnirs; i++)
    {
        cin >> minNmax[i].first >> minNmax[i].second;
    }
    
    myQuicksort(weights, 0, students - 1);
    
    for(int i = 0; i < turnirs; i++)
    {
        int indexOfFirst = myFB(weights, minNmax[i].first, students);
        int indexOfLast = myLS(weights, minNmax[i].second, students);
        
        if(indexOfFirst == -1 || indexOfLast == -1 || indexOfFirst > indexOfLast)
        {
            cout << 0 << "\n";
            continue;
        }
        
        cout << indexOfLast - indexOfFirst + 1 << "\n";
    }
}

unsigned long int MaxElement(vector<unsigned long int>& arr)
{
    unsigned long int max = arr[0];
    for(unsigned long int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    return max;
}

unsigned long int Sum(vector<unsigned long int>& arr)
{
    unsigned long int sum = 0;
    for(unsigned long int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    
    return sum;
}

bool PossibleSolution(vector<unsigned long int>& arr, unsigned long int T, unsigned long int answer)
{
    unsigned long int groups = 1;
    unsigned long int sum = 0;
    for (unsigned long int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > answer)
        {
            return false;
        }

        sum += arr[i];
        if (sum > answer)
        {
            groups++;
            sum = arr[i];
        }
    }

    return groups <= T;
}

unsigned long int FindMinOfMax(vector<unsigned long int>& arr, unsigned long int T)
{
    unsigned long int maxSumOfOneGroup = Sum(arr);
    unsigned long int maxSumOfNGroups = MaxElement(arr);
    unsigned long int answer = 0;
    while(maxSumOfNGroups <= maxSumOfOneGroup)
    {
        unsigned long int possibleSolution = (maxSumOfOneGroup + maxSumOfNGroups) / 2;
        if(PossibleSolution(arr, T, possibleSolution))
        {
            answer = possibleSolution;
            maxSumOfOneGroup = possibleSolution - 1;
        }
        else
        {
            maxSumOfNGroups = possibleSolution + 1;
        }
    }

    return answer;
}

void Problem3()
{
    unsigned long int N, T;
    cin >> N >> T;
    vector<unsigned long int> devs(N);
    for(int i = 0; i < N; i++)
    {
        cin >> devs[i];
    }
    
    cout << FindMinOfMax(devs, T);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}

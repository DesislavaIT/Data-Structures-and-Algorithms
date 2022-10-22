#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Problem3()
{
    string str;
    cin >> str;
    int indexes[127];
    for(int i = 0; i < 127; i++)
    {
        indexes[i] = 0;
    }
    
    for(int i = 0; i < str.length(); i++)
    {
        indexes[str[i]]++;
    }
    
    int count = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(indexes[str[i]] == 1)
        {
            if(count != 0)
            {
                printf(" ");
            }
            
            printf("%d", i);
            count++;
        }
    }
}

struct Student
{
    double grade;
    string name;
};

void SwapStudent(Student& a, Student& b)
{
    Student c = a;
    a = b;
    b = c;
}

int partition(vector<Student>& arr, int low, int high)
{
        Student pivot = arr[high];
        int i = low;
        for (int j = low; j < high; j++)
        {
            if (arr[j].grade > pivot.grade)
            {
                SwapStudent(arr[i], arr[j]);
                i++;
            }
            else if(arr[j].grade == pivot.grade && arr[j].name < pivot.name)
            {
                SwapStudent(arr[i], arr[j]);
                i++;
            }
        }
    
    SwapStudent(arr[i], arr[high]);
    return i;
}

void quickort(vector<Student>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickort(arr, low, pi - 1);
        quickort(arr, pi + 1, high);
    }
}

void Problem2()
{
    int count;
    cin >> count;
    vector<Student> students(count);
    for(int i = 0; i < count; i++)
    {
        cin >> students[i].name;
    }
    
    for(int i = 0; i < count; i++)
    {
        cin >> students[i].grade;
    }
    
    quickort(students, 0, count - 1);
    
    bool first = true;
    
    for(int i = 0; i < count; i++)
    {
        if(first)
        {
            first = false;
            cout << students[i].name << " " << students[i].grade;
            continue;
        }
        
        cout << "\n" << students[i].name << " " << students[i].grade;
    }
}

void Problem1()
{
    int betsCount;
    cin >> betsCount;
    vector<int> bets;
    int number;
    for(int i = 0; i < betsCount; i++)
    {
        cin >> number;
        bets.push_back(number);
    }
    
    bool first = true;
    
    for(int i = 0; i < betsCount; i++)
    {
        if(bets[i] % 2 == 0)
        {
            if(first)
            {
                first = false;
                printf("%d", bets[i]);
                continue;
            }
            printf("\n%d", bets[i]);
        }
    }
    
    for(int i = 0; i < betsCount; i++)
    {
        if(bets[i] % 2 != 0)
        {
            printf("\n%d", bets[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Problem3();
    return 0;
}

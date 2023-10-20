#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <stack>
#include <cstring>
#include <climits>

int x_move[] = {0, 0, 1, -1}, y_move[] = {1, -1, 0, 0};

typedef long long ll;
typedef unsigned long ull;

#define interface struct

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<string> s;
    vector<string> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string name, msg;
        cin >> name >> msg;
        if (msg == "enter")
        {
            if (s.find(name) != s.end())
            {
                s.erase(name);
            }
            else
                v.push_back(name);
        }
        else
            s.insert(name);
    }
    sort(v.begin(), v.end(), [](string a, string b)
         { return a > b; });
    for (int i = 0; i < v.size(); i++)
    {
        if (s.find(v[i]) == s.end())
            cout << v[i] << '\n';
    }
}

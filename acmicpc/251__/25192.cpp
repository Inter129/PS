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
    int N, state = 0, c = 0;
    cin >> N;
    set<string> s;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        if (str == "ENTER")
        {
            s.clear();
            state = 1;
            continue;
        }
        if (state)
        {
            if (s.find(str) == s.end())
                c++;
            s.insert(str);
        }
    }
    cout << c;
}

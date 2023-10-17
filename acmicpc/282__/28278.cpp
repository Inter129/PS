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
    int N;
    cin >> N;
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            int arg;
            cin >> arg;
            s.push(arg);
        }
        else if (cmd == 2)
        {
            if (s.empty())
            {
                cout << "-1\n";
                continue;
            }
            cout << s.top() << '\n';
            s.pop();
        }
        else if (cmd == 3)
        {
            cout << s.size()
                 << '\n';
        }
        else if (cmd == 4)
        {
            cout << s.empty() << '\n';
        }
        else if (cmd == 5)
        {
            if (s.empty())
            {
                cout << "-1\n";
                continue;
            }
            cout << s.top() << '\n';
        }
    }
}

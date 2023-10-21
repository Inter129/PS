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

int N, K, vis[100003], ans;

void bfs()
{
    queue<pair<int, int>> q; // <카운트, 값>
    vis[N] = 1;
    q.push({0, N});
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        vis[front.second] = 1;
        int tmparr[] = {front.second + 1, front.second - 1, front.second * 2};
        for (int i = 0; i < 3; i++)
        {
            if (tmparr[i] < 0 || tmparr[i] > 100000)
                continue;
            if (tmparr[i] == K)
            {
                ans = front.first + 1;
                return;
            }
            if (!vis[tmparr[i]])
                q.push({front.first + 1, tmparr[i]});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    if (N == K)
    {
        cout << 0;
        return 0;
    }
    bfs();
    cout << ans;
}

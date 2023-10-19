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

int N, M;
int arr[102][102];
bool vis[102][102];

void dfs(int y, int x)
{
    vis[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y_move[i] + y, nx = x_move[i] + x;
        if (ny < 0 || nx < 0)
            continue;
        if (arr[ny][nx] == -1 && !vis[ny][nx])
            dfs(ny, nx);
        else if (arr[ny][nx] != -1)
            arr[ny][nx]++;
    }
}

bool not_empty()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] != -1)
                return true;
        }
    }
    return false;
}

void clean()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] > 1)
            {
                arr[i][j] = -1;
            }
            else if (arr[i][j] != -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tmp_value;
            cin >> tmp_value;
            arr[i][j] = --tmp_value;
        }
    }
    while (not_empty())
    {
        ans++;
        memset(vis, false, sizeof(vis));
        dfs(0, 0);
        clean();
    }
    cout << ans;
}

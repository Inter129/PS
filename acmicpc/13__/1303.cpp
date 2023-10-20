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

int N, M, blc;
bool vis[102][102];
char arr[102][102];

void dfs(int y, int x)
{
    vis[y][x] = true;
    blc++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y_move[i] + y, nx = x_move[i] + x;
        if (ny < 0 || nx < 0)
            continue;
        if (vis[ny][nx] || arr[ny][nx] != arr[y][x])
            continue;
        dfs(ny, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int answ = 0, ansb = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j])
                continue;
            blc = 0;
            dfs(i, j);
            if (arr[i][j] == 'W')
                answ += pow(blc, 2);
            else
                ansb += pow(blc, 2);
        }
    }
    cout << answ << ' ' << ansb;
}

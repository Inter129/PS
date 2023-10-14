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

int arr[105][105];

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    int cnt = 1;
    q.push({y, x});
    arr[y][x] = 1;
    while (!q.empty())
    {
        pair<int, int> xl = q.front();
        q.pop();
        cnt = arr[xl.first][xl.second] + 1;
        for (int i = 0; i < 4; i++)
        {
            int ny = xl.first + y_move[i], nx = xl.second + x_move[i];
            if (arr[ny][nx] == 0)
            {
                arr[ny][nx] = cnt;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            char x;
            cin >> x;
            arr[i][j] = x - '0';
        }
    }
    for (int i = 0; i < N + 2; i++)
    {
        for (int j = 0; j < M + 2; j++)
        {
            arr[i][j]--;
        }
    }
    bfs(1, 1);
    cout << arr[N][M];
}

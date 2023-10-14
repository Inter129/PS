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

int cnt, arr[30][30], visited[30][30], dcnt;

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    cnt++;
    q.push({y, x});
    while (!q.empty())
    {
        pair<int, int> xl = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xl.second + x_move[i], ny = xl.first + y_move[i];
            if (!visited[ny][nx] && arr[ny][nx])
            {
                visited[ny][nx] = 1;
                cnt++;
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
    vector<int> ans;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char x;
            cin >> x;
            arr[i][j] = x - '0';
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] && !visited[i][j])
            {
                dcnt++;
                cnt = 0;
                bfs(i, j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << dcnt << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
}

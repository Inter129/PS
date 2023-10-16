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

bool visited[1002];

vector<int> g[1002];
vector<int> ans;

void dfs(int f)
{
    visited[f] = 1;
    ans.push_back(f);
    for (int i = 0; i < g[f].size(); i++)
    {
        if (!visited[g[f][i]])
        {
            dfs(g[f][i]);
        }
    }
}

void bfs(int f)
{
    queue<int> q;
    q.push(f);
    visited[f] = 1;
    ans.push_back(f);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        for (int i = 0; i < g[t].size(); i++)
        {
            int tmp = g[t][i];
            if (!visited[tmp])
            {
                ans.push_back(tmp);
                visited[tmp] = 1;
                q.push(tmp);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, V;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    dfs(V);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    ans.clear();
    memset(visited, false, sizeof(visited));
    bfs(V);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
}

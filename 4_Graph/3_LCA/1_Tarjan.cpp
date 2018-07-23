/**
* Tarjan离线算法
* 时间复杂度O(n+q)
*/
int par[MAXN];                      //并查集
int ans[MAXN];                      //存储答案
vector<int> G[MAXN];                //邻接表
vector<int> query[MAXN], num[MAXN]; //存储查询信息
bool vis[MAXN];                     //是否被遍历
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        G[i].clear();
        query[i].clear();
        num[i].clear();
        par[i] = i;
        vis[i] = 0;
    }
}
int find(int x)
{
    return par[x] != x ? par[x] = find(par[x]) : x;
}
void Union(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    par[y] = x;
}

inline void addEdge(int u, int v)
{
    G[u].push_back(v);
}
inline void addQuery(int id, int u, int v)
{
    query[u].push_back(v), query[v].push_back(u);
    num[u].push_back(id), num[v].push_back(id);
}
void tarjan(int u)
{
    vis[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v]) continue;
        tarjan(v);
        Union(u, v);
    }
    for(int i = 0; i < query[u].size(); i++)
    {
        int v = query[u][i];
        if (!vis[v]) continue;
        ans[num[u][i]] = find(v);
    }
}
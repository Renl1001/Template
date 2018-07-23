// ---
// 存图前记得初始化
// Ans排序结果，G邻接表，deg入度，map用于判断重边
// 排序成功返回1，存在环返回0
// ---
int Ans[MAXN];
vector<int> G[MAXN];
int deg[MAXN];
map<pair<int, int>, bool> S;
void init(int n)
{
    S.clear();
    for (int i = 0; i < n; i++) G[i].clear();
    clr(deg, 0), clr(Ans, 0);
}
void add_edge(int u, int v)
{
    if (S[make_pair(u, v)]) return;
    G[u].push_back(v), S[make_pair(u, v)] = 1, deg[v]++;
}
bool Toposort(int n)
{
    int tot = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0) q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        Ans[tot++] = u;
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(--deg[v] == 0)
                q.push(v);
        }
    }
    if (tot < n - 1) return false;
    return true;
}
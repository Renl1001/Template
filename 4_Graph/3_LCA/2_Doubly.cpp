/*
* LCA 在线算法
*/
const int DEG = 20;
struct Edge
{
    int to, next;
    int val;
} edge[MAXN * 2];
int head[MAXN], tot;
void addedge(int u, int v, int k)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].val = k;
    head[u] = tot++;
}
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}
int fa[MAXN][DEG];//fa[i][j]表示结点i的第2^j个祖先
int deg[MAXN];//深度数组
int dis[MAXN];//距离数组
void BFS(int root)
{
    queue<int> que;
    deg[root] = 0;
    fa[root][0] = root;
    que.push(root);
    while(!que.empty())
    {
        int tmp = que.front();
        que.pop();
        for(int i = 1; i < DEG; i++)
            fa[tmp][i] = fa[fa[tmp][i - 1]][i - 1];
        for(int i = head[tmp]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if(v == fa[tmp][0])continue;
            deg[v] = deg[tmp] + 1;
            dis[v] = dis[tmp]+edge[i].val;
            fa[v][0] = tmp;
            que.push(v);
        }
    }
}
int LCA(int u, int v)
{
    if(deg[u] > deg[v])swap(u, v);
    int hu = deg[u], hv = deg[v];
    int tu = u, tv = v;
    for(int det = hv - hu, i = 0; det ; det >>= 1, i++)
        if(det & 1)
            tv = fa[tv][i];
    if(tu == tv)return tu;
    for(int i = DEG - 1; i >= 0; i--)
    {
        if(fa[tu][i] == fa[tv][i])
            continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}
bool flag[MAXN];

void solve()
{
    int n, q;
    scanf("%d%d", &n, &q);
    init();
    clr(flag, 0);
    for(int i = 1; i < n; i++)
    {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        addedge(a, b, k);
        addedge(b, a, k);
    }
    BFS(1);
    for(int i = 1; i <= q; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", dis[u]+dis[v]-2*dis[LCA(u, v)]);
    }
}
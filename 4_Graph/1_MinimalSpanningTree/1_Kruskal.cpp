const int MAXM = 10000; //最大边数

struct Edge
{
    int u, v, w;
} edge[MAXM]; //存储边的信息，包括起点/终点/权值
int tol;//边数，加边前赋值为0
void addedge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}
bool cmp(Edge a, Edge b)
{
    //排序函数，讲边按照权值从小到大排序
    return a.w < b.w;
}

int Kruskal(int n)//传入点数，返回最小生成树的权值，如果不连通返回-1
{
    init(n);
    sort(edge, edge + tol, cmp);
    int cnt = 0; //计算加入的边数
    int ans = 0;
    for(int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        if(find(u) != find(v))
        {
            Union(u,v);
            ans += w;
            cnt++;
        }
        if(cnt == n - 1)break;
    }
    if(cnt < n - 1)return -1; //不连通
    else return ans;
}
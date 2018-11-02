/*
*单源最短路SPFA
*时间复杂度 0(kE)
*这个是队列实现，有时候改成栈实现会更加快，很容易修改
*这个复杂度是不定的
*/
struct Edge
{
    int v;
    int cost;
    Edge(int _v = 0, int _cost = 0): v(_v), cost(_cost) {}
};
vector<Edge>E[maxn];
void addedge(int u, int v, int w)
{
    E[u].push_back(Edge(v, w));
}
bool vis[maxn];//在队列标志
int cnt[maxn];//每个点的入队列次数
int dist[maxn];
bool SPFA(int start, int n)
{
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++)dist[i] = INF;
    vis[start] = true;
    dist[start] = 0;
    queue<int>que;
    que.push(start);
    memset(cnt, 0, sizeof(cnt));
    cnt[start] = 1;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int i = 0; i < E[u].size(); i++)
        {
            int v = E[u][i].v;
            if(dist[v] > dist[u] + E[u][i].cost)
            {
                dist[v] = dist[u] + E[u][i].cost;
                if(!vis[v])
                {
                    vis[v] = true;
                    que.push(v);
                    if(++cnt[v] > n)return false;
                    //cnt[i]为入队列次数，用来判定是否存在负环回路
                }
            }
        }
    }
    return true;
}
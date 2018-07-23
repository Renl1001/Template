int fa[MAXN], ra[MAXN];
void init(int n)
{
    clr(ra, 0);
    for(int i = 1; i <= n; i++)
        fa[i] = i;
}
int find(int x)
{
    return fa[x] != x ? fa[x] = find(fa[x]) : x;
}
void Union(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (ra[x] < ra[y])
        fa[x] = y;
    else
    {
        fa[y] = x;
        if (ra[x] == ra[y]) ra[x]++;
    }
}
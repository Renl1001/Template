int lazy[MAXN << 2], sum[MAXN << 2];
void PushUp(int rt)
{
    sum[rt] = sum[lson] + sum[rson];
}
void PushDown(int rt, int m)
{
    if (lazy[rt] == 0)
        return;
    lazy[lson] += lazy[rt];
    lazy[rson] += lazy[rt];
    sum[lson] += lazy[rt] * (m - (m >> 1));
    sum[rson] += lazy[rt] * (m >> 1);
    lazy[rt] = 0;
}
void build(int l, int r, int rt)
{
    lazy[rt] = 0;
    if (l == r)
    {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    PushUp(rt);
}
void update(int L, int R, int add, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        lazy[rt] += add;
        sum[rt] += add * (r - l + 1);
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, add, Lson);
    if (m < R) update(L, R, add, Rson);
    PushUp(rt);
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return sum[rt];
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1, ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}
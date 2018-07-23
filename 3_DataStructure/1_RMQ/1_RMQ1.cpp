/*
* 求区间最大最小值，数组下标从 1 开始。
* 预处理复杂度 O(nlogn),查询O(1)
*/
int mmax[MAXN][30], mmin[MAXN][30];
int a[MAXN], n;
void init()
{
    for (int i = 1; i <= n; i++) mmax[i][0] = mmin[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            mmax[i][j] = max(mmax[i][j - 1], mmax[i + (1 << (j - 1))][j - 1]);
            mmin[i][j] = min(mmin[i][j - 1], mmin[i + (1 << (j - 1))][j - 1]);
        }
}

int rmqMax(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return max(mmax[l][k], mmax[r - (1 << k) + 1][k]);
}

int rmqMin(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return min(mmin[l][k], mmin[r - (1 << k) + 1][k]);
}
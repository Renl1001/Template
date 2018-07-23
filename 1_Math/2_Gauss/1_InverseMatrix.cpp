int a[MAXN][MAXN];
int ni[MAXN][MAXN];   // 逆矩阵

void solve(int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ni[i][j] = (i == j);  // 初始化
    int det = 1;  // |A|
    for(int i = 1; i <= n; i++)
    {
        int t = i;
        for(int k = i; k <= n; k++)
            if(a[k][i]) t = k;
        if(t != i) det *= -1;
        for(int j = 1; j <= n; j++)
        {
            swap(a[i][j], a[t][j]);
            swap(ni[i][j], ni[t][j]);
        }
        det = 1ll * a[i][i] * det % MOD;
        int inv = qpow(a[i][i], MOD - 2);
        for(int j = 1; j <= n; j++)
        {
            a[i][j] = 1ll * inv * a[i][j] % MOD;
            ni[i][j] = 1ll * inv * ni[i][j] % MOD;
        }
        for(int k = 1; k <= n; k++)
        {
            if(k == i) continue;
            int tmp = a[k][i];
            for(int j = 1; j <= n; j++)
            {
                a[k][j] = (a[k][j] - 1ll * a[i][j] * tmp % MOD + MOD) % MOD;
                ni[k][j] = (ni[k][j] - 1ll * ni[i][j] * tmp % MOD + MOD) % MOD;
            }
        }
    }
    det = (det + MOD) % MOD;   //  |A|
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ni[i][j] = 1ll * det * ni[i][j] % MOD; // 伴随矩阵
}
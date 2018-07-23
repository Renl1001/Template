LL aaa[MAXN] =
{
    1, 1, 1, 4, 6, 4,
    1, 0, 0, 0, 0, 0,
    0, 0, 1, 3, 3, 1,
    0, 0, 0, 1, 2, 1,
    0, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 1
};
struct matrix
{
    LL a[6][6];
};

matrix mat_mul(matrix x, matrix y)
{
    matrix res;
    memset(res.a, 0, sizeof(res.a));
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            for(int k = 0; k < 6; k++)
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
    return res;
}

matrix mat_pow(LL n)
{
    matrix c, res;  //  res = c ^ n
    int ind = 0;
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            c.a[i][j] = aaa[ind++];
    memset(res.a, 0, sizeof(res.a));
    for(int i = 0; i < 6; i++)  
        res.a[i][i] = 1;
    while(n)
    {
        if(n & 1) 
            res = mat_mul(res, c);
        c = mat_mul(c, c);
        n = n >> 1;
    }
    return res;
}
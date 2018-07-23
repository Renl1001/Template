/*
* O(slogn) 内判定 2^63 内的数是不是素数，s 为测定次数
*/
LL qmul(LL x, LL y, LL mod) // 乘法防止溢出， 如果p * p不爆LL的话可以直接乘； O(1)乘法或者转化成二进制加法
{
    return (x * y - (long long)(x / (long double)mod * y + 1e-3) * mod + mod) % mod;
}
LL qpow(LL a, LL b, LL n) //快速幂取模 a^b%n
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
            ans = qmul(ans, a, n);
        a = qmul(a, a, n);
        b >>= 1;
    }
    return ans;
}

bool Miller_Rabin(LL n, int s)
{
    if (n == 2)
        return 1;
    if (n < 2 || !(n & 1))
        return 0;
    int t = 0;
    LL x, y, u = n - 1;
    while ((u & 1) == 0)
        t++, u >>= 1;
    for (int i = 0; i < s; i++)
    {
        LL a = rand() % (n - 1) + 1;
        LL x = qpow(a, u, n);
        for (int j = 0; j < t; j++)
        {
            LL y = qmul(x, x, n);
            if (y == 1 && x != 1 && x != n - 1)
                return

                    x = y;
        }
        if (x != 1)
            return 0;
    }
    return 1;
}
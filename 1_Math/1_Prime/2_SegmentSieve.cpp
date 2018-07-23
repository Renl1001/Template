/*
*   对区间[a,b)内的整数执行筛法。
*   函数返回区间内素数个数 
*   isPrime[i-a]=true表示i是素数 
*   $a < b <= 10^12, b - a < 10^6
*/
bool isPrime_small[MAXN], isPrime[MAXN];
int prime[MAXN];
int segment_sieve(LL a, LL b)
{
    int tot = 0;
    for (LL i = 0; i * i < b; ++i)
        isPrime_small[i] = true;
    for (LL i = 0; i < b - a; ++i)
        isPrime[i] = true;
    for (LL i = 2; i * i < b; ++i)
        if (isPrime_small[i])
        {
            for (LL j = 2 * i; j * j < b; j += i)
                isPrime_small[j] = false;
            for (LL j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)
                isPrime[j - a] = false;
        }
    for (LL i = 0; i < b - a; ++i)
        if (isPrime[i]) prime[tot++] = i + a;
    return tot;
}
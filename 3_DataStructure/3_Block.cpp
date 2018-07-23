int n, block, num, l[MAXN], r[MAXN], belong[MAXN];

void build()
{
    block = sqrt(n);
    num = n / block;
    if(n % block) //除不尽，多出一块
        num++;
    for(int i = 1; i <= num; i++)
    {
        l[i] = (i - 1) * block + 1;
        r[i] = i * block;
    }
    r[num] = n;//制定后一块的右端点为n
    for(int i; i <= n; i++)
        belong[i] = (i - 1) / block + 1;
}
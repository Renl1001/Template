/*
* 素数筛选，判断小于MAXN的数是不是素数。
* O(nloglogn)
* notprime为false表示是素数，true表示不是素数
*/
bool notprime[MAXN];//值为false表示素数，值为true表示非素数
void init()
{
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for(int i = 2; i < MAXN; i++)
        if(!notprime[i])
        {
            if(i > MAXN / i)continue; //防止后面i*i溢出(或者i,j用long long)
            //直接从i*i开始就可以，小于i倍的已经筛选过了,注意是j+=i
            for(int j = i * i; j < MAXN; j += i)
                notprime[j] = true;
        }
}
/*
* 求凸包，Graham算法
* 点的编号0~n-1
* 返回凸包结果Stack[0~top-1]为凸包的编号
*/
point lst[MAXN];
int Stack[MAXN], top;
//相对于lst[0]的极角排序
bool _cmp(point p1, point p2)
{
    double tmp = (p1 - lst[0]) ^ (p2 - lst[0]);
    if(sgn(tmp) > 0)return true;
    else if(sgn(tmp) == 0 && sgn(dist(p1, lst[0]) - dist(p2, lst[0])) <= 0)
        return true;
    else return false;
}
void Graham(int n)
{
    point p0;
    int k = 0;
    p0 = lst[0];
    //找最下边的一个点
    for(int i = 1; i < n; i++)
    {
        if( (p0.y > lst[i].y) || (p0.y == lst[i].y && p0.x > lst[i].x) )
        {
            p0 = lst[i];
            k = i;
        }
    }
    swap(lst[k], lst[0]);
    sort(lst + 1, lst + n, _cmp);
    if(n == 1)
    {
        top = 1;
        Stack[0] = 0;
        return;
    }
    if(n == 2)
    {
        top = 2;
        Stack[0] = 0;
        Stack[1] = 1;
        return ;
    }
    Stack[0] = 0;
    Stack[1] = 1;
    top = 2;
    for(int i = 2; i < n; i++)
    {
        while(top > 1 && sgn((lst[Stack[top - 1]] - lst[Stack[top - 2]]) ^ (lst[i] - lst[Stack[top - 2]])) <= 0)
            top--;
        Stack[top++] = i;
    }
}
const double PI = acos(-1.0);
#define zero(x) ((fabs(x) < eps ? 1 : 0))
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}

struct point
{
    double x, y;
    point(double a = 0, double b = 0)
    {
        x = a, y = b;
    }
    point operator-(const point &b) const
    {
        return point(x - b.x, y - b.y);
    }
    point operator+(const point &b) const
    {
        return point(x + b.x, y + b.y);
    }
    // 两点是否重合
    bool operator==(point &b)
    {
        return zero(x - b.x) && zero(y - b.y);
    }
    // 点积(以原点为基准)
    double operator*(const point &b) const
    {
        return x * b.x + y * b.y;
    }
    // 叉积(以原点为基准)
    double operator^(const point &b) const
    {
        return x * b.y - y * b.x;
    }
    // 绕P点逆时针旋转a弧度后的点
    point rotate(point b, double a)
    {
        double dx, dy;
        (*this - b).split(dx, dy);
        double tx = dx * cos(a) - dy * sin(a);
        double ty = dx * sin(a) + dy * cos(a);
        return point(tx, ty) + b;
    }
    // 点坐标分别赋值到a和b
    void split(double &a, double &b)
    {
        a = x, b = y;
    }
};
struct line
{
    point s, e;
    line() {}
    line(point _s, point _e)
    {
        s = _s;
        e = _e;
    }
    //两直线相交求交点
    //第一个值为0表示直线重合，为1表示平行，为0表示相交,为2是相交
    //只有第一个值为2时，交点才有意义
    pair<int, point> operator &(const line &b)const
    {
        point res = s;
        if(sgn((s - e) ^ (b.s - b.e)) == 0)
        {
            if(sgn((s - b.e) ^ (b.s - b.e)) == 0)
                return make_pair(0, res); //重合
            else return make_pair(1, res); //平行
        }
        double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
        res.x += (e.x - s.x) * t;
        res.y += (e.y - s.y) * t;
        return make_pair(2, res);
    }
};
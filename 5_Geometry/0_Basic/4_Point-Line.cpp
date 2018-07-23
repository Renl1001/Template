//点到直线距离
//返回为result,是点到直线最近的点
point PointToLine(point P, line L)
{
    point result;
    double t = ((P - L.s) * (L.e-L.s)) / ((L.e-L.s) * (L.e-L.s));
    result.x = L.s.x + (L.e.x - L.s.x) * t;
    result.y = L.s.y + (L.e.y - L.s.y) * t;
    return result;
}
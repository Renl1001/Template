//有equ个方程，var个变元。增广矩阵行数为equ,列数为var+1,分别为0到var
int a[MAXN][MAXN]; 
int b[MAXN][MAXN];
//返回值为-1表示无解，为0是唯一解，否则返回自由变元个数
int Gauss(int equ, int var)
{
    int max_r, col, k;
    for(k = 0, col = 0 ; k < equ && col < var ; k++, col++)
    {
        max_r = k;
        for(int i = k + 1; i < equ; i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        }
        if(a[max_r][col] == 0)
        {
            k--;
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var + 1; j++)
                swap(a[k][j], a[max_r][j]);
        }
        for(int i = k + 1; i < equ; i++)
        {
            if(a[i][col] != 0)
            {
                for(int j = col; j < var + 1; j++)
                    a[i][j] ^= a[k][j];
            }
        }
    }
    return k;
}
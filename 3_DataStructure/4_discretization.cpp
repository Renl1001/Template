int num[maxn];
for(int i = 0; i < n;i ++)
{
    cin >> num[i];
    id.push_back(num[i]);
}
sort(id.begin(), id.end());//为二分搜索排序
//去重让每一个值都是单一的
id.erase(unique(id.begin(), id.end()) , id.end());

//把值改变成编号，映射回来的方法 id[num[i] - 1];
for(int i = 0;i < n;i ++)
    num[i] = lower_bound(id.begin(), id.end(), num[i]) - id.begin() + 1;

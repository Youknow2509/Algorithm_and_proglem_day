int searchElement02(std::vector<std::vector<int>> a, int k)
{
    std::vector<int> b;
    int m = a.size();
    int n = a[0].size();
    for (int i = 0; i<m; i++)
    for (int j = 0; j<n; j++)
    b.push_back(a[i][j]);
    sort(b.begin(), b.end());
    int h = 1;
    if (k == 1)
        return b[0];
    for (int i = 1; i < b.size(); i++)
    if (b[i] != b[i-1]){
        h++;
        if (h == k)
            return b[i];
    }
    return -1;
}
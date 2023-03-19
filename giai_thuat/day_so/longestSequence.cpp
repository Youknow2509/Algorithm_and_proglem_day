int longestSequence(std::vector<int> a)
{
    int len = a.size(),
        res = 2;
    if (len <=2)
       return len;   
    for (int i = 0; i < len - 1; i++){
        for (int j = i + 1; j < len; j++){
            int step = a[j] - a[i],
            e = a[j],
            c = 2;
            for (int k = j + 1; k < len; k++){
                if (e + step == a[k]){
                    c++;
                    e = a[k];
                }
            }
            res = res >= c ? res : c;
        }
    }
    return res;
}
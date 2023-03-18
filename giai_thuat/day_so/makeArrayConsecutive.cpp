std::vector<int> a;
    sort(sequence.begin(), sequence.end());
    int k = sequence[0];
    int h=0;
    while(k!=sequence[sequence.size()-1]){
        if (k==sequence[h]){
            k++;
            h++;
        }
        else{
            while(k!=sequence[h]){
                a.push_back(k);
                k++;
            }
        }
    }
    return a;
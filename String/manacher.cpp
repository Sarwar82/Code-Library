vector<int>manacher_odd(string &s)
{
    int n = s.size();
    vector<int>v(n, 1);
    int l = 0, r = -1;
    for(int i = 0; i < n; i ++){
        int k;
        if(i > r) k = 1;
        else k = min(v[l + r - i], r - i + 1);
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]){
            k ++;
        }
        v[i] = k;
        if(i + k - 1 > r){
            r = i + k - 1;
            l = i - k + 1;
        }
    }
    return v;
}

vector<int>manacher_even(string &s)
{
    int n = s.size();
    vector<int>v(n);
    int l = 0, r = -1;
    for(int i = 0; i < n; i ++){
        int k;
        if(i > r) k = 0;
        else k = min(v[l + r - i + 1], r - i + 1);
        while(i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k ++;
        v[i] = k;
        if(i + k - 1 > r){
            r = i + k - 1;
            l = i - k;
        }
    }
    return v;
}

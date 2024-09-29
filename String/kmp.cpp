vector<int>kmp(string &s)
{
    int n = s.size();
    vector<int>lps(n);
    for(int i = 1; i < n; i ++){
        int j = lps[i - 1];
        while(j >= 0 && s[i] != s[j]){
            if(j == 0) j = -1;
            else j = lps[j - 1];
        }
 
        lps[i] = ++j;
    }
 
    return lps;
}

// matched upto ith charecter...transition if next charecter is ch
int f(int i, char ch, vector<int>&lps, string &s)
{
    while(i >= 0 && s[i] != ch){
        if(i == 0) i = -1;
        else i = lps[i - 1];
    }
    return i + 1;
}

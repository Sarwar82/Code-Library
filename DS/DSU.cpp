struct dsu{
    vector<int>par;
    dsu(){}
    dsu(int n){
        par.resize(n + 1);
        for(int i = 1; i <= n; i ++) par[i] = i;
    }
 
    int find(int x){
        if(x == par[x]) return par[x];
        return par[x] = find(par[x]);
    }
 
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return;
        par[v] = u;
    }
 
    bool f(int u, int v){
        u = find(u), v = find(v);
        return u == v;
    }
};

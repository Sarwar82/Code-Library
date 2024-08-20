struct node{
    int a, b;
    node(){
        a = INT_MAX, b = INT_MIN;
    }
    node(int A, int B){
        a = A, b = B;
    }
};
void combine(node&x, node&y, node&z)
{
    x.a = min(y.a, z.a);
    x.b = max(y.b, z.b);
    return;
}
node st[4 * N];
void update(int v, int l, int r, int pos, node val)
{
    if(l > r) return;
    if(l == r){
        st[v] = val;
        return;
    }

    int m = (l + r) / 2;
    if(pos <= m) update(v * 2, l, m, pos, val);
    else update(v * 2 + 1, m + 1, r, pos, val);
    combine(st[v], st[v * 2], st[v * 2 + 1]);
}

node query(int v, int l, int r, int L, int R)
{
    node ans;
    if(l > r || L > R || L > r || l > R) return ans;
    if(L <= l && r <= R) return st[v];
    int m = (l + r) / 2;
    node x = query(v * 2, l, m, L, R);
    node y = query(v * 2 + 1, m + 1, r, L, R);
    combine(ans, x, y);
    return ans;
}

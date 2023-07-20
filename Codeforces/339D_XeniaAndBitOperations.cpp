# include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int height;
    int n;
    vector <int> st;
    void init(int _n, int _h){
        this->height = _h;
        this->n = _n;
        st.resize(4 * n, 0);
    }
    void build(int start, int ending, int node, vector <int> &a, int h){
        if (start == ending){
            st[node] = a[start];
            return;
        }
        int mid = (start + ending)/2;
        build(start, mid, node * 2 + 1, a, h + 1);
        build(mid + 1, ending, node * 2 + 2, a, h + 1);
        if ((height - h) & 1){
            st[node] = (st[node * 2 + 1] | st[node * 2 + 2]);
        }
        else{
            st[node] = (st[node * 2 + 1] ^ st[node * 2 + 2]);
        }
    }
    void build(vector <int> &a){
        build(0, a.size() - 1, 0, a, 0);
    }
    int query(int start, int ending, int node, int l, int r, int h){
        if (l == start && r == ending) return st[node];
        if (l > r) return 0;
        int mid = (start + ending)/2;
        int q1 = query(start, mid, node * 2 + 1, l, min(r, mid), h + 1);
        int q2 = query(mid + 1, ending, node * 2 + 2, max(l, mid + 1), r, h + 1);
        return ((height - h) & 1) ? (q1 | q2) : (q1 ^ q2);
    }
    int query(int l, int r){
        return query(0, n - 1, 0, l - 1, r - 1, 0);
    }
    void update(int start, int ending, int node, int pos, int val, int h){
        if (start == ending){
            st[node] = val;
            return;
        }
        int mid = (start + ending)/2;
        if (pos <= mid){
            update(start, mid, node * 2 + 1, pos, val, h + 1);
        }
        else{
            update(mid + 1, ending, node * 2 + 2, pos, val, h + 1);
        }
        if ((height - h) & 1){
            st[node] = (st[node * 2 + 1] | st[node * 2 + 2]);
        }
        else{
            st[node] = (st[node * 2 + 1] ^ st[node * 2 + 2]);
        }
    }
    void update(int pos, int val){
        update(0, n - 1, 0, pos - 1, val, 0);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, e;
    cin >> n >> m;
    vector <int> a;
    for (int i = 0; i < (1 << n); i++){
        cin >> e;
        a.push_back(e);
    }
    SegmentTree tree;
    tree.init(a.size(), n);
    tree.build(a);  
    for (int i = 0; i < m; i++){
        int pos, val, ans;
        cin >> pos >> val;
        tree.update(pos, val);
        ans = tree.query(1, a.size());
        cout << ans << '\n';
    }
}

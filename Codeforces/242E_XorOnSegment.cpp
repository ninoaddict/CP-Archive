# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree{
    ll n;
    vector <ll> st;
    vector <ll> lazy;
    void init(ll _n){
        this->n = _n;
        st.resize(n * 4, 0);
        lazy.resize(n * 4, 0);
    }
    void build(ll begin, ll ending, ll node, vector <ll> &a){
        if (begin == ending){
            st[node] = a[begin];
            return;
        }
        ll mid = (begin + ending)/2;
        build(begin, mid, node * 2 + 1, a);
        build(mid + 1, ending, node * 2 + 2, a);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
        return;
    }
    void build(vector <ll> &a){
        build(0, n - 1, 0, a);
    }
    void update(ll start, ll ending, ll node, ll l, ll r){
        if (lazy[node]){
            st[node] = (ending - start + 1) - st[node];
            if (start != ending){
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] ^ 1);
                lazy[node * 2 + 2] = (lazy[node * 2 + 2] ^ 1);
            }
            lazy[node] = lazy[node] ^ 1;
        }
        if (l > r) return;
        if (start == l && ending == r){
            st[node] = (ending - start + 1) - st[node];
            if (start != ending){
                lazy[node * 2 + 1] = lazy[node * 2 + 1] ^ 1;
                lazy[node * 2 + 2] = lazy[node * 2 + 2] ^ 1;
            }
            return;
        }
        ll mid = (start + ending)/2;
        update(start, mid, node * 2 + 1, l, min(r, mid));
        update(mid + 1, ending, node * 2 + 2, max(l, mid + 1), r);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }
    void update(ll l, ll r){
        update(0, n - 1, 0, l - 1, r - 1);
    }
    ll query(ll start, ll ending, ll node, ll l, ll r){
        if (l > r) return 0;
        if (lazy[node]){
            st[node] = (ending - start + 1) - st[node];
            if (start != ending){
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] ^ 1);
                lazy[node * 2 + 2] = (lazy[node * 2 + 2] ^ 1);
            }
            lazy[node] = lazy[node] ^ 1;
        }
        if (start == l && ending == r){
            return st[node];
        }
        ll mid = (start + ending)/2;
        ll q1 = query(start, mid, node * 2 + 1, l, min(r, mid));
        ll q2 = query(mid + 1, ending, node * 2 + 2, max(l, mid + 1), r);
        return q1 + q2;
    }
    ll query(ll l, ll r){
        return query(0, n - 1, 0, l - 1, r - 1);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, t;
    cin >> n;
    vector<vector<ll>> a(20, vector <ll> (n, 0));
    for (ll i = 0; i < n; i++){
        ll e;
        cin >> e;
        for (ll j = 0; j < 20; j++){
            if (e & (1 << j)){
                a[j][i] = 1;
            }
        }
    }
    SegmentTree tree[20];
    for (ll i = 0; i < 20; i++){
        tree[i].init(n);
    }
    for (ll i = 0; i < 20; i++){
        tree[i].build(a[i]);
    }
    cin >> t;
    while (t--){
        ll q, l, r, x;
        cin >> q >> l >> r;
        if (q == 1){
            ll res = 0;
            for (ll j = 0; j < 20; j++){
                res += tree[j].query(l, r) * (1 << j);
            }
            cout << res << '\n';
        }
        else{
            cin >> x;
            for (ll j = 0; j < 20; j++){
                if (x & (1 << j)){
                    tree[j].update(l, r);
                }
            }
        }
    }
}

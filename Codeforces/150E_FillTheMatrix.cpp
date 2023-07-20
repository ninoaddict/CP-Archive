# include <bits/stdc++.h>
# define int long long int
using namespace std;

void solve(){
    int n, m, res = 0;
    cin >> n;
    vector <vector<int>> row(n + 1);
    vector <int> a(n);
    vector <int> seg(n + 1, 0);
    set <int> st;
    st.insert(-1);
    st.insert(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        row[a[i]].push_back(i);
    }
    cin >> m;
    seg[n] = n;
    for (int i = n; i > 0; i--){
        for (int j : row[i]){
            auto L = *prev(st.lower_bound(j));
            auto R = *st.lower_bound(j);
            seg[R - L - 1] -= i;
            seg[R - j - 1] += i;
            seg[j - L - 1] += i;
            st.emplace(j);
        }
    }
    for (int i = n; i > 0; i--){
        int cnt = min(m/i, seg[i]);
        res += (i - 1) * cnt;
        m -= (cnt * i);
        if (m > 0 && cnt != seg[i]){
            res += (m - 1);
            m = 0;
            break;
        }
    }
    cout << res <<'\n';
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}

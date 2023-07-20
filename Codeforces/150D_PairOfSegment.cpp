# include <bits/stdc++.h>
# define int long long int
using namespace std;

bool compare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second < b.second;
}

void solve(){
    int n;
    cin >> n;
    vector <pair<int,int>> seg, allPair;
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        seg.push_back({l, r});
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (min(seg[i].second, seg[j].second) >= max(seg[i].first, seg[j].first)){
                allPair.push_back({min(seg[i].first, seg[j].first), max(seg[i].second, seg[j].second)});
            }
        }
    }
    sort(allPair.begin(), allPair.end(), compare);
    int right = -1, cnt = 0;
    for (auto p : allPair){
        if (right < p.first){
            cnt++;
            right = p.second;
        }
    }
    cout << n - (cnt * 2) << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

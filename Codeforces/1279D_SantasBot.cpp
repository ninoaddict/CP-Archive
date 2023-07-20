# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int main(){
    ll n;
    cin>>n;
    unordered_map <ll,ll> mp;
    vector<ll> arr[n + 5];
    for (ll i = 0; i < n; i++){
        ll sz;
        cin>>sz;
        for (ll j = 0; j < sz;j++){
            ll num;
            cin>>num;
            mp[num]++;
            arr[i].push_back(num);
        }
    }
    ll res = 0;
    for (ll i = 0; i < n; i++){
        ll tempRes = 0;
        for (auto e : arr[i]){
            tempRes = (tempRes + mp[e] * binpow(n, MOD - 2, MOD)) % MOD;
        }
        tempRes = (tempRes * binpow(arr[i].size(), MOD - 2, MOD)) % MOD;
        res = (res + tempRes) % MOD;
    }
    res = (res * binpow(n, MOD - 2, MOD)) % MOD;
    cout<<res<<'\n';
}

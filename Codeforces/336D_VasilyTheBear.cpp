# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7, maxN = 1e6;

ll fact[maxN];

ll binpow(ll a, ll b, ll mod){
    ll res = 1;
    while (b){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

void precomp(){
    fact[0] = 1;
    for (ll i = 1; i < maxN; i++){
        fact[i] = (i*fact[i - 1]) % MOD;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    precomp();
    ll n, m, q, res = 0;
    // n = banyak 0, m = banyak 1, q = query
    cin >> n >> m >> q;
    if (!n){
        if (m == 1 && q == 1 || m > 1 && q == 0) res++;
    }
    else if (!m) {
        if (n % 2 == 0 && q == 1 || n % 2 == 1 && q == 0) res++;
    }
    else{
        for (ll k = 1; k <= n; k+=2){
            if (n + m - k - 1 > 0){
                res += (fact[n + m - k - 1] * binpow((fact[n - k] * fact[m - 1]) % MOD, MOD - 2, MOD)) % MOD;
                res %= MOD;
            }
        }
        if ((n & 1) == 0 && m == 1){
            res = (res + 1) % MOD;
        }
        if (!q){
            res = ((fact[n + m] * binpow((fact[n] * fact[m]) % MOD, MOD - 2, MOD)) + MOD - res) % MOD;
        }
    }
    cout<<res<<'\n';
}

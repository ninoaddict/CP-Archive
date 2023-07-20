# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector <bool> place (n + 5, false);
    vector <bool> number (n + 5, false);
    ll dp[n + 5];
    for (ll i = 1; i <= n; i++){
        ll num;
        cin>>num;
        if (num != -1){
            place[i] = true;
            number[num] = true;
        }
    }
    ll b = 0, g = 0;
    for (ll i = 1; i <= n; i++){
        if (!place[i]){
            if (number[i]) g++;
            else b++;
        }
    }
    dp[0] = 1;
    for (ll i = 1; i <= g; i++) dp[0] = (dp[0] * i) % MOD;
    dp[1] = (dp[0] * g) % MOD;
    for (ll i = 2; i <= b; i++){
        dp[i] = (g * dp[i - 1] + (i - 1)*(dp[i - 1] + dp[i - 2])) % MOD;
    }
    cout<<dp[b]<<'\n';
}

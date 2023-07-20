# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll maxN = 2e5 + 7;
 
ll N, arr[maxN];
bool visited[maxN];
 
void solve(){
    cin>>N;
    ll acg = 0, cg = 0;
    for (ll i = 0; i < N; i++){
        cin>>arr[i];
        arr[i]--;
        visited[i] = false;
    }
    for (ll i = 0; i < N; i++){
        if (!visited[i]){
            ll e = i, p = i, pp = -1;
            bool ck = false;
            while (!visited[e]){
                visited[e] = true;
                pp = p;
                p = e;
                e = arr[e];
            }
            if (e == pp) acg++;
            else if (e == i) cg++;  
        }
    }
    ll cmp = 0;
    if (acg > 0) cmp = 1;
    cout<<cg + cmp<<' '<<acg + cg<<'\n';
}
 
int main(){
    ll t;
    cin>>t;
    while (t--){
        solve();
    }
}

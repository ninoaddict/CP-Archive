# include <bits/stdc++.h>
# define int long long int
using namespace std;

class Graph{
    vector<vector<int>> adj;
    vector<int> parent;
    vector<bool> vis;
    int n;
public:
    Graph(int n){
        this->n = n;
        adj.resize(n + 1);
        vis.resize(n + 1, false);
        parent.resize(n + 1, -1);
    }
    void addEdge(int x, int y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    void bfs(int src = 1){
        queue <int> q;
        q.push(src);
        vis[src] = true;
        parent[src] = src;
        while (!q.empty()){
            int v = q.front();
            q.pop();
            for (auto u : adj[v]){
                if (!vis[u]){
                    q.push(u);
                    parent[u] = v;
                    vis[u] = true;
                }
            }
        }
    }
    void check(vector <int> &a){
        if (a[0] != 1){
            cout << "No" << '\n';
            return;
        }
        vector <int> order(n + 1, INT_MAX);
        order[1] = 0;
        for (int i = 1; i < n; i++){
            order[a[i]] = i; 
            if (order[parent[a[i]]] == INT_MAX || order[parent[a[i - 1]]] > order[parent[a[i]]]){ // If child visited before parent or order is non increasing
                cout << "No" <<'\n';
                return;
            }
        }
        cout << "Yes" <<'\n';
        return;
    }
};

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Graph graph(n);
    vector <int> a(n);
    for (int i = 0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        graph.addEdge(a,b);
    }
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    graph.bfs();
    graph.check(a);
}

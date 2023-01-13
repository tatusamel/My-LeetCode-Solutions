
// https://algoleague.com/contest/algorithm-competition-winter-camp-2022-upsolving-contest/problem/path-suggestions/detail



#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <stack>

using namespace std;

using ll = long long;
const ll INF = 1e18;


/*
 DIJKSTRA's shortest path:
    -> bize ne lazim?
    -> 1 den n.node'a en kisa nasil giderim onu bulacagim
    -> dist[n] arrayi ve her dist[i] = INT_MAX olacak
    -> dist[1] = 0, cunku kendisine 0 la gelir
    -> edgeListe gerek yok.
    -> adjacency liste gerek var. adj olustur
 
    -> ve min heap kullaniriz ki, her zaman en kucuk yoldan
    -> ilerleyelim diye.
    -> ilk once tum 1'den diger nodelara olan edgeleri heape ekle
    -> sonra heap bos degilken:
        -> en kucuk edgei pop et ve bu edgein toNodeundan nerelere gidebiliriz diye bak
        -> sonra gidebilecegimiz yerleri tekrar bu listeye koy
 
    -> ayni zamanda bunlari yaparken de dist[n] arrayini guncelle
    -> bu sayede surekli 1den i.elemana gidilen en kucuk disti buluruz
 
    
 */

/*
 5 6
 1 2 4
 1 3 6
 2 4 1
 4 5 2
 2 5 2
 1 5 7
 */

vector<ll> dijkstra(vector<vector<pair<int,int>>>& adj, int n, int s) {
    
    
    vector<ll> dist(n+1,INF);
    
    // weight, toNode
    // ancak weightler negatif olarak konulacak
    priority_queue<pair<ll,int>> heap;
    
    // visited de olmamasi gerekiyor. yoksa loop
    vector<bool> vis(n+1,false);
    
    // ya da sanki 0'dan 1'e gidiyormus gibi dusunebiliriz
    // 0 dan 1e gidiyoruz 0 agirligi ile
    heap.push({-0,s});
    dist[s] = 0;
    
    while ( !heap.empty() ) {
        
        ll w = -heap.top().first;// weight
        int u = heap.top().second; // toNode
        heap.pop();
        
        // sonra artik buradan nerelere gidebiliriz diye bakip kontrol edecegiz
        
        if ( vis[u] ) continue;
        vis[u] = true;
        
        for ( auto p : adj[u] ) {
            int v = p.first;
            ll w2 = p.second;
            
            if ( w + w2 < dist[v] ) {
                dist[v] = (ll)w+w2;
                heap.push({-dist[v],v});
            }
        }
    }
    return dist;
    
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,s,d;
    cin >> n >> m >> s >> d;
    
    // adjList olusturalim
    // u -> {v,w}
    vector<vector<pair<int,int>>> adj(n+1);
    for ( int i = 0 ; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    // distance to all nodes from source node
    vector<ll> distS = dijkstra(adj, n, s);
    // distance from all nodes to destination node
    // since it's a undirected graph, can be calcualted both ways
    vector<ll> distD = dijkstra(adj, n, d);
    
    int q; cin >> q;
    while ( q-- ) {
        
        int u,v,w; cin >> u >> v >> w;
        
        
        // cevap :
        // s ---------> d
        // s ---------> a -> b ----------> d
        // s ---------> b -> a ----------> d
        // bu ucunden biri olabilir
        // o yuzden basta bir calculation yapip hep onlari kullaniyoruz.
        ll ans = min( {distS[d], distS[u] + w + distD[v], distS[v] + w + distD[u] });
        cout << ans << '\n';
    }
    
    
    
}


/*
 // it means better than that.
 // but i might be superior also j might be superior
 auto better = [&](int i, int j) {
     int cnt = 0;
     for (int k = 0; k < 5; k++) {
         if ( arr[i][k] < arr[j][k] )cnt++;
     }
     return cnt >= 3;
 };
 */

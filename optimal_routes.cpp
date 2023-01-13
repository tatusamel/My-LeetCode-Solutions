https://algoleague.com/contest/algorithm-competition-winter-camp-2022-upsolving-contest/problem/optimal-routes/detail


#include <bits/stdc++.h>

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

void dijkstra(vector<vector<pair<int,int>>>& adj, int n, int m) {
    
    
    vector<ll> dist(n+1,INF);
    
    // weight, toNode
    // ancak weightler negatif olarak konulacak
    priority_queue<pair<ll,int>> heap;
    
    // visited de olmamasi gerekiyor. yoksa loop
    vector<bool> vis(n+1,false);
    
    // ya da sanki 0'dan 1'e gidiyormus gibi dusunebiliriz
    // 0 dan 1e gidiyoruz 0 agirligi ile
    for ( int i = n-m+1; i <= n; i++) {
        heap.push({-0,i});
        dist[i] = 0;
    }
    
    
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
                dist[v] = (ll) w+w2;
                heap.push({-dist[v],v});
            }
        }
    }
    for (int i = 1; i <= n-m; i++) {
        cout << dist[i] << ' ';
    }
    
}
int main() {
    
    int n,m,k;
    cin >> n >> m >> k;
    
    // adjList olusturalim
    // u -> {v,w}
    vector<vector<pair<int,int>>> adj(n+m+1);
    for ( int i = 0 ; i < k; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    dijkstra(adj, n+m, m);
    
    
    
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

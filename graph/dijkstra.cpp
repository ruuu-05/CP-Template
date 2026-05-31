#include <iostream>
#include <bits/stdc++.h>  

using namespace std;

 
 
#define nl "\n"
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fixed(n) fixed << setprecision(n)






const long double pi = acosl(-1.0L);
const int N = 1e5 +5; 

const ll INF  = 1e18;



ll n  , m  , k , q ; 

 

vector<pair<ll,ll>> adj[N];
ll par[N];
ll dis[N];


void dijkstra(int v){
  priority_queue< pair<ll,int> , vector<pair<ll,int>> , greater<> > pq ;
  dis[v]=0;
  pq.push({0,v});

  while(!pq.empty()){
    int curr = pq.top().second ;
    ll d = pq.top().first ;
    pq.pop();
    if ( d!= dis[curr]) continue; 
    for( auto u : adj[curr]){
      if(dis[u.first] > d + u.second){
        dis[u.first] = d + u.second;
        par[u.first] = curr ;
        pq.push({dis[u.first],u.first});
      }
    }
  }
}

void solve(){

  cin>>n>>m;
  for(int i = 0 ; i < n ; i++){
    dis[i+1]=INF; par[i+1]=-1;
  }
  for(int i = 0 ; i < m ; i++){
    int a , b ; ll w ; 
    cin>>a>>b>>w;
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});

  }
  dijkstra(1);
  if(dis[n]==INF){
    cout<<-1;
    return; 
  }
  vector<ll> ans;
  ll curr = n;
  while(par[curr]!=-1){
    ans.push_back(curr);
    curr = par[curr];
  }
  ans.push_back(1);
  reverse(all(ans));
  for(int x : ans)cout<<x<<" ";



}



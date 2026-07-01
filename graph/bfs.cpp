#include <iostream>
#include <bits/stdc++.h>  

using namespace std;

 
 
#define nl "\n"
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fixed(n) fixed << setprecision(n)






const long double pi = acosl(-1.0L);
const int MOD = 998244353 ;
const ll INF  = 2e6 ;
const int N = 1e5+1;



ll n  , m  , k , q ;

 

 
template<typename T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto &x : v) {
        in >> x;  
    }
    return in;
}


 
 
void fastio(){
#ifndef ONLINE_JUDGE
  freopen("C:\\Users\\EgyTech\\Desktop\\cp\\input.txt", "r", stdin);
  freopen("C:\\Users\\EgyTech\\Desktop\\cp\\output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}



vector<int> dx = {0 , 0 , 1 , -1};
vector<int> dy = {1 , -1 , 0 , 0};



vector<vector<int>> adj;
vector<int> dis;
vector<int> ans;
int prnt[N];

void bfs(int s ){
  queue<int> qq ;
  qq.push(s);
  dis[s]=0;
  while(!qq.empty()){
    int v = qq.front();
    qq.pop();
    for(int u : adj[v]){
      if(dis[u] > dis[v]+1){
        dis[u]=dis[v]+1 ;
        prnt[u]=v;
        qq.push(u);
      }

    }
    
  }
}


void solve(){
  cin>>n>>m;
  int s , e ;
  cin>>s>>e;
  adj.assign(n+1,vector<int>());
  dis.assign(n+1,INF);
  for(int i = 0 ; i < m ; i++){
  int a , b ; 
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bfs(s);
  vector<int> ans;
  if(dis[e]==INF){
    cout<<-1;
    return;
  }
  cout<<dis[e]<<nl;
  int curr = e ;
  while(curr!= s){
    ans.push_back(curr);
    curr = prnt[curr];
  }
  ans.push_back(s);
  reverse(all(ans));
  for(int x : ans)cout<<x<<" ";



}

 
int main() {
    fastio();
  ll tc = 1;
  //cin>>tc;


while(tc--){
  solve();
}
  return 0;
}





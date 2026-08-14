#include <iostream>
#include <bits/stdc++.h>  

using namespace std;

 
 
#define nl "\n"
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fixed(n) fixed << setprecision(n)
#define int long long
#define sp " "




const long double pi = acosl(-1.0L);
const ll MOD = 1e9 +  7 ;
const ll INF  = 0x3f3f3f3f3f3f3f3fLL;
const int N = 2e6 + 5  ;

ll n  , m  , k , q ;

 

 


//MOD OPERATIONS
ll add(ll a, ll b, ll mod=MOD) {return ((a % mod) + (b % mod)) % mod;}
ll mul(ll a, ll b, ll mod=MOD) {return ((a % mod) * (b % mod)) % mod;}
ll sub(ll a, ll b) {return (((a - b) % MOD) + MOD) % MOD;}
ll modExp(ll a, ll b) {
    if (b <= 0) return 1;
    ll ret = modExp(a * a % MOD, b / 2);
    if (b % 2) ret = ret * a % MOD;
    return ret;
}
ll inverse(ll b) {return modExp(b, MOD - 2);}
ll divv(ll a, ll b) {return ((a % MOD) * (inverse(b) % MOD)) % MOD;}


const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

//############################

 
 
void fastio(){
#ifndef ONLINE_JUDGE
  freopen("C:\\Users\\EgyTech\\Desktop\\cp\\input.txt", "r", stdin);
  freopen("C:\\Users\\EgyTech\\Desktop\\cp\\output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}


//##############################################################


/*

custom sort
bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first < b.first; // Primary key: Ascending X
    }
    return a.second > b.second;   // Secondary key: Descending Y
}

*/


/////////////////////////////////////////////////////////////////////




void solve(){

} 


signed main() {
    fastio();
  ll tc = 1;
  cin>>tc;

while(tc--){
  solve();
}
  return 0;
}





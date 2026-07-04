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

ll saved[12][100][100][2][2] ; //i rem_d rem_n isA isB
string a , b , kk ;

int dp(int i , int rem_d , int rem_n , bool isA, bool isB){
  if(i == b.size()){
    return (rem_d == 0) && (rem_n == 0 );
  }
  ll &ret = saved[i][rem_d][rem_n][isA][isB];
  if(~ret) return ret ;

  int lb = (isA?a[i]-'0':0);
  int ub = (isB?b[i]-'0':9);
  ret = 0 ;

  for(int d = lb ; d <= ub ; d++){
    ret += dp(i+1, (rem_d+d)%k , (rem_n * 10 + d)%k , isA && (d==a[i]-'0') , isB && (d==b[i]-'0') );
  }
  return ret ;


}



void solve(){
   cin>>a>>b>>kk;
  int aa , bb  ;
  aa = stoi(a);
  bb = stoi(b);
  k = stoi(kk);

  if(k > 90 ){
    cout<<0 <<nl;
    return;
  }
  if(k == 1 ){
    cout<<bb-aa+1<<nl;
    return;
  }
  a = string(b.size()-a.size(),'0') + a ;
  memset(saved , -1 , sizeof(saved));
  cout<<dp(0,0,0,1,1)<<nl;  //i rem_d rem_n isA isB
  
}


int main() {
    fastio();
  ll tc = 1;
  cin>>tc;
for(int tt = 1 ; tt <= tc ; tt++){
  cout<<"Case "<<tt<<": ";
   solve();
}
  return 0;
}



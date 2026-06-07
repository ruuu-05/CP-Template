#include <iostream>
#include <bits/stdc++.h>  

 
#define nl "\n"
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fixed(n) fixed << setprecision(n)

 
using namespace std;

// only union try to think in revrse on deleteing 
struct DSU{
    vector<int> parent, sz;
    int mxsz, cmps;
    DSU(int n){
        parent = sz = vector<int> (n);
        for(int i = 0 ; i < n ; i++)
            parent[i] = i, sz[i] = 1;
        
        mxsz = 1, cmps = n;
    }
    int find(int x){
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    void uni(int x, int y){
        x = find(x);
        y = find(y);
 
        if(x == y)
            return;
        
        if(sz[y] > sz[x])
            swap(x, y);
 
        parent[y] = x;
 
        sz[x]+= sz[y];
        mxsz = max(mxsz, sz[x]);
        cmps--;
    }
};


//----------MST---------------- 

//PRIM

//KRUSKAL [DSU]

struct edge
{
    int a, b;
    ll w;
};
 
bool operator< (edge& e1, edge& e2){
    return e1.w < e2.w;
}
bool operator> (edge& e1, edge& e2){
    return e1.w > e2.w;
}
 
vector<edge> edges;
int n ;

void kruskal(){
    DSU dsu(n);
    sort(all(edges));
    ll cost = 0;
    for(auto edg : edges){
        int x = edg.a, y = edg.b;
        if(dsu.find(x) != dsu.find(y)){
            cost+= edg.w;
            dsu.uni(x, y);
        }
    }
    if(dsu.cmps != 1)
        return void(cout << "IMPOSSIBLE" << endl);
    
    cout << cost << endl;
}

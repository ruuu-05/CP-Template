#include <iostream>
#include <bits/stdc++.h>  
 
using namespace std;


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

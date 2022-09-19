#include<bits/stdc++.h>
typedef long long int li;
using namespace std;

#define pll pair<li,pair<li,li>>

const li N = 1e5+10;
li parent[N];
li size[N];
void make(li v){
    parent[v] = v;
    size[v] = 1;
}

li find(li v){
    if(parent[v] == v)  return v;
    return parent[v] = find(parent[v]);
}

void unio(li a,li b){
     a = find(a);
     b = find(b);
     if(a!= b){
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

signed main(){
    li t;
    cin >> t;
    while(t--){
        li v,e;
        cin >> v >> e;
        
        for(li i = 0;i < v;i++) make(i);
        
        vector<pll> edges(e);
        
        for(li i = 0;i < e;i++) cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        
        li answer = 0;
        sort(edges.begin(),edges.end());
        for(li i = 0;i < e;i++){
            li op = edges[i].second.first;
            li pp = edges[i].second.second;
            if(find(op) != find(pp)){
                unio(op,pp);
                answer += edges[i].first;
            }
        }
        cout << answer << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
typedef long long int li;
using namespace std;

#define pll pair<int,pair<int,int>>
#define s second
#define f first

signed main(){
    li t;
    cin >> t;
	while(t--){
        li n,m;
        cin >> n >> m;
        vector<pll> edge;
        li src,des;
        cin >> src >> des;
        vector<li> dist(n+1,INT_MAX);
        li x,y,w;
        for(li i = 0;i < m;i++){
            cin >> x >> y >> w;
            edge.push_back({x,{y,w}});
        }
        dist[src] = 0;
        for(li i = 0;i < n-1;i++){
            for(li j = 0;j < m;j++){
                li a = edge[j].f;
                li b = edge[j].s.f;
                li wei = edge[j].s.s;
                if(dist[a] != INT_MAX && dist[b] > (dist[a] + wei)){
                    dist[b] = (dist[a] + wei);
                }
            }
        }
        if(dist[des] == INT_MAX){
            cout << 1000000000 << endl;
        }else{
            cout << dist[des] << endl;
        }
        
    }
    return 0;
}

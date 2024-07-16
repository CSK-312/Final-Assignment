#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> graph(n + 1);
    for(int i=0;i<m;i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    vector<long long> res(n + 1, LLONG_MAX);
    res[1]=0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int idx=pq.top().second;
        long long d=pq.top().first;
        pq.pop();
        if(d>res[idx]) continue;
        for(auto &edge:graph[idx]){
            int v=edge.first;     
            long long weight=edge.second; 
            if(res[idx]+weight<res[v]){
                res[v]=res[idx]+weight;
                pq.push({res[v],v});
            }
        }
    }
    for(int i=1;i<=n;++i){
        cout << res[i] << " ";
    }
    return 0;
}
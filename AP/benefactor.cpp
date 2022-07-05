#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int,int>> graph[50001];
vector<pair<int,int>> cl;

pair<int,int> bfs(int node, int nodes){
    int distance[nodes+1];
    fill(distance, distance+nodes+1, 0);
    
    bool vis[nodes+1];
    fill(vis, vis+nodes+1, 0);
    vis[node] = true;
    
    queue<int> q;
    q.push(node);
    
    
    //distance[node]=0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        //dist+=1;
        for(int i=0;i<graph[curr].size(); i++){
            int neigh = graph[curr][i].first;
            if(!vis[neigh]){
                distance[neigh] = distance[curr]+graph[curr][i].second;
                
                vis[neigh] = true;
                q.push(neigh);
            }
        }
    }
    int dist=0;
    int place=1;
    for(int i=1;i<nodes+1;i++){
        if(dist<distance[i]){
            dist=distance[i];
            place =i;
            //cout << distance[i] << " ";
        }
    }
    return(make_pair(place,dist));
}
int main(){
    int ntests;
    int nodes;
    int a,b,c;
    cin >> ntests;
    for (int i=0; i<ntests;i++){
        cin >> nodes;
        for (int j=0;j<nodes-1; j++){
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(b,c));
            graph[b].push_back(make_pair(a,c));
        }
        int point=1;
        int longest=0;
        pair<int,int> res;
        res = bfs(1,nodes);
        res = bfs(res.first,nodes);
        cout <<res.second << "\n";
        for(int j=0;j<nodes+1;j++){
            graph[j].clear();
        }
    }
    return 0;
}
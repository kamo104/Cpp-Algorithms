
//if cost of building a library is lower than the cost of building a road c_lib<=c_road
//build a library for every city

//if cost of building a library is higher than the cost of building a road c_lib>c_road
//for every single coherent component add one library
//figure out mst for a single coherent component and number of edges in this tree //tree bad, better number of cities in one component - 1

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#define MAXN 100001

using namespace std;

vector<int> graph[MAXN];
bool vis[MAXN];

int bfs(int node, int nodes){
    //int distance[nodes+1];
    //fill(distance, distance+nodes+1, 0);
    
    //bool vis[nodes+1];
    //fill(vis,vis+nodes+1,0);
    vis[node] = true;
    
    queue<int> q;
    q.push(node);
    int nvis=1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0;i<graph[curr].size(); i++){
            int neigh = graph[curr][i];
            if(!vis[neigh]){
                vis[neigh] = true;
                q.push(neigh);
                nvis +=1;
                
            }

            
        }
    }
    //when went through all the conections 
    return(nvis);
}



long solve(int ncities, int c_lib, int c_road){
    long result=0;
    for(int i=1;i<ncities+1;i++){
        if(vis[i]==false){
            result +=(bfs(i,ncities)-1)*c_road+c_lib;
        }
    }
    return(result);
}

int main(void){
    int ntests;
    int ncities,nroads,c_lib,c_road;
    int r1,r2;
    cin >> ntests;
    for(int i=0;i<ntests; i++){
        cin >> ncities >> nroads >> c_lib >> c_road;
        for(int j=0;j<ncities+1;j++){
            graph[j].clear();
        }
        fill(vis,vis+ncities+1,0);
        for(int j=0;j<nroads;j++){
            cin >> r1 >> r2;
            graph[r1].push_back(r2);
            graph[r2].push_back(r1);
            //cout << r1 << " " << r2 << "\n";
        }

        if(c_lib>c_road){
            cout << solve(ncities,c_lib,c_road) << "\n";
        }
        else{
            cout << c_lib*ncities << "\n";
        }
    }

    return(0);
}

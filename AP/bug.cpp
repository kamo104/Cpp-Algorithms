#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAXN 2001

vector<int> graph[MAXN];
bool vis[MAXN];
bool color[MAXN];

bool bfs(int node, int nodes){
    int distance[nodes+1];
    fill(distance, distance+nodes+1, 0);
    
    vis[node] = true;
    
    queue<int> q;
    q.push(node);
    
    while(!q.empty()){
        int curr = q.front();
        bool curr_col = color[curr];
        q.pop();
        for(int i=0;i<graph[curr].size(); i++){
            int neigh = graph[curr][i];
            if(!vis[neigh]){
                color[neigh]=curr_col?0:1;
                //distance[neigh] = distance[curr]+1;
                vis[neigh] = true;
                q.push(neigh);
            }
            else if(vis[neigh]&&curr_col==color[neigh])return(1);

            
        }
    }
    //when went through all the conections 
    return(0);
}

bool solve(int nbugs){

    for(int i=0;i<nbugs;i++){
        if(vis[i]==false){
            if(bfs(i,nbugs)){
                return(1);
            };
        }
    }

    return(0);
}
int main(){
    int ntests; 
    int nbugs, interactions, bug1, bug2;
    cin >> ntests;
    for (int i=0;i<ntests; i++){
        cin >> nbugs >> interactions;
        //set visited to all bugs as 0
        fill(vis, vis+nbugs+1,0);
        //color all bugs as 0
        fill(color,color+nbugs+1,0);
        //prepare clear graph
        for(int j=0;j<nbugs;j++){
            graph[j].clear();
        }

        //create graph
        for (int j=0;j<interactions;j++){
            cin >> bug1 >> bug2;
            graph[bug1].push_back(bug2);
            graph[bug2].push_back(bug1);
        }

        //output the answear
        cout << "Scenario #" << i+1 << ":\n";
        switch(solve(nbugs)){
            case(true):{
                cout << "Suspicious bugs found!\n";
                break;
            }
            case(false):{
                cout << "No suspicious bugs found!\n";
                break;
            }
        }
        
    }
    return 0;
}
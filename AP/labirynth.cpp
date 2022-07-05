#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
//vector<int> graph[10001];
//(*graph)
int point;

int bfs(int node, int nodes, vector<int> graph[], vector<int> to_search_list, vector<int> nodes_list){
    int distance[nodes+1];
    //fill(distance, distance+nodes+1, 0);
    for(int i=0;i<nodes_list.size();i++){
        distance[nodes_list[i]] = 0 ;
    }
    bool vis[nodes+1];
    //fill(vis, vis+nodes+1, 0);

    for(int i=0;i<nodes_list.size();i++){
        vis[nodes_list[i]] = false ;
    }

    vis[node] = true;
    
    queue<int> q;
    q.push(node);
    
    int dist=0;
    //distance[node]=0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        //dist+=1;
        for(int i=0;i<graph[curr].size(); i++){
            int neigh = graph[curr][i];
            if(!vis[neigh]){
                distance[neigh] = distance[curr]+1;
                vis[neigh] = true;
                q.push(neigh);
            }
        }
    }
    dist=0;
    for(int i=1;i<to_search_list.size();i++){
        dist<distance[to_search_list[i]]?dist=distance[to_search_list[i]]:dist=dist;
        if(dist<distance[to_search_list[i]]){
            dist=distance[to_search_list[i]];
            point = to_search_list[i];
        }
    }
    return(dist);
}
    
int main() {
    int tests, cols, rows;

    cin >> tests;
    for(int i=0;i<tests;i++){
        cin >> cols >> rows;
        char picture[rows][cols];
        //std::vector<int>* graph = new std::vector<int>[cols*rows];
        vector<int> graph[cols*rows];
        for(int j=0;j<rows;j++){
            for(int k=0;k<cols;k++){
                cin >> picture[j][k];
            }
        }
        vector<int> to_search_list;
        vector<int> nodes_list;
        for(int j=1;j<rows-1;j++){
            for(int k=1;k<cols-1;k++){
                if(picture[j][k]=='.'){
                    nodes_list.push_back(j*cols+k);
                    //check right, and bottom and append to graph based on j,k position
                    //right
                    if(picture[j][k+1]=='.'){
                        graph[j*cols+k].push_back(j*cols+k+1);
                        graph[j*cols+k+1].push_back(j*cols+k);
                    }
                    if(picture[j+1][k]=='.'){
                        graph[j*cols+k].push_back((j+1)*cols+k);
                        graph[(j+1)*cols+k].push_back(j*cols+k);
                    }
                    if(graph[j*cols+k].size()<2){
                        //cout << j << " " << k << "\n";
                        to_search_list.push_back(j*cols+k);
                    }
                }
            }
        }
        int max_dist=0;
        //int tmp;
        bfs(to_search_list[0],cols*rows, graph, to_search_list, nodes_list);
        max_dist = bfs(point,cols*rows, graph, to_search_list, nodes_list);
        /*
        for(int j=0;j<to_search_list.size();j++){
            tmp= bfs(to_search_list[j],cols*rows, graph, to_search_list, nodes_list);
            max_dist < tmp ? max_dist=tmp : max_dist=max_dist;
        }
        */
        cout << "Maximum rope length is " << max_dist << "." << "\n";

    }   
    return 0;
}
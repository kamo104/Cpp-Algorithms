#include <bits/stdc++.h>
#include <queue>
#include <tuple>
using namespace std;

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */

int prims(int n, vector<vector<pair<int,int>>> edges, int start) {
    auto compare = [](tuple<int,int,int> lhs, tuple<int,int,int> rhs)
                {
                    return get<0>(lhs) > get<0>(rhs);
                };
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,decltype(compare) > edges_queue(compare);
    bool vis[n+1];
    int visited = 1;
    fill(vis,vis+n+1,0);
    vis[start] = true;
    long answear =0;
    for(auto el:edges[start]){
        edges_queue.push(make_tuple(el.first,start,el.second));
    }
    while(visited++<n){
        while(!edges_queue.empty()){
            tuple<int,int,int> edge = edges_queue.top();
            edges_queue.pop();
            if(vis[get<1>(edge)]&&vis[get<2>(edge)])continue;

            else if(vis[get<1>(edge)]){
                //go to the second and add his neighbours to the queue
                answear+=get<0>(edge);
                
                //cout << get<0>(edge) << "\n";
                
                vis[get<2>(edge)] = true;
                for(auto el:edges[get<2>(edge)]){
                    edges_queue.push(make_tuple(el.first,get<2>(edge),el.second));
                }
                break;
            }
            else if(vis[get<2>(edge)]){
                //go to the first and add his neighbours to the queue
                answear+=get<0>(edge);
                
                //cout << get<0>(edge) << "\n";
                
                vis[get<1>(edge)] = true;
                for(auto el:edges[get<1>(edge)]){
                    edges_queue.push(make_tuple(el.first,get<1>(edge),el.second));
                }
                break;
            }
        }
    }
    return(answear);
}

int main(){
    int nvert, nedges;
    cin >> nvert >> nedges;
    vector<vector<pair<int,int>>> edges(nvert+1);
    int tmp1,tmp2,tmp3;
    for (int i=0;i<nedges;i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        edges[tmp1].push_back(make_pair(tmp3,tmp2));
        edges[tmp2].push_back(make_pair(tmp3,tmp1));
    }
    cin >> tmp1;
    cout << prims(nvert,edges,tmp1) << "\n";
    return 0;
}

//expected : 6359060 6348740
//59060-48740
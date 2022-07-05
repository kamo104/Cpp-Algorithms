#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;


// neighbours list for each node with weight
vector<vector<pair<int,int>>> graph;


long long dist(int from, int to){
    // long long s=0;
    auto compare = [](pair<int,int> el1, pair<int,int> el2){
        return(el1.second>el2.second);
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> q(compare);

    //bool vis[graph.size()];
    vector<bool> vis(graph.size()+100, 0);
    
    vis[from]=1;

    q.push(make_pair(from,0));

    while(!q.empty()){
        pair<int,int> el = q.top();
        q.pop();

        vis[el.first]=1;

        int sum=el.second;

        if(el.first==to) return sum;

        for(int i=0;i<graph[el.first].size();i++){
            if(!vis[graph[el.first][i].first]){
                
                q.push(make_pair(graph[el.first][i].first, graph[el.first][i].second+sum));
            }
        }
    }

    return 0;
}

int getWeight(string dir){
    return stoi(dir.substr(2,dir.length()-2));
}

// 0 for left, 1 for right, 2 for both
int getDirection(string dir){
    char left = dir[0];
    char right = dir[dir.length()-1];
    if(left=='<' && right=='>'){
        return 2;
    }
    if(right=='>'){
        return 1;
    }
    return 0;
}

int main(){

    int n, cars, roads;
    vector<pair<int,int>> tmp;

    vector<int> car_cities;

    // //unordered_map<string,int> map;
    map<string,int> map;


    string garage, car_city, c1, c2, direction;

    int testcase=1;

    while(cin >> n >> cars >> roads && n+cars+roads){
        

        for(int i=0;i<n+100;i++){
            graph.push_back(tmp);
        }
        int counter=0;

        cin >> garage;
        map.emplace(garage,counter++);

        for(int i=0;i<cars;i++){
            cin >> car_city;

            //add the city to our map
            if(map.count(car_city)<=0)
            map.emplace(car_city,counter++);

            car_cities.push_back(map.at(car_city));
        }

        for(int i=0;i<roads;i++){
            cin >> c1 >> direction >> c2;
            int weight = getWeight(direction);
            int dir = getDirection(direction);

            if(map.count(c1)<=0) map.emplace(c1, counter++);
            if(map.count(c2)<=0) map.emplace(c2, counter++);

            switch(dir){
                case(0):{
                    graph[map.at(c2)].push_back(make_pair(map.at(c1),weight));
                    break;
                }
                case(1):{
                    graph[map.at(c1)].push_back(make_pair(map.at(c2),weight));
                    break;
                }
                case(2):{
                    graph[map.at(c1)].push_back(make_pair(map.at(c2),weight));
                    graph[map.at(c2)].push_back(make_pair(map.at(c1),weight));
                    break;
                }
            }
            
        }


        long long sum=0;

        for(int i=0;i<car_cities.size();i++){
            sum += dist(map.at(garage),car_cities[i]);
            sum += dist(car_cities[i],map.at(garage));
        }

        

        cout << testcase++ << ". " << sum;

        for(int i=0;i<n+100;i++){
            graph[i].clear();
        }
        // graph.clear();
        // map.clear();
        car_cities.clear();
    }


    return 0;
}


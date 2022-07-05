#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2147483647
#define MAXN 21
pair<int,int> robot;
//vector<vector<int>> distances; //dynamicznie tworzyć
vector<pair<int,int>> walls;
vector<pair<int,int>> dirty;

int solve(int x, int y){
    int smallest_length = -1;

    for (auto el:dirty){
        dfs(x,y,el);
    }
    return(smallest_length);
}




int main() {
    int x,y;
    char tmp;
    
    while(true){
        cin>>x>>y;
        if(x==0&&y==0)break;
        walls.clear();
        dirty.clear();
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                cin >> tmp;
                switch(tmp){
                    case('o'):{
                        robot = make_pair(i,j);
                        break;
                    }
                    case('x'):{
                        walls.push_back(make_pair(i,j));
                        break;
                    }
                    case('*'):{
                        dirty.push_back(make_pair(i,j));
                        break;
                    }
                }
            }
        }
        cout << solve(x,y) << "\n";
    }  
    return 0;
}
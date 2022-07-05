#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 400

//vector<vector<char>> picture;
vector<vector<int>> result;

//n num of rows, m num of collumns
void custom_search(int n, int m, vector<pair<int,int>> ones_vect){

    //bool vis[n][m] = {};
    //for(auto el:ones_vect){vis[el.first][el.second] = 1;}

    queue<pair<int,int>> q;
    for(auto el:ones_vect){
        q.push(el);
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            //check top
            if(curr.first+1<n && result[curr.first+1][curr.second]>result[curr.first][curr.second]+1){
                q.push(make_pair(curr.first+1,curr.second));
                result[curr.first+1][curr.second] = result[curr.first][curr.second]+1;
            }
            //check bottom
            if(curr.first-1>=0 && result[curr.first-1][curr.second]>result[curr.first][curr.second]+1){
                q.push(make_pair(curr.first-1,curr.second));
                result[curr.first-1][curr.second] = result[curr.first][curr.second]+1;
            }
            //check right
            if(curr.second+1<m && result[curr.first][curr.second+1]>result[curr.first][curr.second]+1){
                q.push(make_pair(curr.first,curr.second+1));
                result[curr.first][curr.second+1] = result[curr.first][curr.second]+1;
            }
            //check left
            if(curr.second-1>=0 && result[curr.first][curr.second-1]>result[curr.first][curr.second]+1){
                q.push(make_pair(curr.first,curr.second-1));
                result[curr.first][curr.second-1] = result[curr.first][curr.second]+1;
            }
        }
    }
    
}
//
int main(){
    int ntests;
    int n,m;
    char tmp;

    vector<pair<int,int>> ones_vect;
    cin >> ntests;
    for(int i=0;i<ntests;i++){
        //picture.clear();
        result.clear();
        //tmp_c.clear();
        ones_vect.clear();
        cin >> n >> m;
        for(int j=0;j<n;j++){
            //cin >> tmp;
            //picture.push_back(tmp);
            for(int k=0;k<m;k++){
                cin >> tmp;
                //tmp_c.push_back(tmp);
                if(tmp=='1'){
                    ones_vect.push_back(make_pair(j,k));
                }
            }
            //picture.push_back(tmp_c);
            //tmp_c.clear();
            
        }
        vector<int> zero_setter(m);
        fill(zero_setter.begin(), zero_setter.end(), INT32_MAX);
        for(int j=0;j<n;j++){
            result.push_back(zero_setter);
        }
        //set result with zeros of ok length
        for(auto el:ones_vect){
            result[el.first][el.second] = 0;
        }

        if(!ones_vect.empty()){
            custom_search(n,m,ones_vect);
        }
        
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cout << result[j][k];
                if(k!=m-1){
                    cout << " ";
                }
            }
            cout <<  "\n";
        }
    }
    return 0;
}
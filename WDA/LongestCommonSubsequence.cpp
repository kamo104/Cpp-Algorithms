#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

vector<vector<vector<int> > > cs;
vector<int> c;

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b,int i,int j) {
    vector<int> result;
    vector<int> temp;
    int d=0;
    if(cs[i][j][0]==-1){
        vector<int> result;
        if(a[i]==b[j]){
            result.push_back(a[i]);
            temp = longestCommonSubsequence(a,b,i-1,j-1);
            for(int k=0;k<temp.size(); k++){
                result.push_back(temp[k]);
            }
            cs[i][j] = result;
            return(cs[i][j]);
            }    
        else{
            //oblicz longestCommonSubsequence(a,b,i-1,j)
            //potem porownaj ktora jest dluzsza
            //potem daj dluzsza na csa
            result = longestCommonSubsequence(a,b,i-1,j);
            d = max(result.size(),longestCommonSubsequence(a,b,i,j-1).size());
            if (d==result.size()){
                cs[i][j] = result;
            }
            else{
                cs[i][j] = longestCommonSubsequence(a,b,i,j-1);
            }
            return(cs[i][j]);
            //cs[i][j] = max(longestCommonSubsequence(a,b,i-1,j), longestCommonSubsequence(a,b,i,j-1));
            }
        
        }
    else{
        return(cs[i][j]);
        }

    
    }

int main() {
    int n,m;
    cin >> n;
    cin >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> result;
    
    vector<int> tempo(1,-1);
    vector< vector<int> > tempm(m,tempo);
    
    for(int i=0; i<n; i++){
        cs.push_back(tempm);
    }
    for(int i=0;i<n;++i){
        cin >> a[i];
        }
    for(int i=0;i<m;++i){
        cin >> b[i];
        }
    for (int i=0; i<n; i++){
        cs[i][0][0] = b[0];
    }
    for (int i=0;i<m;i++){
        cs[0][i][0] = a[0];
    }
    cs[0][0] = {0};
    result = longestCommonSubsequence(a, b, n-1, m-1);
    for(int i=result.size()-1; i>=0; --i){
        cout << result[i] << ' ';
    }
    return 0;
    }

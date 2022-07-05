#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int clocky(string a, string b){
    int i=0;
    i+=1;
    
    return(i);
}


int main() {
    //#1 when are the two overlapping, and how many of those times are in the h range
    int ntests;
    
    vector<pair<string,string>> response;
    cin >> ntests;
    string a,b;
    for(int i=0; i<ntests; i++){
        cin >> a;
        cin >> b;
        cout << clocky(a,b);
        response.push_back(make_pair(a,b));
    }
    
    for(int i=0; i<ntests; i++){
        cout << response[i].first << " ";
        cout << response[i].second << "\n";
    }
    return 0;
}
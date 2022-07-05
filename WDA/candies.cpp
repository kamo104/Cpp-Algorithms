#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int cost_tab[10004];

long long candies(vector<int> *prio){
    int i=0;
    long long returner=0;
    
    prio->insert(prio->begin(),prio->at(0));
    prio->insert(prio->end(), prio->at(prio->size()-1));
    for(int i=1;i<=prio->size();++i){
        cost_tab[i] =1;
        if(prio->at(i-1)>=prio->at(i) && prio->at(i)<=prio->at(i+1)){
            for(int j=i-1;j>0 && prio[j]>=prio[j+1]; --j){
                cost_tab[j] = cost_tab[j+1] + 1;
            }
            for(;i<=prio->size() && prio->at(i+1)>prio->at(i);++i){
                cost_tab[i+1]  = cost_tab[i] +1;
            }
        }
    }
    for(int i=1;i<=prio->size(); ++i){
        if(prio->at(i)>prio->at(i+1) && prio->at(i)>prio->at(i-1)){
            prio->at(i) = max(prio->at(i+1), prio->at(i-1));
        }   
    }
    for(int i=1;i<=prio->size();++i){
        returner += prio->at(i);
    }
    return(returner);
}



int main(void){
    vector<int> prio;
    int n;
    int temp;
    cin >> n;
    cin >> temp;
    for (int i=0;i<n;++i){
        cin >> temp;
        prio.push_back(temp);
    }
    cout << candies(&prio);
    return 0;
}
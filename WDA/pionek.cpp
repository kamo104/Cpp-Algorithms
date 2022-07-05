#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<short> negatives;
int table_of_cost[1000001];

long max_sum(int num_negs, vector<short> negatives){
    int temp[6];
    int maximum=0;
    
    negatives.push_back(0);
    num_negs += 1;
    
    for(int j=0; j<num_negs;j++){
        table_of_cost[j] = 0;
    }
    for(int j=0; j<6;j++){
        table_of_cost[j] = negatives[j];
    }
    for (int i=6; i<num_negs;i++){
        for(int g=0;g<6;++g){
            temp[g] = table_of_cost[i-(g+1)];
        }
        maximum = temp[0];
        for(int g=0; g<6;++g){
            temp[g]>maximum ? maximum = temp[g] : maximum=maximum;
        }
        // maximum == (maximum from 6 last elements)
        table_of_cost[i] = negatives[i] + maximum;
    }
    return(table_of_cost[num_negs-1]);
}

int main() {
    int nfields;
    short field;
    long result=0;
    bool last_negative=false;
    int num_negs=0;
    
    cin >> nfields;
    cin >> field;
    result += field;
    
    for (int i=0; i<nfields-1; i++){
        
        cin >> field;
        
        if(field>=0){
            result+= field;
        }
        else{
            num_negs +=1;
            negatives.push_back(field);
            last_negative = true;
            continue;
        }
        
        if(field>=0 && last_negative == true){
            last_negative = false;
            if(num_negs <= 5){
                negatives.clear();
                num_negs =0;
                continue;
            }
            result += max_sum(num_negs, negatives);
            negatives.clear();
            num_negs =0;
        }
    }
    if(num_negs >= 5){
        if(field<0){
            result += field;
        }
        result += max_sum(num_negs, negatives);
    }
    else if (num_negs>0){
        result += negatives[num_negs-1];
    }
    cout << result;  
    return 0;
}

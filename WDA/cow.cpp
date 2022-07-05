
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int barn[1000000];

bool check2(int ncows, int distance, int nstalls){
    int left,right;
    left = barn[0];
    right = barn[1];
    ncows -=1;
    nstalls -=1;
    for (int r=1; ncows >0;++r, --nstalls){
        if (nstalls <=0){
            return (false);
        }
        right = barn[r];
        if (right - left >=distance){
            ncows -=1;
            left = barn[r];
            continue;
            }
        }
    
    return (true);
}

int check(int ncows,int maxsearch, int minsearch, int nstalls){
    int med=maxsearch +minsearch;
    if (maxsearch-minsearch <= 2){

        if (check2(ncows,minsearch+1,nstalls) == true){

            if (check2(ncows,maxsearch,nstalls) == true){

                return(maxsearch);
                }
            }
        else {

            return(minsearch);
            }
        }
    if (check2(ncows,med/2, nstalls) == true){
        minsearch = med/2;
        return(check(ncows,maxsearch,minsearch, nstalls));
    }
    else {
        maxsearch = med/2;
        return(check(ncows,maxsearch,minsearch, nstalls));
    }
    
}

int main() {
    int ntests;
    int nstalls;
    int ncows;
    int stall;
    int size;
    int maxsearch;
    int minsearch=1;
    cin >> ntests;
    for(int i=0; i<ntests; ++i){
        cin >> nstalls;
        cin >> ncows;
        if(ncows > nstalls){
            cout << 0 << endl;
            continue;
        }
        for(int j=0; j<nstalls; ++j){
            cin >> stall;
            barn[j]=stall;
        }
        sort(barn, barn + nstalls);
        size = 1 + barn[nstalls-1]-barn[0];
        maxsearch = size/(ncows-1);
        cout << check(ncows,maxsearch,minsearch,nstalls) << endl;
    } 
    return 0;
}
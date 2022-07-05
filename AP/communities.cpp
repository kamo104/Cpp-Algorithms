#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100001


long val[MAXN];
long parent[MAXN];
long rnk[MAXN];


long find(long x){
    if(parent[x]!=x) parent[x] = find(parent[x]);
    return(parent[x]);
}

void _union(long x, long y){
    long xroot = find(x);
    long yroot = find(y);
    
    if(rnk[xroot]<rnk[yroot]){
        parent[xroot] = yroot;
        val[yroot] += val[xroot];
    }
    else if(rnk[xroot]>rnk[yroot]){
        parent[yroot] = xroot;
        val[xroot] += val[yroot];
    }
    else{
         parent[yroot] = xroot;
         val[xroot] += val[yroot];
         ++rnk[yroot];
    }
}

/*3 6
Q 1
M 1 2
Q 2
M 2 3
Q 3
Q 2*/

int main() {
    long nppl,nq;
    long tmp1,tmp2;
    char tmp;
    cin >> nppl >> nq;
    for(long i=0;i<MAXN;i++){
        parent[i] = i;
        rnk[i] = 1;
        val[i] = 1;
    }
    
    while(nq--){
        cin >> tmp;
        switch(tmp){
            case('Q'):{
                cin >> tmp1;
                cout << val[find(tmp1)] << "\n";
                break;
            }
            case('M'):{
                cin >> tmp1 >> tmp2;
                _union(tmp1,tmp2);
                break;
            }
        }
    }
    return 0;
}

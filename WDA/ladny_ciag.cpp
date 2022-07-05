#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int tab[1001][1001];

int biggest_counted_x=1;

int count(int x, int k, int q){
    int returner=0;
    if(biggest_counted_x < x){
        for(int j=biggest_counted_x+1; j<=x;++j){
            for(int i=0;i<=k;i++){
                if(i==0){
                    tab[j][0] = tab[j-1][0] + tab[j-1][1];
                    continue;
                }
                else if(i==k){
                    tab[j][k] = tab[j-1][k] + tab[j-1][k-1];
                    continue;
                }

                
            }
        }
        biggest_counted_x = x;
    }

    for (int i=0;i<=k;i++){
        returner += tab[x][i];
    }

    return( returner );
}


int main() {
    for(int j=0; j>=1000; --j){ tab[1][j] = 1;}
    
    int n,x,k,q;
    cin >> n >> k >> q;
    for(int i=0; i<n;++i){
        cin >> x;
        cout << count(x,k,q) << ' ';
    }
    
    return 0;
}

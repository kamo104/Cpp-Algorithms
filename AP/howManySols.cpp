#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
bool isPerfectSquare(long long x){ 
    if(x==0||x==1){return(1);}
    long long left = 1, right = x;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (mid * mid == x){
            return true;
        }
        else if (mid * mid < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}
long long numsols(short n,short x, short y){

    if(x==0&&y==0){
        return(n*n*n*n);
    }
    else if(x==0|| y==0){
        return(n*n*n);
    }
    long long nsols=0;
    for(int d=0;d<=n;d++){
        for(int b=0;b<=n;b++){
            for(int a=0;a<=n;a++){
                //check if xa^2+yb^2-yd^2 = xc^2
                if(isPerfectSquare(a*a+(y*b*b-y*d*d)/x)){
                    nsols+=1;
                }
                /*
                for(int c=0;c<=n;c++){
                    if(x*(a*a-c*c)==y*(d*d-b*b)){
                        nsols+=1;
                    }
                }
                */

            }
        }
    }
    return(nsols);
}


int main() {
    short n,x,y;

    cin >> n >> x >> y;
    cout << numsols(n,x,y) << "\n";
    
    return 0;
}
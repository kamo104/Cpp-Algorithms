#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sil(unsigned long long int y){
    unsigned long long int x=y;
    while(y>1){
        x = x*(y-1);
        while(x%10==0){
            x=x/10;
        }
        --y;
        x = x%1000;        
    }
    return(x%10);
}
int main() {
    int tests;
    unsigned long long int n;
    cin >> tests;
    for (int i=0; i < tests ;++i){
        cin >> n;
        cout << sil(n) << endl;
        }
    return 0;
}
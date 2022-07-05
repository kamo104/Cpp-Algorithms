#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nwd(int n1,int n2) {
    if (n1==1 || n2 == 1){
        return(1);
    }
    if (n2 == 0){
        return(n1);
    }
    else if (n1 == n2){
        return(n1);
    }
    else if (n1>n2){
        return(nwd(n1,n1%n2));
    }
    else if (n2>n1){
        return(nwd(n2,n2%n1));
    }
    return(0);
}

int main() {
    int tests;
    int n1,n2;
    cin >> tests;
    for(int i=0; i<tests;++i){
        cin >> n1;
        cin >> n2;
        if (n1==0 || n2==0){
            cout << 0 << endl;
            continue;
        }
        else if (n1 ==1 || n2 == 1){
            cout << 1 << endl;
            continue;
        }
        cout << nwd(n1,n2) << endl;
    }
    return 0;
}
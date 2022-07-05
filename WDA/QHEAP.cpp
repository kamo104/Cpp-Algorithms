#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>
#include <D:\Studia\Sem1\WDA\myheaders\heap.h>
using namespace std;


int main() {
    heap h;
    
    int nqueries;
    long long temp;
    short operation;
    cin >> nqueries;
    //cout << LONG_LONG_MIN << " ";
    for(int i=0;i<nqueries;i++){
        cin >> operation;
        switch(operation){
                case(1):{
                    cin>> temp;
                    h.push(temp);
                    continue;
                }
                case(2):{
                    cin >> temp;
                    h.pop(temp);
                    continue;
                }
                case(3):{
                    cout << h.min() << "\n";
                    continue;
                }
        }
    }  
    
    return 0;
}

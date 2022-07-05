#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool is_palindrome(string a){
    int a_len = a.length();
    for(int i=a_len-1; i>=(a_len-1)/2;--i){
        if(a[i]!=a[a_len-1-i]){
            return(false);
        }
        
    }
    return(true);
}


int main(void){
    string a;
    cin >> a;
    cout << is_palindrome(a);


    return 0;
}
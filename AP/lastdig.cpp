#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define NMAX LONG_LONG_MAX

typedef unsigned short int suint;
typedef long long ll;

ll twos_powers[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,\
65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,\
67108864,134217728,268435456,536870912,1073741824,2147483648};

char lastdig_of_base_to_two[32];


int main() {
    suint n;
    suint base;
    ll power;
    cin >> n;

    while(n--){
        cin >> base >> power;
        
        //initialize the lastdig arr
        lastdig_of_base_to_two[0] = base%10;
        for (suint i=1; i<32;i++){
            lastdig_of_base_to_two[i]= (lastdig_of_base_to_two[i-1]*lastdig_of_base_to_two[i-1])%10;
        }
       
        ll count=0;
        bool first = true;
        char res;
        for (ll i = power; i ; i /= ll(2) , count+=1){
            if(i & ll(1)){
                if(first){
                    res= lastdig_of_base_to_two[count];
                    first = false;
                }
                else res = (suint(res)*suint(lastdig_of_base_to_two[count]))%10;
            }
            
        }

        cout << suint(res) << "\n";

    }
    
    
    return 0;
}
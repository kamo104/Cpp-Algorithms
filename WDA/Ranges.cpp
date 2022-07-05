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

set <long> singlenums;


int main() {
    int ntests,nranges;
    long lower_a,upper_a,lower_b,upper_b,result=0;
    long nums=0;
    cin >> ntests;
    for (int i=0;i<ntests;++i){
        cin >> nranges;
        
        //najpierw zbieramy pierwszy range i porownamy go z kolejnym itd
        cin >> lower_a;
        cin >> upper_a;
        
        for (int j=0;j<nranges;++j){
            if(lower_a==upper_a){singlenums.insert(lower_a);nums+=1;}
            if (nranges==1)break;
            cin >> lower_b;
            cin >> upper_b;
            upper_a-upper_b>0?upper_a=upper_a:upper_a=upper_b;
            lower_a-lower_b>0?lower_a=lower_a:lower_a=lower_b;
        }
        long temp;
        
        
        
        if (lower_a>upper_a){
            temp=upper_a;
            upper_a=lower_a;
            lower_a=temp;
        }
        while(nums>0){
            temp = singlenums[singlenums.end()];
            if (temp==lower_a && temp==upper_a){
                result+=1;
                singlenums.erase(temp);
                nums-=1;
                continue;
            }
            else if(temp>=lower_a&&temp<=upper_a){
                singlenums.erase(temp);
                nums-=1;
                continue;
            }
            else{
                result+=1;
                singlenums.erase(temp);
                continue;
            }
        }

        result += upper_a-lower_a;
        //cout << result <<endl;
        result=0;
        temp=0;
        nums=0;
    }
    return 0;
}
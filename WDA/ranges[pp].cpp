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

vector <pair <long,long> > holder;

int main() {
    int ntests,nranges, temp;
    long begin, end, result;
    bool ended_on_resize=false;
    cin >> ntests;
    for(int i=0; i<ntests;++i){
        result=0;
        holder.clear();
        cin >> nranges;
        for (int j=0; j<nranges;j++){
            cin >> begin;
            cin >> end;
            if(begin>end)swap(begin, end);
            holder.push_back(make_pair(begin,end));
        }
        sort(holder.begin(),holder.end());
        begin = holder[0].first;
        end = holder[0].second;
        for (int j=1;j<holder.size();j++){
            //cout << holder[j].first << " " << holder[j].second << endl;
            /*rozważyć 3 przypadki, 
            I~!niemożliwe po posortowaniu, jeśli sortowanie za wolne wrócić 
            I początek następnego zbioru jest mniejszy niż początek naszego zbioru, wtedy 
            II początek jest w naszym zbiorze albo jest równy końcowi, wtedy poszerzamy zbiór roboczy
            III początek następnego zbioru jest poza wcześniejszym, wtedy dopisujemy do wyniku liczbę 
            liczb w zbiorze starym i nowy jest naszym go to,*/
            if(holder[j].first>end){
                result += end-begin+1;
                begin = holder[j].first;
                end = holder[j].second;
                ended_on_resize = false;
            }
            else{
                end = holder[j].second;
                ended_on_resize = true;
            }
        }
        if(ended_on_resize ==true){
            result+= end-begin-1;
        }
        cout << result << "\n";

        
    }
    
    return 0;
}
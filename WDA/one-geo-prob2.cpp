#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long int lli;
#define BASE 1e10


string a[21];
string b[20];
string c[20];
string d[20];
string e[21];


int add(string x[], string y[], int lx, int ly){
    int a_len=1;
    string t="";
    for (int i=0; i<21;++i){
        a[i] ="";
    }
    lli carry =0,i;
    for (i=0; i<max(lx,ly); ++i){
        lli tmp=0;
        if (i<=lx){
            t=x[i];
            tmp += stoll(t);
        }
        if (i<=ly){
            t=x[i];
            tmp += stoll(t);
        }
        tmp += carry;
        carry = tmp/(lli(BASE));
        t=a[i];
        a[i] = to_string(stoll(t) + tmp %(lli(BASE)));
        
        a_len = i+1;
    }
    if(carry>0){
        t=a[i+1];
        a[i+1] = to_string(stoll(t) + carry);
        
        a_len +=1;
    }
    return(a_len);
}
//                a   -    b
int subtract(string x[], string y[], int lx, int ly){
    lli carry = 0, i, tmp;
    string t="";
    for (i=0; i<max(lx,ly); ++i){
        tmp=0;
        if (i<=lx){
            tmp +=stoll(x[i]);
        }
        if (i<=ly){
            tmp -= stoll(y[i]);
        }
        if (tmp <0){
            carry = -1;
            tmp = lli(BASE)+tmp;
        }
        else{
            carry =0;
        }
        x[i] = to_string(tmp);
    }
    
    if(carry<0){
        t = x[i+1];
        x[i+1] = to_string(stoll(t) - carry);
    }
    return(lx);
}


int getnum(string z[]){
    string number="";
    int z_len=0;
    lli cur_len=1;
    string letter;
    char t;
    scanf("%c",&t);
    letter = to_string(t-48);
    //cout << letter-48 << endl;
    while(t != ' ' && t != '\n'){
        number = number + letter;
        
        if(scanf("%c",&t)==EOF)break;
        letter = to_string(t-48);
        if(stoll(number)*10 >= lli(BASE)){
            cout << number << " " << endl;
            z[z_len] = number;
            z_len += 1;
            number = "";
            cur_len =0;
        }
        cur_len +=1;
    }
    if(cur_len != 0){
        z[z_len] = number;
        z_len += 1;
        number = "";
        cur_len =0;
    }
    //cout << z_len;
    return(z_len);
}


int main() {
    int ntests=0;
    char letter;
    int b_len, c_len, d_len, a_len;
    cin >> ntests;
    scanf("%c",&letter);
    for (int i=0; i<ntests;++i){
        //cout << stoll("1");
        
        b_len = getnum(b);
        reverse(b,b + b_len);
        c_len = getnum(c);
        reverse(c, c+ c_len);
        d_len = getnum(d);
        reverse(d,d + d_len);
        a_len = add(c,c,c_len,c_len);
        a_len = subtract(a,b,a_len,b_len);
        a_len = subtract(a,d,a_len,d_len);
        cout << a_len;
        for(int j=a_len-1;j>=0;--j){
            cout << a[j];
        }
        cout << " ";
        for(int j=b_len-1;j>=0;--j){
            cout << b[j];
        }
        cout << " ";
        for(int j=c_len-1;j>=0;--j){
            cout << c[j];
        }
        cout << " ";
        for(int j=d_len-1;j>=0;--j){
            cout << d[j];
        }
        cout << endl;
        
    }
    return 0;
}

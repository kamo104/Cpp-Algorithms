#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long int lli;
#define BASE 10


char a[500];
char b[500];
char c[500];
char d[500];


int add(char x[], char y[], int lx, int ly){
    int a_len=1;
    int carry =0,i;
    for (i=0; i<max(lx,ly); ++i){
        int tmp=0;
        if (i<=lx){
            tmp +=x[i];
        }
        if (i<=ly){
            tmp += y[i];
        }
        tmp += carry;
        carry = tmp/10;
        a[i] += tmp %10;
        a_len = i+1;
        
    }
    if(carry>0){
        a[i] +=carry;
        a_len +=1;
        }
    return(a_len);
}

int subtract(char x[], char y[], int lx, int ly){
    int carry = 0, i, tmp;
    for (i=0; i<max(lx,ly); ++i){
        x[i] += carry;
        tmp=0;
        if (i<=lx){
            tmp +=x[i];
        }
        if (i<=ly){
            tmp -= y[i];
        }
        if (tmp <0){
            carry = -1;
            tmp = int(BASE)+tmp;
        }
        else{
            carry =0;
        }
        x[i] = tmp;
        
    }
    if(carry<0){
        x[i] += carry;
        }
    return(lx);
}


int getnum(char z[]){
    string g;
    cin >> g;
    int i=0;
    for (i=0;i<g.length();++i){
        z[i]=g[i]-48;
    }
    return(i);
}


int main() {
    int ntests=0;
    char letter;
    int b_len, c_len, d_len, a_len;
    cin >> ntests;
    scanf("%c",&letter);
    for (int i=0; i<ntests;++i){

        b_len = getnum(b);
        reverse(b,b + b_len);

        c_len = getnum(c);
        reverse(c, c+ c_len);

        d_len = getnum(d);
        reverse(d,d + d_len);

        a_len = add(c,c,c_len,c_len);
        a_len = subtract(a,b,a_len,b_len);
        a_len = subtract(a,d,a_len,d_len);

        for(int j=a_len-1;j>=0;--j){
            if(a[j]==0 && j!=0)continue;
            printf("%d",a[j]);
        }
        
        cout << endl;
    }
    return 0;
}

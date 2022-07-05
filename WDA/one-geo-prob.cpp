#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long int lli;
#define BASE 1e10


lli a[21];
lli b[20];
lli c[20];
lli d[20];


int add(lli x[], lli y[], int lx, int ly){
    int a_len=1;
    /*for (int i=0; i<21;++i){
        a[i] =0;
    }*/
    lli carry =0,i;
    for (i=0; i<max(lx,ly); ++i){
        lli tmp=0;
        if (i<=lx){
            tmp +=x[i];
        }
        if (i<=ly){
            tmp += y[i];
        }
        tmp += carry;
        carry = tmp/(lli(BASE));
        a[i] += tmp %(lli(BASE));
        
        a_len = i+1;
        if(carry>0){
        a[i+1] +=carry;
        a_len +=1;
    }
    }
    return(a_len);
}

int subtract(lli x[], lli y[], int lx, int ly){
    lli carry = 0, i, tmp;
    for (i=0; i<max(lx,ly); ++i){
        tmp=0;
        if (i<=lx){
            tmp +=x[i];
        }
        if (i<=ly){
            tmp -= y[i];
        }
        if (tmp <0){
            //cout << "wtf";
            carry = -1;
            tmp = lli(BASE)+tmp;
        }
        else{
            carry =0;
        }
        x[i] = tmp;
        if(carry<0){
        x[i+1] += carry;
        }
    }
    
    return(lx);
}


int getnum(lli z[]){
    lli number=0;
    int z_len=0;
    lli cur_len=1;
    char letter;
    scanf("%c",&letter);
    //cout << letter-48 << endl;
    while(letter != ' ' && letter != '\n'){
        number = number*10 + (letter-48);
        if(scanf("%c",&letter)==EOF)break;
        //if(letter=' ' || letter == '\n' )break;
        if(number*10 >= lli(BASE)){
            //cout << number << " " << lli(1e10) <<  endl;
            z[z_len] = number;
            z_len += 1;
            number = 0;
            cur_len =0;
        }
        cur_len +=1;
    }
    if(cur_len != 0){
        z[z_len] = number;
        z_len += 1;
        number = 0;
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
    /* for now lets test on 1 test case
    ntests = 1;*/
    for (int i=0; i<ntests;++i){

        b_len = getnum(b);
        //if(b_len >1)reverse(b,b + b_len);
        c_len = getnum(c);
        //if(c_len>1)reverse(c, c+ c_len);
        d_len = getnum(d);
        //if(d_len>1)reverse(d,d + d_len);
        a_len = add(c,c,c_len,c_len);
        a_len = subtract(a,b,a_len,b_len);
        //a_len = subtract(a,d,a_len,d_len);

        for(int j=a_len-1;j>=0;--j){
            printf("%lld",a[j]);
        }
        cout << " ";
        for(int j=b_len-1;j>=0;--j){
            printf("%lld",b[j]);
        }
        cout << " ";
        for(int j=c_len-1;j>=0;--j){
            printf("%lld",c[j]);
        }
        cout << " ";
        for(int j=d_len-1;j>=0;--j){
            printf("%lld",d[j]);
        }
        cout << endl;
    }
    return 0;
}

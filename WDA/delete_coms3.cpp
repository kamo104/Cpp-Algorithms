#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long int lli;
bool block_comment=false;
bool doendl=true;

string delcoms(string a, int start){
    ssize_t com_end, line_com, block_com, string_start;
    string b = "", c = "", d="";
    int add=0,start2=0;
    c = a.substr(start,-1);
    a.erase(start,-1);
    line_com = c.find("//");
    line_com == -1 ? line_com = 2147483647 : line_com = line_com;

    block_com = c.find("/*");
    block_com == -1 ? block_com = 2147483647 : block_com = block_com;

    string_start = c.find("\"");
    string_start == -1 ? string_start =2147483647 : string_start = string_start;

    if (block_comment == true){
        if(c.find("*/") == std::string::npos){
            doendl = false;
            return("");
        }
        else{
            c.erase(0,c.find("*/")+2);
            block_comment = false;
            a.append(c);
            if(a.length() == 0){
                doendl = false;

                return(a);
            }

            return(delcoms(a,start));
        }
    }
    
    else if ((line_com -block_com)<0 && (line_com-string_start)<0){
        b = c.substr(0,line_com);
        a.append(b);
        return(a);
    }
    else if ((block_com -line_com)<0 && (block_com-string_start)<0){
        b = c.substr(0,block_com);
        c.erase(0,block_com);
        if (c.find("*/") == std::string::npos){
            block_comment = true;
            a.append(b);

            return(a);
        }
        else{
            c.erase(0,c.find("*/")+2);
            b.append(c);
            a.append(b);

            return(delcoms(a,start));
        }
    }
    else if ((string_start -line_com)<0 && (string_start-block_com)<0){
        b = c.substr(0,string_start);
        c.erase(0,string_start);
        add = b.length() + a.length() + c.find("\"");;
        b.append(c);
        a.append(b);

        return(delcoms(a,start + int(add)));

    }
    else{

        return(a.append(c));
    }
    return 0;
}

int main() {
    string line;
    while(getline(cin,line)){
        cout << delcoms(line, 0);
        if (doendl == false){
            doendl = true;
            continue;
        }
        else{
            cout << endl;
        }
    }
    return 0;
}
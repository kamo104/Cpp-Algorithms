#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool block_comment=false;
bool doendl=true;
bool in_string = false;
size_t smallest(size_t line_com,size_t block_com,size_t string_start){
    size_t small = line_com;
    if (block_com <small){
        small = block_com;
    }
    if (string_start < small){
        small = string_start;
    }
    return(small == 18446744073709551615 ? 0 : (small == line_com ? 1 : (small==block_com ? 2 : (small==string_start ? 3 : 0))));
}


string delcoms(string a, int start){
    size_t com_end, line_com, block_com, string_start;
    string b = "", c = "", d="";
    int add=0;
    size_t number=0;
    c = a.substr(start,-1);
    a.erase(start,-1);
    line_com = c.find("//");
    block_com = c.find("/*");
    string_start = c.find("\"");

    if (in_string == true){
        in_string = false;
        if (c.find("\\\"") == -1){
            if (c.find("\"") != -1){
                add = c.find("\"") + b.length() + a.length()+1;
                b.append(c);
                a.append(b);
                return(delcoms(a,add));
            }
            else{
                b.append(c);
                a.append(b);
                return(a);
            }
        }
        else{
            if(c.find("\\\"")+1==c.find("\"")){
                add = c.find("\"") + b.length() + a.length()+1;
                b.append(c);
                a.append(b);
                in_string =true;
                
                return(delcoms(a,add));
            }
            else{
                //b.append(c);
                /* komentarz 
                cout << a;
                cout << endl;
                cout << c.find("\\\"");
                cout << c.find("\""); */
                
                add = c.find("\"") + b.length() + a.length()+1;
                b.append(c);
                a.append(b);
                return(delcoms(a,add));
            }
        }
    }
    else if (block_comment == true){
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
    number = smallest(line_com,block_com,string_start);
    if (number == 1){
        //cout << "its line com";
        return(a.append(c.substr(0,line_com)));
    }
    else if (number == 2){
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
    else if (number == 3){
        b = c.substr(0,string_start+1);
        c.erase(0,string_start+1);
        if (c.find("\\\"") == -1){
            if (c.find("\"") != -1){
                add = c.find("\"") + b.length() + a.length()+1;
                b.append(c);
                a.append(b);
                return(delcoms(a,add));
            }
            else{
                b.append(c);
                a.append(b);
                return(a);
            }
        }
        else{
            if(c.find("\\\"")+1==c.find("\"")){
                add = c.find("\"") + b.length() + a.length()+1;
                b.append(c);
                a.append(b);
                in_string =true;
                return(delcoms(a,add));
            }
            else{
                add = c.find("\"") + b.length() + a.length()+1;
                b.append(c);
                a.append(b);
                return(delcoms(a,add));
            }
        }


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
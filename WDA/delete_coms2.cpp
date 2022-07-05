#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool block_comment=false;
bool doendl=true;

string delcoms(string a){
    size_t com_end, line_com, block_com;
    int pos;
    line_com = a.find("//");
    block_com = a.find("/*");
    if (block_comment == true){
        com_end = a.find("*/");
        if(com_end == std::string::npos){
            a = a.substr(0,0);
            doendl = false;
            return(a);
        }
        else{
            a = a.substr(com_end+2,-1);
            block_comment=false;
            if(a == ""){
                doendl = false;
                return(a);
            }
            return(delcoms(a));
        }
    }
    else if (line_com != std::string::npos && block_com != std::string::npos ){
        if (line_com < block_com){
            a = a.substr(0,line_com);
            return(a);
        }
        else {
            com_end = a.find("*/");
            if(com_end == std::string::npos){
                block_comment = true;
                a = a.substr(block_com,-1);
                return(a);
            }
            else{
                while(com_end<block_com){
                    com_end = a.find("*/",com_end+2);
                    if(com_end == -1){
                        block_comment = true;
                        a = a.substr(block_com,-1);
                        return(a);
                    }
                }
                block_comment=false;
                string temp;
                temp = a.substr(0,block_com);
                a = a.substr(com_end+2,-1);
                return(delcoms(temp+a));
            }
        }
    }
    else if (line_com == std::string::npos && block_com != std::string::npos){
        com_end = a.find("*/");
            if(com_end == std::string::npos){
                block_comment = true;
                a = a.substr(0,block_com);
                /*if (a == ""){
                    doendl = false;
                    return(a);
                }*/
                return(a);
            }
            else{
                while(com_end<block_com){
                    com_end = a.find("*/",com_end+2);
                    if(com_end == std::string::npos){
                        block_comment = true;
                        a = a.substr(0,block_com);
                        return(a);
                    }
                }
                string temp;
                temp = a.substr(0,block_com);
                a = a.substr(com_end+2,-1);
                /*if(temp+a == ""){
                    doendl = false;
                    return(a);
                }*/
                return(delcoms(temp+a));
            }
    }
    else if (line_com != std::string::npos && block_com == std::string::npos){
        a = a.substr(0,line_com);
        return(delcoms(a));
    }
    else if (line_com == std::string::npos && block_com == std::string::npos){
        return(a);
    }
    return 0;
}

int main() {
    string line;
    string whole_text;
    while(getline(cin,line)){
        cout << delcoms(line);
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
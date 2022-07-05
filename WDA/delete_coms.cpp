#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    bool block_comment=false,line_comment=false;
    bool last_slash = false;
    bool last_star = false;
    bool back_slash = false;
    bool doendl = true;
    string line;
    string current_line;
    while(getline(cin,line)){
        for(long unsigned int i=0;i<line.length();i++){
            if(block_comment ==true){
                if (line[i] == '*'){
                    last_star = true;
                    last_slash = false;
                    continue;
                }
                else if (line[i] == '/' && last_star == true){
                    block_comment = false;
                    last_star = false;
                    last_slash = false;
                    continue;
                }
                else {
                    last_star = false;
                    last_slash = false;
                    continue;
                }
            }
            else if(line_comment == true){
                if (line.back() == 92 ){
                    back_slash = true;
                    last_slash = false;
                    last_star = false;
                    break;
                    }
                else{
                line_comment = false;
                back_slash = false;
                doendl = false;
                break;
                }
            }
            else if(last_slash == true){
                if (line[i]=='*'){
                    block_comment = true;
                    current_line.pop_back();
                    cout << current_line;
                    current_line.clear();
                    continue;
                }
                else if(line[i]== '/'){
                    line_comment = true;
                    last_slash = false;
                    last_star = false;
                    if(line.back() == 92){
                        back_slash = true;
                    }
                    current_line.pop_back();
                    cout << current_line << endl;
                    current_line.clear();
                    break;
                }
            }
            else if(line[i] == '/'){
                last_slash = true;
                last_star = false;
                current_line.append(1,line[i]);
                continue;
            }
            else if(line[i] == '*'){
                last_star = true;
                last_slash = false;
                current_line.append(1,line[i]);
                continue;
            }
            
            last_star = false;
            last_slash = false;
            current_line.append(1,line[i]);
            }
    
    if(line_comment==true && back_slash == false){
        line_comment = false;
        continue;
        
    }
    else if(line_comment==true && back_slash == true){
        line_comment = true;
        back_slash = false;
        continue;
    }
    else if (block_comment == true){
        current_line.clear();
        continue;
    }
    else if(doendl == false){
        doendl = true;
        continue;
    }
    else{
    cout << current_line << endl;
    current_line.clear();
    }
    }
    return 0;
}
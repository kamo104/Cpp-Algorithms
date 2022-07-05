#include <bits/stdc++.h>

using namespace std;


/*
    patrzac na dwa stringi od konca albo sie zgadzaja albo nie, jak sie zgadzaja to jest git usuwamy ich dlugosc o 1 z obu jak nie to mozemy zmienic litere na duza i zobaczyc czy sie zgadza albo ja pominac
 */

vector<vector<string> > cs;
vector<string> c;

string longestCommonSubsequence(string a, string b,int i,int j) {
    string result;
    string temp;
    int d=0;
    if(cs[i][j][0]==32){
        if(a[i]==b[j]){
            result += a[i];
            temp = longestCommonSubsequence(a,b,i-1,j-1);
            result += temp;
            cs[i][j] = result;
            return(cs[i][j]);
            }    
        else{
            //oblicz longestCommonSubsequence(a,b,i-1,j)
            //potem porownaj ktora jest dluzsza
            //potem daj dluzsza na csa
            result = longestCommonSubsequence(a,b,i-1,j);
            d = max(result.length(),longestCommonSubsequence(a,b,i,j-1).length());
            if (d==result.size()){
                cs[i][j] = result;
            }
            else{
                cs[i][j] = longestCommonSubsequence(a,b,i,j-1);
            }
            return(cs[i][j]);
            //cs[i][j] = max(longestCommonSubsequence(a,b,i-1,j), longestCommonSubsequence(a,b,i,j-1));
            }
        
        }
    else{
        return(cs[i][j]);
        }

    
    }


int n_upper_letters(string a){
    int result =0;
    for (int i=0; i<a.length(); ++i){
        if(65<=a[i] && a[i]<=90){
            result+=1;
        }
    }
    return(result);
}
int n_lower_letters(string a){
    int result =0;
    for (int i=0; i<a.length(); ++i){
        if(97<=a[i] && a[i]<=122){
            result+=1;
        }
    }
    return(result);
}
bool is_upper(char c){
    if(c<=90 && 65<=c){
        return(true);
    }
    else{
        return(false);
    }
}
bool is_lower(char c){
    if(c<=122 && 97<=c){
        return(true);
    }
    else{
        return(false);
    }
}
int first_upper(string a){
    for (int i=0;i>a.length();i++){
        if(is_upper(a[i])){return i;}
    }
    return(-1);
}
int last_upper(string a){
    for (int i=a.length()-1;i>=0;i--){
        if(is_upper(a[i])){return i;}
    }
    return(-1);
}
string upper(string a){
    for(int i=0; i<a.length();i++){
        if(a[i]>=97 && a[i]<=122){
            a[i] -= 32;
        }
    }
    return(a);
}


string abbreviation(string a, string b) {

    if(n_upper_letters(a)>n_upper_letters(b)){
        return("NO");
        }
    else{
        string temp=b;
        for(int i=0;i<a.length();i++){
            if(is_upper(a[i])){
                if(temp.find(a[i])!=std::string::npos){
                    temp = temp.substr(temp.find(a[i])+1, -1);
                    }
                else{
                    return("NO");
                    }
                }
            }
        //temp =b;
        string tempa =a;
        if(last_upper(tempa)!=-1){
            tempa = tempa.substr(last_upper(tempa)+1,-1);
            if(tempa.length()>=temp.length()){
                tempa = upper(tempa);

                for(int i=0;i<temp.length();++i){
                    if(tempa.find(temp[i])!=std::string::npos){
                        tempa = tempa.substr(tempa.find(temp[i]), -1);
                    }
                    else{
                        return("NO");
                    }
                }
                
            }
            else{
                //cout << tempa << temp;
                return("NO");
            }
        }
        tempa =upper(a);
        temp =b;
        for(int i=0; i<b.length(); i++){
            if(tempa.find(b[i])==std::string::npos){
                return("NO");
                }
            }
        tempa =a;
        temp =b;
        if(first_upper(a)!=-1){
            //sprawdzic pomiedzy dwiema duzymi literami w a czy wystepuje to samo tylko ze malymi co jest w b pomiedzy tymi literami
            /*
            1
CedaBeeD
CDBAD
*/
            temp.find(a[first_upper(a)]);
        }

        }
    return("YES");
    }

int main() {
    int ntests;
    string a,b;
    cin >> ntests;
    for(int i=0;i<ntests;i++){
        cin >> a;
        cin >> b;
        
        string tempo = " ";
        vector< string > tempm(b.length(),tempo);
        for(int i=0; i<a.length(); i++){
            cs.push_back(tempm);
        }
        
        cout << abbreviation(a, b) << "\n";
    }
    return 0;
    }

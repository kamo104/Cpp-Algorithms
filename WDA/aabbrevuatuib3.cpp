#include <bits/stdc++.h>

using namespace std;


/*
    patrzac na dwa stringi od konca albo sie zgadzaja albo nie, jak sie zgadzaja to jest git usuwamy ich dlugosc o 1 z obu jak nie to mozemy zmienic litere na duza i zobaczyc czy sie zgadza albo ja pominac
 */

string cs[1010][1010];


string longestCommonSubsequence(string a, string b,int i,int j) {
    string result;
    string temp;
    int d=0;
    if(cs[i][j][0]==' '){
        if(a[i]==b[j]){
            result += a[i];
            temp = longestCommonSubsequence(a,b,i-1,j-1);
            result.append(temp);
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
string reverse_str(string a){
    string temp="";
    for(int i=1; i<=a.length();++i){
        temp+=a[a.length()-i];
    }
    return temp;
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
        tempa =upper(a);
        temp =b;
        //cout << longestCommonSubsequence(tempa,temp,tempa.length()-1,temp.length()-1) << " ";
        if(reverse_str(longestCommonSubsequence(tempa,temp,tempa.length()-1,temp.length()-1))==temp){
            return("YES");
        }
        else{
            //cout << reverse_str(longestCommonSubsequence(tempa,temp,tempa.length()-1,temp.length()-1));
            return("NO");
        }
                   //sprawdzic pomiedzy dwiema duzymi literami w a czy wystepuje to samo tylko ze malymi co jest w b pomiedzy tymi literami
/*
1
CedaBeeD
CDBAD
*/

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
        int tep = max(a.length(),b.length());
        for(int g=0; g<tep; g++){
            for(int j=0;j<tep; j++){
                cs[g][j] = " ";
            }
        }
        
        for (int g=0; g<=tep; g++){
            cs[g][0][0] = b[0];
        }
        for (int g=0;g<=tep;g++){
            cs[0][g][0] = a[0];
        }
        cs[0][0] = b[0];


        cout << abbreviation(a, b) << "\n";
    }
    return 0;
    }

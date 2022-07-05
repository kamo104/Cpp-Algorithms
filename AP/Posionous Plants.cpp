#include <bits/stdc++.h>
#include <stack>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int poisonousPlants(vector<int> p) {
    stack<pair<int,int>> t;
    
    long ans =0;
    t.push(make_pair(p[0],1));
    for(long i=1;i<p.size();i++){
        if(p[i] > p[i-1]){
            t.push(make_pair(p[i],1));
            ans = max(ans,long(1));
        }
        else{
            long n=0;
            while(t.size()>0 && t.top().first >=p[i]){
                n=max(n,long(t.top().second));
                t.pop();
            }
            long days_reduced = 0;
            if(t.size()>0) days_reduced=1;
            ans = max(ans,days_reduced);
            t.push(make_pair(p[i],days_reduced));
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split(rtrim(p_temp_temp));

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

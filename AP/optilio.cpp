#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // string id;
    // string tmp;
    // int nseq;
    // cin >> nseq >> nseq;
    // unordered_map<string, string> map;

    
    // for(int i=0; i<nseq; i++){
        
    //     cin >> id >> tmp;
    //     map.emplace(tmp,id);
    // }
    // for(int i=0; i<nseq; i++){
    //     cin >> id >> tmp;
    //     try{
    //         map.at(tmp);
    //         cout << map[tmp] << " " << id << "\n";
    //     }
    //     catch(out_of_range){
    //     }
    // }

    char id[102];
    char tmp[152];
    int nseq;
    int gen_length;
    unordered_map<string, string> map;
    scanf("%d%d", &gen_length, &nseq);
    for(int i=0;i<nseq;i++){
        scanf("%100s%152s",&id, &tmp);
        map.emplace(string(tmp),string(id));
    }
    for(int i=0;i<nseq;i++){
        scanf("%100s%152s",&id, &tmp);
        try{
            map.at(string(tmp));
            printf("%s %s\n",map[string(tmp)].c_str(), &id);
        }
        catch(out_of_range){
        }
    }


    return 0;
}
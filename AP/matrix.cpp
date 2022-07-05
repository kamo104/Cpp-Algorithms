#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

struct Node{
    bool is_machine;
    Node* parent;
};

Node* find(Node* n){
    Node* tmp=n;
    while(tmp->parent!=tmp){
        tmp = tmp->parent;
        n->parent=tmp;
    }
    return(tmp);
}

void custom_union(Node* a, Node* b){
    a=find(a);
    b=find(b);
    if(a->is_machine) b->parent=a;
    else a->parent=b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nroads,nmachines;
    cin >> nroads >> nmachines;


    vector<tuple<int,int,int>> roads;
    vector<Node*> nodes;

    for(int i=0;i<nroads;i++){
        Node* x = new Node;
        x->is_machine=0;
        x->parent = x;
        nodes.push_back(x);
    }
    

    int from, to, cost;
    for(int i=0; i<nroads-1;i++){
        cin >> from >> to >> cost;
        roads.push_back(make_tuple(from,to,cost));
    }
    
    int machine;
    for(int i=0;i<nmachines;i++){
        cin >> machine;
        nodes[machine]->is_machine=1;
    }

    auto comparator = [](tuple<int,int,int> a, tuple<int,int,int> b){
        return get<2>(a) > get<2>(b);
    };

    sort(roads.begin(),roads.end(),comparator);
    long long cst=0;
    for(int i=0;i<roads.size();i++){
        tuple<int,int,int> tmp = roads[i];
        if(find(nodes[get<0>(tmp)])->is_machine && find(nodes[get<1>(tmp)])->is_machine){
            cst += get<2>(tmp);
        }
        else{
            custom_union(nodes[get<0>(tmp)],nodes[get<1>(tmp)]);
        }
    }
    cout << cst << "\n";
    return 0;
}
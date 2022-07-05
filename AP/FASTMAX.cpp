#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>


using namespace std;

typedef long long ll;

struct Node{
    Node* left;
    Node* right;
    Node* parent;
    int val;
    pair<int,int> range;
};

class MaxTree{
    private:
    vector<Node*> root_list;
    Node* root;

    int search_max(Node* from, int range_start, int range_end){
        int mid = (from->range.first + from->range.second)/2;

        if((from->range.first==range_start && from->range.second==range_end) || (from->range.first == from->range.second)) return from->val;

        if(range_end<=mid) return search_max( from->left, range_start, range_end);

        if(range_start>mid) return search_max( from->right, range_start, range_end);

        int maxl = search_max(from->left, range_start, mid);
        int maxr = search_max(from->right, mid+1, range_end);
        return(max(maxl,maxr));
    }

    Node* search_for(Node* from, int a){
        if(from->range.first==a && from->range.second==a){
            return(from);
        }
        else{
            if(a <= from->left->range.second){
                return( search_for(from->left, a));
            }
            else{
                return( search_for(from->right, a));
            }
        }
        
    }

    void fix_upwards(Node* from){
        if(from==nullptr) return;

        int lmax=0, rmax=0;
        if(from->left!=nullptr) lmax = from->left->val;
        if(from->right!=nullptr) rmax = from->right->val;

        from->val = max(lmax,rmax);
        if(from->parent!=nullptr) fix_upwards(from->parent);
    }

    public:
    int get_max(int a, int b){
        return search_max(this->root, a, b);
    }

    bool set_val_at(int a, int b){
        Node* x = this->search_for(this->root, a);
        x->val = b;
        this->fix_upwards(x->parent);
        return 1;
    }

    Node* buildMaxTree(Node* parent, int range_start, int range_end){
        Node* x = new Node;
        x->range=make_pair(range_start,range_end);
        x->parent=parent;
        x->val=0;
        if(range_start!=range_end){
            int mid = (range_start+range_end)/2;
            x->left = this->buildMaxTree(x, range_start, mid);
            x->right = this->buildMaxTree(x, mid+1, range_end);
        }
        else{
            x->right = nullptr;
            x->left = nullptr;
        }

        root_list.push_back(x);
        return(x);
    }

    void display(){
        for(int i=0;i<this->root_list.size();i++){
            cout << this->root_list[i]->val << "\n";
        }
    }
    MaxTree(int from, int to){
        this->root=buildMaxTree(nullptr,from,to);
    }
};



int main(){
    int nelems, nqueries;
    cin >> nelems >> nqueries;

    MaxTree tree(0,nelems);

    //tree.buildMaxTree(nullptr, 0, nelems);

    int type, a, b;
    for(int i=0;i<nqueries;i++){
        cin >> type >> a >> b;
        switch(type){
            case(1):{
                tree.set_val_at(a,b);
                break;
            }
            default:{
                cout << tree.get_max(a,b) << "\n";
                break;
            }
        }
    }
    //tree.display();

    return 0;
}
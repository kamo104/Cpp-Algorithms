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
    ll val;
    pair<int,int> range;
};

class SumTree{
    private:
    vector<Node*> root_list;
    vector<ll> base;
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

    ll search_sum(Node* from, int range_start, int range_end){
        int mid = (from->range.first + from->range.second)/2;

        if((from->range.first==range_start && from->range.second==range_end) || (from->range.first == from->range.second)) return from->val;

        if(range_end<=mid) return search_sum( from->left, range_start, range_end);

        if(range_start>mid) return search_sum( from->right, range_start, range_end);

        ll suml = search_max(from->left, range_start, mid);
        ll sumr = search_max(from->right, mid+1, range_end); //+1

        return(max(max(suml,sumr), suml+sumr));

        //return(suml+sumr);
    }


    public:
    ll get_sum(int a, int b){
        return search_sum(this->root, a, b);
        //return 0;
    }


    Node* buildSumTree(Node* parent, int range_start, int range_end){
        Node* x = new Node;
        x->range=make_pair(range_start,range_end);
        x->parent=parent;
        //x->val=0;
        if(range_start!=range_end){
            int mid = (range_start+range_end)/2;
            x->left = this->buildSumTree(x, range_start, mid);
            x->right = this->buildSumTree(x, mid+1, range_end);
            x->val = max(max(x->left->val, x->right->val),x->left->val + x->right->val);
        }
        else{
            x->right = nullptr;
            x->left = nullptr;
            if(range_start-1<this->base.size()){
                if(range_start-1==0){
                    if(this->base[1]<0) x->val = this->base[1];
                    else x->val = 0;
                }
                else x->val = this->base[range_start-1];
            }
            
            
        }

        // cout << x->val << "\n";
        root_list.push_back(x);
        return(x);
    }

    void display(){
        cout << this->root->val << "\n";

        cout << this->root->left->val << " ";
        cout << this->root->right->val << "\n";

        cout << this->root->left->left->val << " ";
        cout << this->root->left->right->val << " ";
        cout << this->root->right->left->val << " ";
        cout << this->root->right->right->val << "\n";

        //cout << this->root->right->left->right->val << "\n";
    }
    SumTree(int from, int to, vector<ll> elems){
        this->base=elems;
        this->root=buildSumTree(nullptr,from,to);
    }
};



int main(){
    int nelems, tmp;
    cin >> nelems;

    vector<ll> elems(1,0);
    for(int i=0;i<nelems;i++){
        cin >> tmp;
        elems.push_back(tmp);
        //cout << elems[i+1] << "\n";
    }

    SumTree tree(1,nelems+1,elems);
    // tree.display();

    int a, b, nqueries;
    cin >> nqueries;
    for(int i=0;i<nqueries;i++){
        cin >> a >> b;
        cout << tree.get_sum(a+1,b+1) << "\n";
        
    }

    return 0;
}
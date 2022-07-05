
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

#define HSIZE 100002
#define LLMIN -9223372036854775807
//heap class
class heap{
    
    private:
        vector<long long> v;
        int size;
        
        //returns position of smaller element from two positions
        int min_at_pos(int p1, int p2){
            if(v[p1]<v[p2]){
                return(p1);
            }
            else{return(p2);}
        }

        //returns true if a child at pos has a parent
        bool has_parent(int child_pos){
            if(child_pos==1){
                return(false);
            }
            return(true);
        }

        //returns number of children at parent position
        int has_children(int parent_pos){
            if(size>=parent_pos*2+1){return(2);}
            else if(size==parent_pos*2){return(1);}
            else{return(0);}
        }

        //returns position of a parent from child position
        int parent_pos(int child_pos){
            if(has_parent(child_pos)){
                return(child_pos/2);
            }
            else{return(1);}
        }

        //returns value of a parent from child position
        int parent_val(int child_pos){
            if(has_parent(child_pos)){
                return(v[child_pos/2]);
            }
            else {return(v[1]);}
        }

        //swaps items at two positions
        void swap(int p1,int p2){
            auto temp=v[p1];
            v[p1] = v[p2];
            v[p2] = temp;
        }

        //simple comparator of two values
        long long min_val(long long v1, long long v2){
            if(v1<v2){return(v1);}
            else{return(v2);}
        }

    public:
        heap(void) {
            for (int i=0;i<HSIZE;i++){
                v.push_back(0);
            }
            v[0] = LLMIN;
            size=0;
        }

        //clear the heap and fill with zeros
        void clear(void){
            v.clear();
            for (int i=0;i<HSIZE;i++){
                v.push_back(0);
            }
            v[0] = LLMIN;
            size=0;
            return;
        }

        //push an element onto a heap
        void push(long long t){
            //append at end then check position
            size+=1;
            v[size] = t;
            int curr=size;
            //check with parent if u are at the right place
            while(parent_val(curr)>v[curr]){
                if(has_parent(curr)){
                    swap(parent_pos(curr),curr);
                    curr = parent_pos(curr);
                }
            } //swap with father
            
        }

        //pop a specific element from heap
        int pop(long long t){
            int pop_pos=-1;
            for(int i=1;i<=size;++i){
                if(v[i]==t){
                    pop_pos = i;
                    break;
                }
            }
            if(pop_pos==-1){
                return 0;
            }
            else{
                v[pop_pos]=v[size];
                size-=1;
                int curr=pop_pos;
                bool do_bottom=true;
                //insert last element from tree into pop position and go up checking, then go down
                while(parent_val(curr)>v[curr]){
                    if(has_parent(curr)){
                        swap(parent_pos(curr),curr);
                        curr = parent_pos(curr);
                        do_bottom=false;
                    }
                    else{break;}
                }
                if(do_bottom){
                    curr=pop_pos;
                    while(has_children(curr)){
                        switch(has_children(curr)){
                                //zero children
                            case(0):{return(1);}
                                //one child
                            case(1):{
                                if(v[curr]>v[curr*2]){
                                    swap(curr,curr*2);
                                    return(1);
                                }
                                else{return(1);}
                            }
                                //two children
                            case(2):{
                                if(v[curr]>min_val(v[curr*2],v[curr*2+1])){
                                    //swap with bigger child and update curr
                                    int swap_pos = min_at_pos(curr*2,curr*2+1);
                                    swap(curr,swap_pos);
                                    curr = swap_pos;
                                }
                                else{return(1);}
                            }
                        }
                    }
                }
                else{return(1);}
            }
                

            return(1);
        }

        //return the smallest element on heap
        long long min(void){
            if(size>=1){return(v[1]);}
            else{return(LLMIN);}
        }
};

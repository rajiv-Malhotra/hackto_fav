#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void par(vector<string> &res,int open,int index,int n,string temp){
        if(open<0)
            return;
        if(index==n){
            if(open==0)
                res.push_back(temp);
            return;
        }
        
        int remain = n-index-open;
        if(remain>0){
            par(res,open+1,index+1,n,temp+"(");
            par(res,open-1,index+1,n,temp+")");
        }
        else
            par(res,open-1,index+1,n,temp+")");
            
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        par(res,0,0,n*2,"");
        return res;
    }
};
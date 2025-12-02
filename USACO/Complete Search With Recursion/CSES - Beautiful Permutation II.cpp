#include<bits/stdc++.h>
using namespace std;



void solve(set<int> &st, vector<int> &v){
    if(st.empty()){
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
        
        exit(0);
    }
    
    for(int i : st){
        if(v.empty() || abs(i - v.back()) > 1){
            st.erase(i);
            v.push_back(i);
            solve(st, v);
            st.insert(i);
            v.pop_back(i);
        }
    }
}

int main(){
    int n; cin>>n;
    set<int> st;
    vector<int> v;
    
    for(int i = 1; i <= n; i++) st.insert(i);
    
    solve(st, v);
    
    cout<<"NO SOLUTION"<<endl;
    
    return 0;
}

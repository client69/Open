#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(queue<string> &s,string ip, string op){
    if(ip.length()==0){
        s.push(op);
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(s,ip,op1);
    solve(s,ip,op2);
}

int main(){
    string ip;
    cin>>ip;
    string op="";
    queue<string> s;
    solve(s,ip,op);
    while(!s.empty()){
        cout<<s.front()<<" ";
        s.pop();
    }
}

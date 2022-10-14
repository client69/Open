#include<bits/stdc++.h>
using namespace std;

int* getlps(string pattern)
{
    int l=pattern.length();
    int *lps=new int[l];
    lps[0]=0;
    int j=0;
    for(int i=1;i<l;){
        if(pattern[i]==pattern[j]){
            lps[i]=j+1;
            j++;
            i++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }

        }
    }
    return lps;
}
bool kmp(string s,string p)
{
    int l=s.length();
    int m=p.length();
    int i=0,j=0;
    int *lps=getlps(p);
    while(i<l && j<m){
        if(s[i]==p[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else
                i++;
        }
        if(j==m)
            return true;
    }
    return false;
}
int main()
{
    string s,p;
    cin>>s>>p;
    cout<<kmp(s,p);
    return 0;
}

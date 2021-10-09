#include<iostream>
#include<vector>
using namespace std;

//78
//[tv, tw, tx, uv, uw, ux]

string keyMap[10]={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

vector<string> getKpc(string str,int idx)
{
    int digit=str[idx]-'0';
    string storedStr=keyMap[digit];                 //storing keypad charactors
    
    if(idx==str.size())                             //returned vector of empty string at last
    {
        vector<string> temp;
		string empty="";
		
		temp.push_back(empty);
		
		return temp;
    }
    
    vector<string> ans=getKpc(str,idx+1);              //storing the previously genrated answer
    vector<string> newAns;
    
	int size=ans.size();
    
    for(int curr=0;curr<storedStr.size();curr++)    //for every keypad charactor
    {
        for(int ind=0;ind<size;ind++)               //for every char of previos answer
        {
            newAns.push_back(storedStr[curr]+ans[ind]);     //adding new charactor before every previous answer
        }
    }
    
    return newAns;
}

int main()                                          //Driver code
{
    string s;

    cin >> s;

    vector<string> ans = getKpc(s,0);
    int cnt = 0;

    cout << '[';

    for (string str : ans)
	{
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        
		else
            cout << str;
        
		cnt++;
    }
	
	return 0;
}
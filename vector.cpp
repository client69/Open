#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
	vector<int>v;
	for(int i=0;i<=1;i++)
		{v.push_back(i);}
	
	for(auto i=v.begin();i!=v.end();i++)
	{cout<<" "<<*i;}
cout<<"\n";
for(auto i=v.begin();i!=v.end();i++)
	{cout<<" "<<*i;}
cout<<endl;
vector<int>v2;
v2.push_back(2);
v2.push_back(3);
v.swap(v2);
for(auto i=v.begin();i!=v.end();i++)
	{cout<<" "<<*i;}
cout<<endl;
for(auto i=v2.begin();i!=v2.end();i++)
	{cout<<" "<<*i;}
	cout<<endl;
	int n=v.size();
	cout<<n;
	cout<<endl;
	for (auto ir = v.rbegin(); ir != v.rend(); ++ir) 
        cout << *ir << " "; 
   vector<int>::iterator ptr;
   ptr=v.begin();
return 0;
}

//complexity nlogk

#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long
#define M 1000000007

int Find_KthLargest(vector <int> vec, int k) {
	priority_queue <int, vector<int>> pq (vec.begin(),vec.begin()+k);
	for(int i=k;i<vec.size();i++) {
		if(vec[i]<pq.top()) {
			pq.pop();
			pq.push(vec[i]);
		}
	}
	return pq.top();
}

int main()
{
	vector<int> vec ={7,4,6,3,9,1};
	int k=3;
	cout<<Find_KthLargest(vec, k);
	return 0;
}


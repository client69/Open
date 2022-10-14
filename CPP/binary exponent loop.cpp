#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b)
{
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL
	         long int base, power = 1, inputpower;
	         cin >> base >> inputpower;
	         long long int ans = 1;



	         return 0;
}


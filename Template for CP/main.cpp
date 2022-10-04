#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pii pair<int, int>
#define piii pair<int, pi>
#define vii vector<pii>
#define viii vector<piii>
#define vvi vector<vector<int>>
#define endl "\n"
#define qq cout << " here ";
#define int long long
#define all(x) begin(x), end(x)
#define ff(n) for (int i = 0; i < n; i++)
#define fore(i, a, b) for (ll i = (a); i <= (b); i++)
#define pb(i) push_back(i)
#define ld long double
#define mp(i, j) make_pair(i, j)
#define vi vector<ll>
// ld pi=	3.14159265358979323846;
int mod = 1e9 + 7;
const int N = 1e6 + 5;
int INF = 0x3F3F3F3F;
 int LMAX= LLONG_MAX;

 int LMIN = LLONG_MIN;

void iter(vector<int> &v)
{
  for (auto i : v)
  {
    cout << i << " ";
  }
  cout << endl;
}
bool isPrime(int x)
{
  for (int i = 2; i <= sqrt(x); i++)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}
//Round off to nth precision
void print_precision(long double x, int y)
{
  x *= (pow(10, y));
  x = round(x);
  x /= pow(10, y);
  cout << fixed << setprecision(y) << x << endl;
}
int gcd(int l, int s)
{
  if (s == 0)
    return l;
  return gcd(s, l % s);
}
int fact(int n){
  if(n<2) return 1;
  return (n*fact(n-1))%mod;
}
int absl(int x, int y)
{
  if (x > y)
  {
    return x - y;
  }
  return y - x;
}

class DSU
{
public:
  vector<int> parent, rank, cnt;
  int cnt_comp; // total components
  DSU(int n)
  {
    parent.resize(n);
    rank.resize(n);
    cnt_comp = n;
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      rank[i] = 1;
    }
  }
  void join(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a == b)
      return;
    cnt_comp--;
    if (rank[a] >= rank[b])
    {
      parent[b] = a;
      rank[a] += rank[b];
    }
    else if (rank[a] < rank[b])
    {
      parent[a] = b;
      rank[b] += rank[a];
    }
  }
  int find(int a)
  {
    return a == parent[a] ? a : parent[a] = find(parent[a]);
  }
  bool check(int a, int b)
  {
    return find(a) == find(b);
  }
};

int power(int a, int p)
{
  if (p == 0)
  {
    return 1;
  }
  if (p == 1)
  {
    return a;
  }

  int res = power(a, p / 2);

  res = (res * res) % mod;

  if (p & 1)
  {
    res = (a * res) % mod;
  }

  return res;
}

void solve()
{
  int n,k;
  cin>>n>>k;
  unordered_map<int,int>m;
  vector<vector<int>>graph(n);
  ff(n-1){
    int u,v;
    cin>>u>>v;
    u--;
    v--;
    m[u]++;
    m[v]++;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  queue<int>q;
  for(auto &i:m){
    if(i.second==1){
      i.second--;
      q.push(i.first);
    }
  }
  while(k-- && q.size()){
    int sz=q.size();
    while(sz--){
      int f=q.front();
      q.pop();
      m.erase(f);
      for(auto &v:graph[f]){
        if(m.find(v)!=m.end())
        m[v]--;
        if(m.find(v)!=m.end() && m[v]==1){
          q.push(v);
        }
      }
    }
  }
  cout<<m.size()<<endl;
}


main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; 
  tc = 1;
 cin >> tc;
 while (tc--)
  {
    solve();
  }
}


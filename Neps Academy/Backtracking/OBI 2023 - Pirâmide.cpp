#include<bits/stdc++.h>
//#include<numbers>
//#include<chrono>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define DEBUG(x...)x
#define ww(x) DEBUG(cout<< #x " = " << x << "\n")
#define endl '\n'
#define vecin(name, len) vector<int> name(len); for (auto &x : name) cin >> x;
#define vecout(v) for (auto x : v) cout << x << " "; cout << endl;
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;

int top = 0;

bool balance(int mid, int bot, vi &v, int idx, int szmid, int szbot)
{
    if(idx == 6)
        if(top == mid && top == bot && szmid == 2 && szbot == 3)
            return 1;

    if(v[idx] == top)
        return balance(mid, bot, v, idx+1, szmid, szbot);

    if(mid > top || bot > top)
        return 0;

    bool res = 0;

    if(szmid < 2)
        res |= balance(mid+v[idx], bot, v, idx+1, szmid+1, szbot);
    if(szbot < 3)
        res |= balance(mid, bot+v[idx], v, idx+1, szmid, szbot+1);

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    vi v(6); 
  
  for(auto&x:v){
    cin>>x; 
    if(x > top) 
      top = x;
  }

    if(balance(0, 0, v, 0, 0, 0)) 
      cout<<'S'<<endl; 
    else 
      cout<<'N'<<endl;

    return 0;
}

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

//Princio da uniao Exclusao, consegui ver, mas nao implementar direito, so a parte da decisao

ll n, k;
vi v;
ll ans;

void solve(int idx, int tam, ll prod){
    
    if(prod > n) return;
    
    if(idx == k){
        
        if(tam > 0){
            if(tam%2 == 0)
                ans += n/prod;
            else
                ans -= n/prod;
        }
        
        return;
    }
    
    solve(idx+1, tam, prod);
    
    if(prod*v[idx] <= n)
        solve(idx+1, tam+1, prod*v[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin>>n>>k;

    v.resize(k); for(auto&x:v)cin>>x;
    
    ans = n;
    
    solve(0, 0, 1);
    
    cout<<n+ans<<endl;

    return 0;
}

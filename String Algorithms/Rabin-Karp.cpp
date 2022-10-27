//VC template
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

typedef long long int li;
typedef long double ld;
typedef unsigned long long uli;

#define PI 3.1415926535897932384626
#define endl '\n'
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define s second
#define f first


// declaration of ordered set //find_by_order // order_of_key // two main functions of ordered set
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


#ifdef vanshavenger
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif


typedef vector<li> vi;
typedef unordered_map<li,li> ump;
typedef unordered_map<char,li> sump;
typedef map<li,li> mp;
typedef pair<li,li> pl;
typedef vector<pl> vpl;
typedef pair<li,pair<li,li>> pll;



//*************************************************************************************
class TripletGCD{public:li x,y,gcd;};
TripletGCD extendedEuclid(li a, li b);
li moduloInverse(li a, li m);
li power(li a,li b, li c);
bool isPowerOfTwo(li x){return (x && !(x & (x - 1)));}

//*************************************************************************************


// li lengthOfLIS(vi& ans){ //not strictly increeasing
//     vi newAns;
//     for (li i = 0; i < ans.size(); i++){
//         if (newAns.empty() || newAns.back() < ans[i]){
//             newAns.push_back(ans[i]);
//         }
//         else{
//             li index = lower_bound(newAns.begin(), newAns.end(), ans[i]) - newAns.begin();
//             newAns[index] = ans[i];
//         }
//     }
//     return newAns.size();
// }
const li p = 31;

//-------------------------------------------------------------------------

void solve(){
    string pattern;
    string text;
    cin >> pattern >> text;
    li n = pattern.size();
    li m = text.size();
    li hPattern = 0;
    vector<li> p_pow(max(n,m));
    p_pow[0] = 1;
    for(li i = 1;i < p_pow.size();i++){
        p_pow[i] = (p_pow[i-1]*p)%MOD;
    }
    for(li i = 0;i < n;i++){
        hPattern = (hPattern + (pattern[i] - 'a' + 1)*p_pow[i])%MOD;
    }
    vector<li>TextHash(m+1,0);
    for(li i = 0;i < m;i++){
        TextHash[i+1] = (TextHash[i] + (text[i] - 'a' + 1)*p_pow[i])%MOD;
    }
    vector<li> total;
    for(li i = 0;i <= (m-n);i++){
        li currHash = (TextHash[i+n] + MOD - TextHash[i])%MOD;
        if(currHash == (hPattern*p_pow[i])%MOD){
           total.emplace_back(i); 
        } 
    }
    cout << total.size() << endl;
    
}

//-------------------------------------------------------------------------
signed main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    #ifndef ONLINE_JUDGE
	    freopen("Error.txt", "w", stderr);
    #endif
    auto start1 = high_resolution_clock::now();
    li t = 1;
    cin >> t;
    for(li ret = 1;ret <= t;ret++){
        // cout << "Case #" << ret << ": ";
        solve();
    }
    
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifdef vanshavenger
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}
//--------------------------------------------------------------------------
TripletGCD extendedEuclid(li a, li b){
    if(b == 0){
        TripletGCD ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
        
    }
    TripletGCD smallans = extendedEuclid(b,a%b);
    TripletGCD ans;
    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x - (a/b)*smallans.y;
    return ans;
}

li moduloInverse(li a, li m){
    TripletGCD ans = extendedEuclid(a,m);
    return ans.x;
}
li power(li a,li b, li c = MOD){
    li ans = 1;
    if(b == 0){
        return 1%c;
    }
    while(b){
        if(b&1){
            ans *= a;
            ans %= c;
        }
        a *= a;
        a %= c;
        b >>= 1;
    }
    return ans;
}

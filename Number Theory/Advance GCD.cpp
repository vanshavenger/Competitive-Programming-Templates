//VC template
#include <bits/stdc++.h>
typedef long long int li;
typedef long double ld;
#define PI 3.1415926535897932384626
#define endl '\n'
const li MOD = 1e9 + 7;
// __gcd(x,y) --> inbuilt

using namespace std;
typedef vector<li> vi;
typedef unordered_map<li,li> ump;
typedef unordered_map<char,li> sump;
typedef map<li,li> mp;

//-------------------------------------------------------------------------

void AdvanceGCD(li &a,string& b){
    
    li num = 0 ;
    for(li i = 0;i < b.size();i++){
        num = (num*10 + (li)(b[i] - '0'))%a;
    }
    cout << __gcd(a,num) << endl;
}

//-------------------------------------------------------------------------
signed main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    li t;
    cin >> t;
    while(t--){
        li a;
    	string b;
    	cin >> a >> b;
        AdvanceGCD(a,b);
    }
    return 0;
}

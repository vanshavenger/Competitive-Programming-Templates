#include <bits/stdc++.h>
using namespace std;

typedef long long int li;
#define endl '\n'
#define MOD 1000000007

li BExpo(li a,li b){
    if(b == 0) return 1;
    li answer = BExpo(a,b/2);
    answer %= MOD;
    li op = (answer*answer)%MOD;
    if(b%2 == 0) return op;
    op *= a;
    op %= MOD;
    return op;
}

li BEnoREC(li a,li b){
    li ans = 1;
    while(b > 0){
        if(b&1){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}

signed main(){
    li t = 1;
    // cin >> t;
    for(li ret = 1;ret <= t;ret++){
        // cout << "Case #" << ret << ": ";
        li a,b;
        cin >> a >> b;
        cout << BExpo(a,b) << endl;
        cout << BEnoREC(a,b) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long int li;
#define endl '\n'
#define MOD 1000000007

li gcREC(li a,li b){
    return b ? gcd(b,a%b) : a;
}
li gc(li a,li b){
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

signed main(){
    li t = 1;
    // cin >> t;
    for(li ret = 1;ret <= t;ret++){
        // cout << "Case #" << ret << ": ";
        li a,b;
        cin >> a >> b;
        // cout << __gcd(a,b) << endl; // inbuilt
        cout << gcREC(a,b) << endl;
        cout << gc(a,b) << endl;
    }
    return 0;
}

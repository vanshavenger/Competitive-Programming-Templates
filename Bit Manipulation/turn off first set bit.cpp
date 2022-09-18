#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    return n - (n&(-n));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n&(n-1) == 0){
            cout << 0 << endl;
            continue;
        }
        cout << solve(n) << endl;
    }
    return 0;
}

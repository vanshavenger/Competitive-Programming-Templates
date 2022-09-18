#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    return n&(-n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}

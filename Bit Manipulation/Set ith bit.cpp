#include <bits/stdc++.h>
using namespace std;

int solve(int n,int i){
    return ((1 << i) | n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n >> i;
        cout << solve(n,i) << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
	while(t--){
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }
        int x = 0;
        for(int i = 0;i < n;i++){
            x ^= arr[i];
        }
        cout << x << endl;
        delete [] arr;
    }
    return 0;
}

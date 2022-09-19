#include <bits/stdc++.h>
typedef long long int li;
using namespace std;

void bubbleSort(vector<li>& input, li size)
{
    for (li i = 0;i < size;i++) {
        for (li j = 0;j < size-1 -i;j++) {
            if (input[j] >= input[j+1]) {
                li temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
} 

signed main(){

	li t;
	cin >> t;

	while (t--)
	{
		li size;
		cin >> size;

		vector<li> input(size);

		for(li i = 0; i < size; ++i) cin >> input[i];

		bubbleSort(input, size);

		for (int i = 0; i < size; ++i) cout << input[i] << " ";
		
		cout << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,i=0;
	int arr[3];
	cin >> T;
	while(i<T-1){
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr+3);
		cout << "Case " << i+1 << ": " << arr[1] << endl;
		i++;
	}
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr+3);
	cout << "Case " << T << ": " << arr[1];
	return 0;
}
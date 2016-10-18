#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,m,n;
	bool b;
	cin >> t;
	for(int i=0 ; i<t ; ++i){
		cin >> m >> n;
		if(m == 1||m == 0) m = 2;
		int fin=sqrt(n);
		for(int j=m ; j<=n ;++j){
			b=true;
			for(int k=2 ; k<=fin ; ++k){
				if(j%k==0 and k!=j){
					k=m;
					b=false;
				}
			}
			if(b){
				cout << i << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
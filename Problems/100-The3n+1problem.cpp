#include <bits/stdc++.h>
using namespace std;

int main(){
	int i,j;
	while(cin >> i >> j){
		cout << i << " " << j << " ";
		if(i>j) swap(i, j);
		int best=0;
		for(int k=i ; k<=j ; k++){
			int cont=1;
			int n=k;
			while(n>1){
				if(n % 2 == 0) n/=2;
				else n= 3*n+1;
				cont++;
			}
			best = max(best, cont);
		}
		cout << best << endl;
	}
	return 0;
}
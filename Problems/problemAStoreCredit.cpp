#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int main(){
	int N,C,I,i=0,j=0,pos1,pos2,k,aux;
	cin >> N;
	while(j<N){
		cin >> C;
		cin >> I;
		vector<int> miVector;
		i=0;
		while(i<I){
			cin >> k;
			miVector.push_back(k);
			i++;
		}
		for(int n=0 ; n<miVector.size() ; n++){
			for(int m=0 ; m<miVector.size() ; m++){
				if(miVector[n]+miVector[m]==C && m!=n){
					pos1=n+1;
					pos2=m+1;
					m=miVector.size();
					n=miVector.size();
				}
			}
		}
		if(pos1>pos2){
			aux=pos1;
			pos1=pos2;
			pos2=aux;
		}
		cout << "Case #" << j+1 << ": " << pos1 << " " << pos2 << endl;
		j++;
	}
	return 0;
}
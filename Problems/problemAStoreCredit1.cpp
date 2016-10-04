#include <bits/stdc++.h>
using namespace std;

int const MAXN = 1010;

int limpiar(bool arr[], int size){
	for(int i=0 ; i<size ; i++){
		arr[i]=0;
	}
	return 0;
}
// Problema resuelto para el caso en que no se repitan costos.
int main(){
	bool seen[MAXN];
	bool pos[MAXN];
	pair<int,int> pareja; 
	int N,C,I,i=0,j=0,pos1,pos2,k,aux;
	cin >> N;
	while(j<N){
		cin >> C;
		cin >> I;
		pareja=make_pair(0,0);
		limpiar(seen, I);
		limpiar(pos, I);
		i=0;
		while(i<I){
			int costo;
			cin >> costo;
			pos[costo]=i+1;
			if(seen[C-costo]==1){
				pareja=make_pair(pos[costo],pos[C-costo]);
				i=I;
			}else{
				seen[costo]=1;
			}
			i++;
		}
		cout << "Case #" << j+1 << ": " << pareja.first << " " << pareja.second << endl;
		j++;
	}
}
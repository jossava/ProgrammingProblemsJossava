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
	int pos[MAXN];
	pair<int,int> pareja; 
	int N,C,I,i=0,j=0,pos1,pos2,k,aux;
	bool b;
	cin >> N;
	while(j<N){
		b=true;
		cin >> C;
		cin >> I;
		pareja=make_pair(0,0);
		for(int k=0 ; k<I ; k++){
			seen[k]=false;
			pos[k]=0;
		}
		i=0;
		while(i<I){
			int costo;
			cin >> costo;
			if(b){
				if(seen[C-costo]){
					pareja=make_pair(i+1,pos[C-costo]);
					b=false;
				}else{
					pos[costo]=i+1;
					seen[costo]=true;
				}
			}
			i++;
		}
		cout << "Case #" << j+1 << ": " << pareja.first << " " << pareja.second << endl;
		j++;
	}
}
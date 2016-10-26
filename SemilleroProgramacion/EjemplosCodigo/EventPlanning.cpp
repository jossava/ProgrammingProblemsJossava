#include <bits/stdc++.h>
using namespace std;
int const MAXA = 1010;
pair<int,int[MAXA]> hotels[18];

int main(){
	int N,B,H,W,p,a;
	bool beds;
	while(cin >> N >> B >> H >> W){
		// limpiar
		beds=false;
		for(int i=0; i<H; ++i){
			hotels[i].first=0;
			for(int j=0; j<W; ++j){
				hotels[i].second[j]=0;
			}
		}
		//llenar arreglo hotels
		for(int i=0; i<H ; ++i){
			cin >> p;
			hotels[i].first=p;
			for(int j=0; j<W; ++j){
				cin >> a;
				hotels[i].second[j]=a;
			}
			if((p*N)>B){
				hotels[i].first=11000;
			}
		}
		//descartar hoteles sin camas suficientes
		for(int i=0; i<H; ++i){
			if(hotels[i].first<11000){
				for(int j=0; j<W; ++j){
					if(hotels[i].second[j]>=N){
						beds=true;
						break;
					}
				}
				if(!beds) hotels[i].first=11000;
			}
		}
		//obviar hoteles descartados.
		int cont=0;
		for(int i=0; i<H; ++i){
			if(hotels[i].first==11000){
				cont++;
			}
		}
		if(cont==H){
			cout << "stay home" << endl;
		}else{
			int min=(200*10001);
			for(int i=0; i<H; ++i){
				if(hotels[i].first<11000){
					if(hotels[i].first*N < min){
						min=(hotels[i].first)*N;
					}
				}
			}
			cout << min << endl;
		}
	}
	return 0;
}
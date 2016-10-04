#include <iostream>
#include <vector>
#include <map>
using namespace std;

int tareaRepresentacionGrafos(int n, int m){
	// Representacion del grafo en matriz de adyacencia.
	int g [n][n];
	int u,v;
	//map<int, int> aristas [m]; así se utilizan los mapas.
	for(int k=0 ; k<m ; k++){
		cin >> u >> v;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(g[i][j]!=1){
					g[i][j]=0;
				}
			}
		}
		g[u][v]=1;
		g[v][u]=1;
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << g[i][j] << "  ";
		}
		cout << endl;
	}

	//representación del grafo en listas de adyacencia.
}

int main(){
	int n,m;
	cin >> n >> m;
	tareaRepresentacionGrafos(n,m);
	return 0;
}

int ejemploVectores(){
	vector <string> palabras; //(5) tamaño vector.
	for(int i=0 ; i<palabras.size() ; i++){ 
		cin >> palabras[i]; 
		cout << palabras[i] << endl;
	}
	vector<int> g [1000]; //Grafo de 1000 nodos, cada uno con un vector de enteros.
	return 0;
}
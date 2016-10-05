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
		g[u][v]=1;
		g[v][u]=1;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(g[i][j]!=1){
					g[i][j]=0;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << g[i][j] << "  ";
		}
		cout << endl;
	}

	//representación del grafo en listas de adyacencia.
	vector<int> g1 [n];
	for (int j = 0; j < n; ++j){
		g1[j].push_back(j);
	}
	for(int k=0 ; k<m ; k++){
		cin >> u >> v;
		g1[u].push_back(v);
		g1[v].push_back(u);
	}
	for (int i = 0; i < n; ++i){
		for (int l = 0; l < g1[i].size(); ++l){
			cout << g1[i].at(l) << " ";
		}
		cout << endl;
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	tareaRepresentacionGrafos(n,m);
	return 0;
}

int ejemploVectores(){
	vector <string> palabras (5); //(5) tamaño vector.
	for(int i=0 ; i<palabras.size() ; i++){ 
		cin >> palabras[i]; 
		cout << palabras[i] << endl;
	}
	vector<int> g [1000]; //Grafo de 1000 nodos, cada uno con un vector de enteros.
	return 0;
}

int comoUsarGetLine(){
	string line;
	while (getline(cin, line)){
		stringstream ss(line); // El stream ss se crea con line
		string word;
		int count = 0;
		while (ss >> word) count++;// ss se usa igual que cin
		cout << count << endl;
	}
	return 0;
}
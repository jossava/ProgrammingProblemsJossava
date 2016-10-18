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

int ejemploStack(){
	stack <int> s;
	s.push(10);
	s.push(-1);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.size() << endl;
	return 0;
}

int ejemploQueue(){
	queue <int> q;
	q.push(10);
	q.push(-1);
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << q.size() << endl;
	return 0;
}


vector <int> g[MAXN];		// La lista de adyacencia
int d[MAXN]; 				// Aristas usadas desde la fuente
void bfs(int s, int n){ 	// s = fuente, n = numero de nodos
	// Marcar todos los nodos como no visitados
	for (int i = 0; i < n; ++i) d[i] = -1;
	queue <int> q;
	q.push(s);				// Agregar la fuente a la cola
	d[s] = 0;				// La distancia de la fuente es 0
	while (q.size() > 0){
		int cur = q.front(); q.pop();
		for (int i = 0; i < g[cur].size(); ++i){
		int next = g[cur][i];
			if (d[next] == -1){				// Si todava no lo he visitado
				d[next] = d[cur] + 1; 		// La distancia que llevo + 1
				q.push(next);				// Agregarlo a la cola
			}
		}
	}
}
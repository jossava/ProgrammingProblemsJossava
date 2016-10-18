#include <bits/stdc++.h>
using namespace std;
// El maximo numero de dominos
const int MAXN = 100005;
// El grafo
vector <int> g[MAXN];
// El grafo reversado
vector <int> grev[MAXN];
// El "ordenamiento topologico" del grafo G
vector <int> topo_sort;
// La componente fuertemente conexa a la que pertenece cada nodo
int scc[MAXN];
// El arreglo de visitado para el primer DFS
bool seen[MAXN];
// El numero de aristas entrantes a cada componente
int in[MAXN];

// DFS donde se halla el ordenamiento topologico
void dfs1(int u){
	seen[u] = true;
	for (int i = 0; i < g[u].size(); ++i){
		int v = g[u][i];
		if (!seen[v]) dfs1(v);
	}
	topo_sort.push_back(u);
}
// DFS donde se hallan las componentes
void dfs2(int u, int comp){
	scc[u] = comp;
	for (int i = 0; i < grev[u].size(); ++i){
		int v = grev[u][i];
		if (scc[v] == -1) dfs2(v, comp);
	}
}

int main(){
	int cases; cin >> cases;
	while (cases--){
		int n, m;
		cin >> n >> m;
		// Limpiar las variables entre caso y caso
		for (int i = 0; i <= n; ++i){
			g[i].clear();
			grev[i].clear();
			topo_sort.clear();
			scc[i] = -1;
			seen[i] = false;
			in[i] = 0;
		}
		// Crear el grafo y el grafo reversado
		for (int i = 0; i < m; ++i){
			int u, v; cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
			grev[v].push_back(u);
		}
		// Llamar el primer dfs
		for (int i = 0; i < n; ++i){
			if (!seen[i]) dfs1(i);
		}
		reverse(topo_sort.begin(), topo_sort.end());
		// Llamar el segundo dfs
		int comp = 0;
		for (int i = 0; i < n; ++i){
			int u = topo_sort[i];
			if (scc[u] == -1) dfs2(u, comp++);
		}
		// Ver cuantas aristas entrantes tiene cada componente
		for (int u = 0; u < n; ++u){
			for (int i = 0; i < g[u].size(); ++i){
				int v = g[u][i];
				if (scc[u] != scc[v]) in[scc[v]]++;
			}
		}
		// Sumar las componentes que tienen 0 aristas entrantes
		int count = 0;
		for (int u = 0; u < comp; ++u){
			if (in[u] == 0) count++;
		}
		cout << count << endl;
	}
	return 0;
}
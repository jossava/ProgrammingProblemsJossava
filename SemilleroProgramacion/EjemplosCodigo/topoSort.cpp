#include <bits/stdc++.h>
using namespace std;

int const MAXN = 10005;
vector<int> g[MAXN];
bool seen[MAXN];
vector<int> topoSort;

void dfs(int u){
	seen[u]=true;
	for (int i = 0; i < g[u].size(); ++i){
		int v = g[u][i];
		if(!seen[v]) dfs(v);
	}
	topoSort.push_back(u);
}

int main(){
	int numNodos,relaciones,nodo1,nodo2;
	cin >> numNodos >> relaciones;
	while(relaciones--){
		cin >> nodo1 >> nodo2;
		g[nodo1].push_back(nodo2);
	}
	for (int i = 0; i < numNodos; ++i){
		if(!seen[i]) dfs(i);
	}
	reverse(topoSort.begin(), topoSort.end());
	for (int i = 0; i < topoSort.size(); ++i){
		cout << topoSort[i] << " ";
	}
	cout << endl;
	return 0;
}
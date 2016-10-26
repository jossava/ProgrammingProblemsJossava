#include <bits/stdc++.h>
using namespace std;

int const MAXN = 100010;
vector<int> g[MAXN];
bool seen [MAXN];
vector<int> topoSort;
int scc[MAXN];
vector<int> grev[MAXN];
int in[MAXN];

void dfs1(int u){
	seen[u] = true;
	for(int i=0; i<g[u].size(); ++i){
		int v=g[u][i];
		if(!seen[v]) dfs1(v);
	}
	topoSort.push_back(u);
}

void dfs2(int u, int comp){
	scc[u]=comp;
	for(int i=0; i<grev[u].size(); ++i){
		int v=grev[u][i];
		if(scc[v]==-1) dfs2(v,comp);
	}
}

int main(){
	int cases,n,m,x,y;
	cin >> cases;
	while(cases--){
		cin >> n >> m;
		for(int i=0; i<n; ++i){
			g[i].clear();
			grev[i].clear();
			topoSort.clear();
			seen[i]=false;
			scc[i]=-1;
			in[i]=0;
		}
		for(int i=0; i<m; ++i){
			cin >> x >> y;
			x--;y--;
			g[x].push_back(y);
			grev[y].push_back(x);
		}
		for(int i=0; i<n; ++i){
			if(!seen[i]) dfs1(i);
		}
		reverse(topoSort.begin(), topoSort.end());
		int comp=0;
		for(int i=0; i<n; ++i){
			int u=topoSort[i];
			if(scc[u]==-1) dfs2(u,comp++);
		}
		for(int u=0; u<n; ++u){
			for(int i=0; i<g[u].size(); ++i){
				int v=g[u][i];
				if(scc[u] != scc[v]) in[scc[v]]++;
			}
		}
		int cont=0;
		for(int i=0; i<comp; ++i){
			if(in[i]==0) cont++;
		}
		cout << cont << endl;
	}
	return 0;
}
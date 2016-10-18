#include <bits/stdc++.h>
using namespace std;

//const int MAXN = 10000;
//const int MAXM = 20000;

bool dfs(vector<int> g[],bool visitados[], int s, int n){
	for(int i=0 ; i<n ; ++i) visitados[i]=0;
	queue<int> q;
	int nNodes=0;
	memset(visitados,0,10000);
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		visitados[cur]=1;
		for(int i=0 ; i<g[cur].size() ; ++i){
			int next = g[cur][i];
			if(!visitados[next]){
				q.push(next);
			}else{
				return false;
			}
		}
		nNodes++;
	}
	if(nNodes!=n) return false;
	else return true;
}

int main(){
	int n,m;
	while(cin >> n >> m){
		vector <int> g[n+1];
		bool d[n]={0};
		for(int i=0 ; i<m ; ++i){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
		}
		if(dfs(g,d,1,n) and n==m+1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
} 

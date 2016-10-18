#include <bits/stdc++.h>
using namespace std;
#define MAXN 110

vector<int> g[MAXN], ans;
bool state[MAXN];

void limpiar(){
	for (int i = 0; i < MAXN; ++i){
		g[i].clear();
		state[i]=false;
	}
}

void dfs(int u){
	state[u]=true;
	for(int i=0; i<g[u].size(); ++i){
		int nextNode = g[u][i];
		if(!state[nextNode]) dfs(nextNode);
	}
	ans.push_back(u);
}

int sortTop(int n){
	for (int i = 0; i < n; ++i) state[i]=false;
	for (int i = 0; i < n; ++i){
		if(!state[i]) dfs(i);
	}
	reverse(ans.begin(),ans.end());
}

int main(){
	int n,m,x,y;
	cin >> n >> m;
	while(n!=0 || m!=0){
		limpiar();
		ans.clear();
		for (int i = 0; i < m; ++i){
			cin >> x >> y;
			g[x-1].push_back(y-1);
		}
		sortTop(n);
		cout << ans[0]+1;
		for (int i = 1; i < n; ++i) cout << " " << ans[i]+1;
		cout << endl;
		cin >> n >> m;
	}
	return 0;
}

